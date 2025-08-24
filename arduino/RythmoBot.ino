/*
 *=================================================================
 * == ALL-IN-ONE ESP32 CONTROLLER - WITH SOUND SENSOR CLAP DETECTION & LED STRIPS ==
 * == OPTIMIZED VERSION WITH ULTRA-FAST WEBSOCKET RESPONSE ==
 *=================================================================
 * -- All hardware (Servos, Motors, LCD, Buzzer, LED Strips) is controlled by the ESP32.
 * -- Implements a non-blocking state machine for fast, animated LCD updates.
 * -- MODIFICATION: Integrated 26-step coordinated leg movement sequence for "Falling for you"
 * -- BUZZER: Plays unique WiFi connection sound and dance step sounds
 * -- MOTOR CH15: Channel 15 motor continuous rotation (45°->0°->45°->0°) every 1 second
 * -- ULTRASONIC: Ultrasonic sensor stops base movement when obstacle detected (0-20cm)
 * -- SOUND SENSOR: Sound sensor clap detection triggers special robot movements
 * -- PWM SPEED: ENA and ENB pins for PWM speed control of 4-wheel base
 * -- NEW LED STRIPS: 2 LED strips on pin D2 with various synchronized patterns
 * -- NON-BLOCKING WIFI LED: Fixed WiFi reconnection issue with non-blocking LED pattern
 * -- ULTRA-FAST WEBSOCKET: Instant pause/stop response with global abort system
 * -- FIX: Reverted to blocking smoothMove for compatibility with dance files
 * -- FIX: Restored handleBaseMovement to resolve undefined reference error
 * -- Version: Complete with modular dance step files + Ultra-Fast WebSocket Response
 */

// -- LIBRARIES --
#include <WiFi.h>
#include <WebSocketsServer.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <LiquidCrystal_I2C.h>
#include <FastLED.h>

// Include dance choreography files
#include "fallingforyou.h" // "Falling for you" dance steps
#include "stereo.h"        // "stereo love" dance steps
#include "faded.h"         // "Faded" dance steps
#include "alone.h"         // "Alone" dance steps
#include "neural.h"        // "Mashup" dance steps
#include "other.h"         // "Other" dance steps

// -- WIFI CREDENTIALS --
const char* ssid = "Dialog 4G 128";
const char* password = "8A1c939D";

// -- HARDWARE INITIALIZATION --
WebSocketsServer webSocket(81);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);  // I2C address 0x40
LiquidCrystal_I2C lcd(0x27, 16, 2);                           // I2C address 0x27, 16x2 display

// -- LED STRIP CONFIGURATION --
#define LED_PIN 2         // D2 pin for LED strips
#define NUM_LEDS 60       // Total number of LEDs (adjust based on your strips)
#define LED_TYPE WS2812B  // Type of LED strip
#define COLOR_ORDER GRB   // Color order for your strips
#define BRIGHTNESS 100    // LED brightness (0-255)

CRGB leds[NUM_LEDS];  // LED array

// -- PIN DEFINITIONS --
// Motor Driver Pins (Base) - Updated with ENA and ENB
const int IN1 = 12;
const int IN2 = 14;
const int IN3 = 27;
const int IN4 = 26;
const int ENA = 13;  // PWM pin for Motor A (Left motors)
const int ENB = 25;  // PWM pin for Motor B (Right motors)
// Buzzer Pin
#define BUZZER_PIN 18
// Ultrasonic Sensor Pins
#define TRIG_PIN 33
#define ECHO_PIN 32
// Sound Sensor Pin
#define SOUND_SENSOR_PIN 34

// === REAL-TIME ABORT & LOOP HELPERS ===
volatile bool gAbortAll = false;          // set true on pause/stop; checked everywhere
bool gPaused = false;                     // current paused state

// -- WEBSOCKET OPTIMIZATION VARIABLES --
unsigned long lastKeepAlive = 0;
const unsigned long KEEP_ALIVE_INTERVAL = 1000; // Send heartbeat every 1 second
bool webSocketConnected = false;

// -- PWM SPEED CONTROL SETTINGS --
#define PWM_FREQ 1000     // PWM frequency (1kHz)
#define PWM_RESOLUTION 8  // 8-bit resolution (0-255)

// -- SPEED SETTINGS --
int baseSpeed = 150;    // Default base speed (0-255)
int danceSpeed = 140;   // Speed during dancing (slower)
int normalSpeed = 140;  // Speed during normal movement
int slowSpeed = 80;     // Slow speed for precise movements

// --- SERVO CHANNEL DEFINITIONS ---
// Leg 1 (Left)
const int LEG1_HIP_CHANNEL = 6;
const int LEG1_KNEE_CHANNEL = 7;
const int LEG1_ANKLE_CHANNEL = 8;
// Leg 2 (Right)
const int LEG2_HIP_CHANNEL = 9;
const int LEG2_KNEE_CHANNEL = 10;
const int LEG2_ANKLE_CHANNEL = 11;
// Continuous Rotation Motor
#define MOTOR_CH15 15

// -- SERVO --
// Home positions for all 12 servos. Arms have specific homes, legs home to 0.
int servoHome[12] = {
  90, 45, 135, 90, 60, 120,  // Arms (Ch 0-5)
  0, 0, 0, 0, 0, 0           // Legs (Ch 6-11) home position is 0 degrees
};
// Array to track the current angle of each servo
int currentServoAngles[12] = {
  90, 45, 135, 90, 60, 120,
  0, 0, 0, 0, 0, 0
};

// -- ROBOT STATE VARIABLES --
bool isDancing = false;
bool obstacleDetected = false;
String currentSong = "No song";

// -- LCD STATE MACHINE VARIABLES --
enum LcdState { INIT, PLAYING, PAUSED, STOPPED };
LcdState lcdState = STOPPED;
unsigned long lastAnimationTime = 0;
unsigned long lastLcdUpdate = 0; // For optimized LCD updates
int dotCount = 0;

// -- BASE MOVEMENT CONTROL VARIABLES --
unsigned long lastBaseMovement = 0;
unsigned long baseMovementInterval = 2000;
bool isMovingForward = true;
const unsigned long FORWARD_CYCLES = 5;
const unsigned long BACKWARD_CYCLES = 5;
unsigned long currentCycleCount = 0;

// -- CHANNEL 15 MOTOR CONTROL VARIABLES --
unsigned long lastMotorMovement = 0;
unsigned long motorMovementInterval = 1000;  // 1 second
int motorCurrentAngle = 45;
bool motorMovingToZero = true;

// -- ULTRASONIC SENSOR VARIABLES --
unsigned long lastUltrasonicCheck = 0;
unsigned long ultrasonicCheckInterval = 100;  // Check every 100ms

// -- SOUND SENSOR VARIABLES --
bool soundPreviouslyHigh = true;  // Tracks state to detect edge
unsigned long lastClapTime = 0;
unsigned long clapDebounceDelay = 500;  // Prevent multiple clap detections within 500ms
bool clapMovementInProgress = false;

// -- LED STRIP VARIABLES --
enum LedPattern {
  LED_OFF,
  LED_RAINBOW,
  LED_PULSE,
  LED_CHASE,
  LED_STROBE,
  LED_FIRE,
  LED_DANCE,
  LED_CLAP_RESPONSE,
  LED_OBSTACLE_WARNING,
  LED_STARTUP,
  LED_WIFI_SUCCESS,
  LED_BREATHING,
  LED_WAVE
};

// Add these global variables to better control clap response
bool clapLedPatternActive = false;
unsigned long clapPatternStartTime = 0;
LedPattern currentLedPattern = LED_OFF;

unsigned long lastLedUpdate = 0;
unsigned long ledUpdateInterval = 50;  // 50ms for smooth animations
int ledAnimationStep = 0;
uint8_t ledHue = 0;
uint8_t ledBrightness = BRIGHTNESS;
bool ledDirection = true;

// -- NON-BLOCKING WIFI LED PATTERN VARIABLES --
bool wifiPatternCompleted = false;
unsigned long wifiPatternStartTime = 0;
const unsigned long WIFI_PATTERN_TIMEOUT = 15000;  // 15 seconds timeout

// -- NEW STATE MACHINE VARIABLES FOR NON-BLOCKING MOVEMENTS --
enum ClapState {
  CLAP_IDLE,
  CLAP_INIT,
  CLAP_MOVE_SET1,
  CLAP_MOVE_SET2,
  CLAP_MOVE_SET3,
  CLAP_MOVE_SET4,
  CLAP_FINAL_POSE,
  CLAP_RESET
};
ClapState clapState = CLAP_IDLE;
unsigned long clapStepStartTime = 0;
int clapCurrentStep = 0;

enum DanceState {
  DANCE_IDLE,
  DANCE_EXECUTING_STEP,
  DANCE_RESETTING
};
DanceState danceState = DANCE_IDLE;
unsigned long danceStepStartTime = 0;
int currentDanceStep = 0;

// -- BUZZER STATE --
struct BuzzerTone {
  int frequency;
  unsigned long duration;
  unsigned long startTime;
  bool active;
};
BuzzerTone currentTone = {0, 0, 0, false};

// === FUNCTION DECLARATIONS ===
void smoothMove(uint8_t channel, int toAngle, int delayMs);
void pwmWriteAngle(uint8_t ch, float angle);
void resetAllServos();
void updateLcdScreenFast();
void playClapResponseSound();
void playErrorSound();
void setMotorSpeed(int speed);
void setupPWMChannels();
void moveForward(int duration);
void moveBackward(int duration);
void stopBase();
void playStepSound(int stepNumber);
void handleWifiLedPatternCompletion();
void optimizeWiFi();
void updateLEDs();
void setLedPattern(LedPattern pattern);
void clearAllLEDs();
void ledRainbow();
void ledPulse();
void ledChase();
void ledStrobe();
void ledFire();
void ledDance();
void ledClapResponse();
void ledObstacleWarning();
void ledStartup();
void ledWifiSuccess();
void ledBreathing();
void ledWave();
void executeClapResponseStep();
void executeDanceStep();
void playTone(int frequency, int duration);
void updateBuzzer();
void handleBaseMovement();

// === ULTRA-FAST RESPONSE FUNCTIONS ===

// Check if we should abort current operations
inline bool shouldAbort() {
  webSocket.loop(); // CRITICAL: Process incoming messages immediately
  return gAbortAll;
}

// Hard stop everything NOW (called on pause/stop)
void pauseImmediate() {
  gAbortAll = true;
  gPaused = true;

  stopBase();
  noTone(BUZZER_PIN);
  currentTone.active = false;
  setMotorSpeed(0);
  setLedPattern(LED_BREATHING);
  lcdState = PAUSED;
  isDancing = false;
  clapState = CLAP_IDLE;
  danceState = DANCE_IDLE;
  clapMovementInProgress = false;

  updateLcdScreenFast();

  // Flush a few websocket cycles to immediately ack to the client
  for (int i = 0; i < 3; i++) { webSocket.loop(); yield(); }
}

// Full stop + reset (used by "stop")
void stopImmediate() {
  gAbortAll = true;
  gPaused = false;
  isDancing = false;
  currentSong = "No song";
  clapState = CLAP_IDLE;
  danceState = DANCE_IDLE;
  clapMovementInProgress = false;

  stopBase();
  noTone(BUZZER_PIN);
  currentTone.active = false;
  setMotorSpeed(0);
  setLedPattern(LED_BREATHING);
  lcdState = STOPPED;

  // Start resetting servos to home
  resetAllServos();

  for (int i = 0; i < 3; i++) { webSocket.loop(); yield(); }
}

// Resume clears the abort and restores speed/pattern
void resumeFromPause() {
  gAbortAll = false;
  gPaused = false;
  clapState = CLAP_IDLE;
  danceState = DANCE_IDLE;
  clapMovementInProgress = false;

  if (currentSong != "No song" && currentSong != "") {
    isDancing = true;
    setMotorSpeed(danceSpeed);
    setLedPattern(LED_DANCE);
    lcdState = PLAYING;
  } else {
    setMotorSpeed(normalSpeed);
    setLedPattern(LED_BREATHING);
    lcdState = STOPPED;
  }
  updateLcdScreenFast();
}

// === WIFI OPTIMIZATION FUNCTION ===
void optimizeWiFi() {
  WiFi.setSleep(false);
  WiFi.setAutoReconnect(true);
  Serial.println("WiFi optimizations applied - Sleep disabled, Auto-reconnect enabled");
}

// === LED STRIP FUNCTIONS ===
void setupLEDs() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();

  Serial.println("LED strips initialized on pin D2");
  Serial.print("Number of LEDs: ");
  Serial.println(NUM_LEDS);

  setLedPattern(LED_STARTUP);
}

void updateLEDs() {
  if (millis() - lastLedUpdate >= ledUpdateInterval) {
    switch (currentLedPattern) {
      case LED_OFF:
        clearAllLEDs();
        break;
      case LED_RAINBOW:
        ledRainbow();
        break;
      case LED_PULSE:
        ledPulse();
        break;
      case LED_CHASE:
        ledChase();
        break;
      case LED_STROBE:
        ledStrobe();
        break;
      case LED_FIRE:
        ledFire();
        break;
      case LED_DANCE:
        ledDance();
        break;
      case LED_CLAP_RESPONSE:
        ledClapResponse();
        break;
      case LED_OBSTACLE_WARNING:
        ledObstacleWarning();
        break;
      case LED_STARTUP:
        ledStartup();
        break;
      case LED_WIFI_SUCCESS:
        ledWifiSuccess();
        break;
      case LED_BREATHING:
        ledBreathing();
        break;
      case LED_WAVE:
        ledWave();
        break;
    }

    FastLED.show();
    lastLedUpdate = millis();
    ledAnimationStep++;
    if (ledAnimationStep > 1000) {
      ledAnimationStep = ledAnimationStep % 200;
    }
  }
}

void setLedPattern(LedPattern pattern) {
  if (clapLedPatternActive && pattern != LED_CLAP_RESPONSE) {
    Serial.println("WARNING: Attempted to change LED pattern during clap response - ignoring");
    return;
  }

  if (currentLedPattern == pattern) {
    Serial.println("LED pattern already set to requested pattern - skipping");
    return;
  }

  currentLedPattern = pattern;
  ledAnimationStep = 0;
  ledHue = 0;
  ledDirection = true;

  if (pattern != LED_WIFI_SUCCESS && pattern != LED_CLAP_RESPONSE) {
    FastLED.clear();
    FastLED.show();
  }

  switch (pattern) {
    case LED_STROBE:
      ledUpdateInterval = 100;
      break;
    case LED_CHASE:
      ledUpdateInterval = 80;
      break;
    case LED_FIRE:
      ledUpdateInterval = 30;
      break;
    case LED_DANCE:
      ledUpdateInterval = 60;
      break;
    case LED_CLAP_RESPONSE:
      ledUpdateInterval = 30;
      break;
    case LED_OBSTACLE_WARNING:
      ledUpdateInterval = 200;
      break;
    case LED_WIFI_SUCCESS:
      ledUpdateInterval = 100;
      break;
    case LED_BREATHING:
      ledUpdateInterval = 50;
      break;
    default:
      ledUpdateInterval = 50;
      break;
  }

  Serial.print("LED pattern changed to: ");
  Serial.println(pattern);
}

void clearAllLEDs() {
  FastLED.clear();
}

void ledRainbow() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV((ledHue + (i * 255 / NUM_LEDS)) % 255, 255, ledBrightness);
  }
  ledHue += 2;
}

void ledPulse() {
  uint8_t brightness = beatsin8(30, 0, 255);
  fill_solid(leds, NUM_LEDS, CHSV(ledHue, 255, brightness));
  ledHue += 1;
}

void ledChase() {
  fadeToBlackBy(leds, NUM_LEDS, 64);
  int pos = ledAnimationStep % NUM_LEDS;
  leds[pos] = CHSV(ledHue, 255, 255);
  leds[(pos + 1) % NUM_LEDS] = CHSV(ledHue + 30, 255, 180);
  leds[(pos + 2) % NUM_LEDS] = CHSV(ledHue + 60, 255, 100);
  ledHue += 2;
}

void ledStrobe() {
  if (ledAnimationStep % 2 == 0) {
    fill_solid(leds, NUM_LEDS, CRGB::White);
  } else {
    FastLED.clear();
  }
}

void ledFire() {
  for (int i = 0; i < NUM_LEDS; i++) {
    int heat = random(0, 255);
    if (heat < 80) {
      leds[i] = CRGB::Black;
    } else if (heat < 160) {
      leds[i] = CRGB::Red;
    } else if (heat < 220) {
      leds[i] = CRGB::Orange;
    } else {
      leds[i] = CRGB::Yellow;
    }
  }
}

void ledDance() {
  fadeToBlackBy(leds, NUM_LEDS, 32);
  int pos1 = beatsin16(30, 0, NUM_LEDS - 1);
  int pos2 = beatsin16(45, 0, NUM_LEDS - 1);
  int pos3 = beatsin16(60, 0, NUM_LEDS - 1);
  leds[pos1] += CHSV(0, 255, 255);
  leds[pos2] += CHSV(96, 255, 255);
  leds[pos3] += CHSV(160, 255, 255);
}

void ledClapResponse() {
  unsigned long elapsed = millis() - clapPatternStartTime;
  if (elapsed < 500) {
    int center = NUM_LEDS / 2;
    int maxRadius = NUM_LEDS / 2;
    int radius = map(elapsed, 0, 500, 0, maxRadius);
    FastLED.clear();
    for (int i = max(0, center - radius); i <= min(NUM_LEDS - 1, center + radius); i++) {
      uint8_t brightness = 255 - (abs(i - center) * 255 / maxRadius);
      brightness = max(brightness, (uint8_t)50);
      leds[i] = CHSV((elapsed / 10) % 255, 255, brightness);
    }
  } else if (elapsed < 1500) {
    fadeToBlackBy(leds, NUM_LEDS, 40);
    int numSparkles = 8;
    for (int i = 0; i < numSparkles; i++) {
      int pos = random(NUM_LEDS);
      leds[pos] = CHSV(random(255), 255, 255);
    }
  } else if (elapsed < 2200) {
    if ((elapsed / 100) % 2 == 0) {
      fill_solid(leds, NUM_LEDS, CRGB::Red);
    } else {
      fill_solid(leds, NUM_LEDS, CRGB::Blue);
    }
  } else if (elapsed < 3000) {
    uint8_t brightness = beatsin8(30, 100, 255);
    fill_solid(leds, NUM_LEDS, CHSV(96, 255, brightness));
  } else {
    clapLedPatternActive = false;
    if (isDancing) {
      setLedPattern(LED_DANCE);
    } else {
      setLedPattern(LED_BREATHING);
    }
    Serial.println("Clap LED pattern finished, restored normal pattern");
  }
}

void ledObstacleWarning() {
  if (ledAnimationStep % 2 == 0) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
  } else {
    FastLED.clear();
  }
}

void ledStartup() {
  if (ledAnimationStep < NUM_LEDS) {
    leds[ledAnimationStep] = CHSV(ledHue, 255, 255);
    ledHue += 256 / NUM_LEDS;
  } else if (ledAnimationStep < NUM_LEDS + 30) {
    // Hold full pattern
  } else {
    setLedPattern(LED_BREATHING);
  }
}

void ledWifiSuccess() {
  if (ledAnimationStep < 30) {
    int fillCount = map(ledAnimationStep, 0, 29, 0, NUM_LEDS);
    FastLED.clear();
    for (int i = 0; i < fillCount; i++) {
      leds[i] = CRGB::Green;
    }
  } else if (ledAnimationStep < 60) {
    FastLED.clear();
    for (int i = 0; i < NUM_LEDS; i++) {
      uint8_t brightness = sin8(((i * 256 / NUM_LEDS) + ((ledAnimationStep - 30) * 8)) % 256);
      leds[i] = CRGB(0, brightness, 0);
    }
  } else if (ledAnimationStep < 90) {
    fill_solid(leds, NUM_LEDS, CRGB::Green);
  } else if (ledAnimationStep < 120) {
    uint8_t brightness = beatsin8(20, 100, 255);
    fill_solid(leds, NUM_LEDS, CRGB(0, brightness, 0));
  } else if (ledAnimationStep < 150) {
    if ((ledAnimationStep / 3) % 2 == 0) {
      fill_solid(leds, NUM_LEDS, CRGB::Green);
    } else {
      fill_solid(leds, NUM_LEDS, CRGB::White);
    }
  } else {
    uint8_t brightness = beatsin8(10, 150, 255);
    fill_solid(leds, NUM_LEDS, CRGB(0, brightness, 0));
  }
}

void ledBreathing() {
  uint8_t brightness = beatsin8(15, 30, 200);
  fill_solid(leds, NUM_LEDS, CHSV(160, 200, brightness));
}

void ledWave() {
  for (int i = 0; i < NUM_LEDS; i++) {
    uint8_t brightness = sin8(((i * 256 / NUM_LEDS) + (ledAnimationStep * 4)) % 256);
    leds[i] = CHSV((ledHue + (i * 2)) % 255, 255, brightness);
  }
  ledHue += 1;
}

void handleWifiLedPatternCompletion() {
  if (!wifiPatternCompleted) {
    unsigned long elapsedTime = millis() - wifiPatternStartTime;
    if (currentLedPattern == LED_WIFI_SUCCESS && ledAnimationStep >= 150) {
      wifiPatternCompleted = true;
      setLedPattern(LED_BREATHING);
      Serial.println("WiFi LED pattern completed naturally, switched to breathing");
    } else if (elapsedTime >= WIFI_PATTERN_TIMEOUT) {
      wifiPatternCompleted = true;
      setLedPattern(LED_BREATHING);
      Serial.println("WiFi LED pattern timed out, switched to breathing");
    }
  }
}

// === PWM SPEED CONTROL FUNCTIONS ===
void setupPWMChannels() {
  ledcAttach(ENA, PWM_FREQ, PWM_RESOLUTION);
  ledcAttach(ENB, PWM_FREQ, PWM_RESOLUTION);
  setMotorSpeed(baseSpeed);
  Serial.println("PWM channels configured for motor speed control");
}

void setMotorSpeed(int speed) {
  speed = constrain(speed, 0, 255);
  ledcWrite(ENA, speed);
  ledcWrite(ENB, speed);
  baseSpeed = speed;
  Serial.print("Motor speed set to: ");
  Serial.println(speed);
}

void changeSpeedGradually(int targetSpeed, int stepSize = 5, unsigned long stepMs = 30) {
  static int currentSpeed = baseSpeed;
  static unsigned long lastSpeedUpdate = 0;
  static bool speedChanging = false;

  if (!speedChanging) {
    currentSpeed = baseSpeed;
    targetSpeed = constrain(targetSpeed, 0, 255);
    if (currentSpeed == targetSpeed) return;
    speedChanging = true;
  }

  if (shouldAbort()) {
    speedChanging = false;
    return;
  }

  if (millis() - lastSpeedUpdate >= stepMs) {
    int dir = (targetSpeed > currentSpeed) ? 1 : -1;
    currentSpeed += dir * stepSize;
    if ((dir > 0 && currentSpeed >= targetSpeed) || (dir < 0 && currentSpeed <= targetSpeed)) {
      currentSpeed = targetSpeed;
      speedChanging = false;
    }
    setMotorSpeed(currentSpeed);
    lastSpeedUpdate = millis();
  }
}

// === SOUND SENSOR FUNCTIONS ===
void checkForClap() {
  if (gPaused || clapMovementInProgress) return;

  int soundNow = digitalRead(SOUND_SENSOR_PIN);
  if (soundPreviouslyHigh && soundNow == LOW) {
    if (millis() - lastClapTime > clapDebounceDelay) {
      Serial.println("🎉 Clap detected! Starting clap response...");
      lastClapTime = millis();
      clapMovementInProgress = true;
      clapLedPatternActive = true;
      clapPatternStartTime = millis();
      clapState = CLAP_INIT;
      setLedPattern(LED_CLAP_RESPONSE);
      updateLcdScreenFast();
    }
  }
  soundPreviouslyHigh = (soundNow == HIGH);
}

void executeClapResponseStep() {
  if (shouldAbort() || !clapMovementInProgress) {
    clapState = CLAP_IDLE;
    clapMovementInProgress = false;
    return;
  }

  if (millis() - clapStepStartTime < 10) return; // Small delay for smooth updates

  switch (clapState) {
    case CLAP_INIT:
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Clap Detected!");
      lcd.setCursor(0, 1);
      lcd.print("Dancing...");
      setMotorSpeed(slowSpeed);
      playClapResponseSound();
      clapState = CLAP_MOVE_SET1;
      clapStepStartTime = millis();
      break;

    case CLAP_MOVE_SET1:
      if (clapCurrentStep == 0) {
        smoothMove(0, 30, 10);
        smoothMove(3, 150, 10);
        smoothMove(1, 10, 10);
        smoothMove(4, 170, 10);
        clapCurrentStep = 1;
        clapStepStartTime = millis();
      } else if (millis() - clapStepStartTime >= 300) {
        clapCurrentStep = 0;
        clapState = CLAP_MOVE_SET2;
        clapStepStartTime = millis();
      }
      break;

    case CLAP_MOVE_SET2:
      if (clapCurrentStep == 0) {
        pwmWriteAngle(LEG1_HIP_CHANNEL, 15);
        pwmWriteAngle(LEG2_HIP_CHANNEL, 15);
        pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
        pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
        pwmWriteAngle(LEG1_ANKLE_CHANNEL, 10);
        pwmWriteAngle(LEG2_ANKLE_CHANNEL, 10);
        clapCurrentStep = 1;
        clapStepStartTime = millis();
      } else if (millis() - clapStepStartTime >= 400) {
        clapCurrentStep = 0;
        clapState = CLAP_MOVE_SET3;
        clapStepStartTime = millis();
      }
      break;

    case CLAP_MOVE_SET3:
      if (clapCurrentStep == 0) {
        smoothMove(0, 135, 10);
        smoothMove(3, 45, 10);
        smoothMove(2, 90, 10);
        smoothMove(5, 90, 10);
        clapCurrentStep = 1;
        clapStepStartTime = millis();
      } else if (millis() - clapStepStartTime >= 300) {
        clapCurrentStep = 0;
        clapState = CLAP_MOVE_SET4;
        clapStepStartTime = millis();
      }
      break;

    case CLAP_MOVE_SET4:
      if (clapCurrentStep == 0) {
        pwmWriteAngle(LEG1_HIP_CHANNEL, 25);
        pwmWriteAngle(LEG2_HIP_CHANNEL, 5);
        pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
        pwmWriteAngle(LEG2_KNEE_CHANNEL, 15);
        clapCurrentStep = 1;
        clapStepStartTime = millis();
      } else if (millis() - clapStepStartTime >= 300) {
        clapCurrentStep = 0;
        clapState = CLAP_FINAL_POSE;
        clapStepStartTime = millis();
      }
      break;

    case CLAP_FINAL_POSE:
      if (clapCurrentStep == 0) {
        smoothMove(0, 45, 10);
        smoothMove(3, 135, 10);
        smoothMove(2, 45, 10);
        smoothMove(5, 135, 10);
        clapCurrentStep = 1;
        clapStepStartTime = millis();
      } else if (millis() - clapStepStartTime >= 500) {
        clapCurrentStep = 0;
        clapState = CLAP_RESET;
        clapStepStartTime = millis();
      }
      break;

    case CLAP_RESET:
      resetAllServos();
      if (millis() - clapStepStartTime >= 200) {
        setMotorSpeed(isDancing ? danceSpeed : normalSpeed);
        clapMovementInProgress = false;
        clapState = CLAP_IDLE;
        updateLcdScreenFast();
        Serial.println("Clap response sequence complete!");
      }
      break;

    default:
      clapState = CLAP_IDLE;
      clapMovementInProgress = false;
      break;
  }
}

// === ULTRASONIC SENSOR FUNCTIONS ===
float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  float distance = (duration * 0.034) / 2;
  if (duration == 0) return -1;
  return distance;
}

void checkForObstacles() {
  if (millis() - lastUltrasonicCheck >= ultrasonicCheckInterval) {
    float distance = measureDistance();
    if (distance > 0 && distance <= 50.0) {
      if (!obstacleDetected) {
        obstacleDetected = true;
        setLedPattern(LED_OBSTACLE_WARNING);
        playErrorSound();
      }
    } else {
      if (obstacleDetected) {
        obstacleDetected = false;
        if (isDancing) {
          setLedPattern(LED_DANCE);
        } else {
          setLedPattern(LED_BREATHING);
        }
      }
    }
    lastUltrasonicCheck = millis();
  }
}

// === CHANNEL 15 MOTOR CONTROL FUNCTIONS ===
void handleMotorCH15() {
  if (obstacleDetected || clapMovementInProgress || shouldAbort()) {
    if (obstacleDetected) Serial.println("Head motor paused due to obstacle detection");
    return;
  }

  if (millis() - lastMotorMovement >= motorMovementInterval) {
    if (motorMovingToZero) {
      if (motorCurrentAngle > 0) {
        motorCurrentAngle -= 5;
        if (motorCurrentAngle < 0) motorCurrentAngle = 0;
        pwmWriteAngle(MOTOR_CH15, motorCurrentAngle);
        Serial.print("Motor CH15 angle: ");
        Serial.println(motorCurrentAngle);
      } else {
        motorMovingToZero = false;
      }
    } else {
      if (motorCurrentAngle < 90) {
        motorCurrentAngle += 5;
        if (motorCurrentAngle > 90) motorCurrentAngle = 90;
        pwmWriteAngle(MOTOR_CH15, motorCurrentAngle);
        Serial.print("Motor CH15 angle: ");
        Serial.println(motorCurrentAngle);
      } else {
        motorMovingToZero = true;
      }
    }
    lastMotorMovement = millis();
  }
}

// === BUZZER CONTROL FUNCTIONS ===
void playTone(int frequency, int duration) {
  if (shouldAbort()) return;
  if (currentTone.active) {
    noTone(BUZZER_PIN);
    currentTone.active = false;
  }
  if (frequency > 0) {
    tone(BUZZER_PIN, frequency);
    currentTone = {frequency, duration, millis(), true};
  }
}

void updateBuzzer() {
  if (currentTone.active && millis() - currentTone.startTime >= currentTone.duration) {
    noTone(BUZZER_PIN);
    currentTone.active = false;
  }
}

void playClapResponseSound() {
  static int clapSoundStep = 0;
  static unsigned long lastSoundTime = 0;
  const int tones[] = {523, 659, 784, 1047, 988, 880, 784, 1047, 1319};
  const int durations[] = {100, 100, 100, 150, 80, 80, 120, 200, 250};
  const int delays[] = {0, 0, 0, 50, 0, 0, 100, 0, 0};

  if (shouldAbort()) {
    clapSoundStep = 0;
    return;
  }

  if (clapSoundStep < 9 && millis() - lastSoundTime >= (clapSoundStep > 0 ? delays[clapSoundStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[clapSoundStep], durations[clapSoundStep]);
      clapSoundStep++;
      lastSoundTime = millis();
    }
  } else if (clapSoundStep >= 9) {
    clapSoundStep = 0;
  }
}

void playWifiConnectedSound() {
  static int wifiSoundStep = 0;
  static unsigned long lastSoundTime = 0;
  const int tones[] = {523, 659, 784, 1047, 1047, 1175, 1319, 1397, 1568, 1047, 1319, 1568};
  const int durations[] = {150, 150, 150, 200, 100, 100, 100, 100, 300, 100, 100, 400};
  const int delays[] = {0, 0, 0, 100, 0, 0, 0, 0, 200, 50, 50, 0};

  if (shouldAbort()) {
    wifiSoundStep = 0;
    return;
  }

  if (wifiSoundStep < 12 && millis() - lastSoundTime >= (wifiSoundStep > 0 ? delays[wifiSoundStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[wifiSoundStep], durations[wifiSoundStep]);
      wifiSoundStep++;
      lastSoundTime = millis();
    }
  } else if (wifiSoundStep >= 12) {
    wifiSoundStep = 0;
    Serial.println("WiFi connection sound complete!");
  }
}

void playStartupSound() {
  static int startupSoundStep = 0;
  static unsigned long lastSoundTime = 0;
  const int tones[] = {440, 523, 659, 784};
  const int durations[] = {200, 200, 200, 300};

  if (shouldAbort()) {
    startupSoundStep = 0;
    return;
  }

  if (startupSoundStep < 4 && millis() - lastSoundTime >= (startupSoundStep > 0 ? durations[startupSoundStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[startupSoundStep], durations[startupSoundStep]);
      startupSoundStep++;
      lastSoundTime = millis();
    }
  } else if (startupSoundStep >= 4) {
    startupSoundStep = 0;
  }
}

void playDanceSound() {
  static int danceSoundStep = 0;
  static unsigned long lastSoundTime = 0;
  const int tones[] = {659, 784, 988, 1047};
  const int durations[] = {150, 150, 150, 200};

  if (shouldAbort()) {
    danceSoundStep = 0;
    return;
  }

  if (danceSoundStep < 4 && millis() - lastSoundTime >= (danceSoundStep > 0 ? durations[danceSoundStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[danceSoundStep], durations[danceSoundStep]);
      danceSoundStep++;
      lastSoundTime = millis();
    }
  } else if (danceSoundStep >= 4) {
    danceSoundStep = 0;
  }
}

void playStepSound(int stepNumber) {
  if (shouldAbort()) return;
  int frequencies[] = {
    262, 294, 330, 349, 392, 440, 494, 523, 587, 659,
    698, 784, 831, 880, 932, 988, 1047, 1175, 1319, 1397,
    1568, 1661, 1760, 1865, 1976, 2093
  };
  if (stepNumber >= 1 && stepNumber <= 26) {
    playTone(frequencies[stepNumber - 1], 150);
  }
}

void playPauseSound() {
  static int pauseSoundStep = 0;
  static unsigned long lastSoundTime = 0;
  const int tones[] = {659, 523};
  const int durations[] = {200, 300};

  if (shouldAbort()) {
    pauseSoundStep = 0;
    return;
  }

  if (pauseSoundStep < 2 && millis() - lastSoundTime >= (pauseSoundStep > 0 ? durations[pauseSoundStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[pauseSoundStep], durations[pauseSoundStep]);
      pauseSoundStep++;
      lastSoundTime = millis();
    }
  } else if (pauseSoundStep >= 2) {
    pauseSoundStep = 0;
  }
}

void playStopSound() {
  static int stopSoundStep = 0;
  static unsigned long lastSoundTime = 0;
  const int tones[] = {784, 659, 523, 392};
  const int durations[] = {150, 150, 200, 300};

  if (shouldAbort()) {
    stopSoundStep = 0;
    return;
  }

  if (stopSoundStep < 4 && millis() - lastSoundTime >= (stopSoundStep > 0 ? durations[stopSoundStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[stopSoundStep], durations[stopSoundStep]);
      stopSoundStep++;
      lastSoundTime = millis();
    }
  } else if (stopSoundStep >= 4) {
    stopSoundStep = 0;
  }
}

void playResumeSound() {
  static int resumeSoundStep = 0;
  static unsigned long lastSoundTime = 0;
  const int tones[] = {523, 659, 784};
  const int durations[] = {150, 150, 200};

  if (shouldAbort()) {
    resumeSoundStep = 0;
    return;
  }

  if (resumeSoundStep < 3 && millis() - lastSoundTime >= (resumeSoundStep > 0 ? durations[resumeSoundStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[resumeSoundStep], durations[resumeSoundStep]);
      resumeSoundStep++;
      lastSoundTime = millis();
    }
  } else if (resumeSoundStep >= 3) {
    resumeSoundStep = 0;
  }
}

void playErrorSound() {
  static int errorSoundStep = 0;
  static unsigned long lastSoundTime = 0;
  const int tones[] = {200, 200, 200};
  const int durations[] = {100, 100, 100};
  const int delays[] = {50, 50, 0};

  if (shouldAbort()) {
    errorSoundStep = 0;
    return;
  }

  if (errorSoundStep < 3 && millis() - lastSoundTime >= (errorSoundStep > 0 ? delays[errorSoundStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[errorSoundStep], durations[errorSoundStep]);
      errorSoundStep++;
      lastSoundTime = millis();
    }
  } else if (errorSoundStep >= 3) {
    errorSoundStep = 0;
  }
}

void testBuzzer() {
  static int buzzerTestStep = 0;
  static unsigned long lastTestTime = 0;
  const int tones[] = {500, 800, 1100, 1400, 1700, 2000};
  const int durations[] = {150, 150, 150, 150, 150, 150};
  const int delays[] = {200, 200, 200, 200, 200, 200};

  if (shouldAbort()) {
    buzzerTestStep = 0;
    return;
  }

  if (buzzerTestStep < 6 && millis() - lastTestTime >= (buzzerTestStep > 0 ? delays[buzzerTestStep - 1] : 0)) {
    if (!currentTone.active) {
      playTone(tones[buzzerTestStep], durations[buzzerTestStep]);
      buzzerTestStep++;
      lastTestTime = millis();
    }
  } else if (buzzerTestStep >= 6) {
    buzzerTestStep = 0;
  }
}

// === OPTIMIZED LCD UPDATE FUNCTIONS ===
void updateLcdScreenFast() {
  if (millis() - lastLcdUpdate < 50) return;
  lcd.clear();
  switch (lcdState) {
    case PLAYING:
      lcd.setCursor(0, 0);
      lcd.print(currentSong.substring(0, 16));
      lcd.setCursor(0, 1);
      lcd.print(obstacleDetected ? "OBSTACLE!" : "Playing");
      break;
    case PAUSED:
      lcd.setCursor(0, 0);
      lcd.print(currentSong.substring(0, 16));
      lcd.setCursor(0, 1);
      lcd.print("Paused");
      break;
    case STOPPED:
      lcd.setCursor(0, 0);
      lcd.print("Robot Ready");
      lcd.setCursor(0, 1);
      lcd.print("Clap to dance!");
      break;
    case INIT:
      lcd.setCursor(0, 0);
      lcd.print("IP Address:");
      lcd.setCursor(0, 1);
      lcd.print(WiFi.localIP().toString());
      break;
  }
  lastLcdUpdate = millis();
}

// === SONG-SPECIFIC STEP EXECUTION ===
void executeDanceStep() {
  if (shouldAbort() || danceState == DANCE_IDLE) {
    danceState = DANCE_IDLE;
    return;
  }

  if (millis() - danceStepStartTime < 10) return;

  if (danceState == DANCE_EXECUTING_STEP) {
    if (currentSong == "Falling For You") {
      executeFallingStep(currentDanceStep);
    } else if (currentSong == "Stereo Love") {
      executeStereoStep(currentDanceStep);
    } else if (currentSong == "Faded") {
      executeFadedStep(currentDanceStep);
    } else if (currentSong == "Alone") {
      executeAloneStep(currentDanceStep);
    } else if (currentSong == "Mastie Mashup") {
      executeNeuralStep(currentDanceStep);
    } else {
      executeOtherStep(currentDanceStep);
    }
    danceState = DANCE_RESETTING;
    danceStepStartTime = millis();
  } else if (danceState == DANCE_RESETTING) {
    if (millis() - danceStepStartTime >= 200) {
      resetAllServos();
      danceState = DANCE_IDLE;
      Serial.println("Dance step complete, servos reset");
    }
  }
}

// === ULTRA-FAST WEBSOCKET EVENT HANDLER ===
void handleWebSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length) {
  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      webSocketConnected = false;
      break;
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d\n", num, ip[0], ip[1], ip[2], ip[3]);
        webSocketConnected = true;
        webSocket.sendTXT(num, "connected");
      }
      break;
    case WStype_TEXT:
      {
        String message = String((char*)payload).substring(0, length);
        if (message == "pause") {
          webSocket.sendTXT(num, "paused_ack");
          pauseImmediate();
          playPauseSound();
          Serial.println("⚡ IMMEDIATE PAUSE EXECUTED");
          return;
        }
        if (message == "stop") {
          webSocket.sendTXT(num, "stopped_ack");
          stopImmediate();
          playStopSound();
          Serial.println("⚡ IMMEDIATE STOP EXECUTED");
          return;
        }
        if (message == "resume") {
          webSocket.sendTXT(num, "resumed_ack");
          resumeFromPause();
          playResumeSound();
          Serial.println("⚡ IMMEDIATE RESUME EXECUTED");
          return;
        }
        if (message == "heartbeat") {
          return;
        }
        if (message.toInt() >= 1 && message.toInt() <= 26) {
          currentDanceStep = message.toInt();
          playStepSound(currentDanceStep);
          danceState = DANCE_EXECUTING_STEP;
          danceStepStartTime = millis();
        } else if (message.startsWith("song:")) {
          webSocket.sendTXT(num, "song_started");
          currentSong = message.substring(5);
          gAbortAll = false;
          isDancing = true;
          lcdState = PLAYING;
          setMotorSpeed(danceSpeed);
          setLedPattern(LED_DANCE);
          playDanceSound();
          Serial.println("Song started: " + currentSong);
        } else if (message.startsWith("speed:")) {
          int newSpeed = message.substring(6).toInt();
          if (newSpeed >= 0 && newSpeed <= 255) {
            changeSpeedGradually(newSpeed);
            webSocket.sendTXT(num, "speed_changed");
            Serial.print("Speed changed to: ");
            Serial.println(newSpeed);
          } else {
            webSocket.sendTXT(num, "speed_error");
            playErrorSound();
          }
        } else if (message.startsWith("led:")) {
          String ledCommand = message.substring(4);
          ledCommand.toLowerCase();
          if (ledCommand == "off") {
            setLedPattern(LED_OFF);
          } else if (ledCommand == "rainbow") {
            setLedPattern(LED_RAINBOW);
          } else if (ledCommand == "pulse") {
            setLedPattern(LED_PULSE);
          } else if (ledCommand == "chase") {
            setLedPattern(LED_CHASE);
          } else if (ledCommand == "strobe") {
            setLedPattern(LED_STROBE);
          } else if (ledCommand == "fire") {
            setLedPattern(LED_FIRE);
          } else if (ledCommand == "dance") {
            setLedPattern(LED_DANCE);
          } else if (ledCommand == "breathing") {
            setLedPattern(LED_BREATHING);
          } else if (ledCommand == "wave") {
            setLedPattern(LED_WAVE);
          } else {
            playErrorSound();
            webSocket.sendTXT(num, "led_error");
            Serial.println("Unknown LED pattern");
          }
        } else if (message.startsWith("brightness:")) {
          int newBrightness = message.substring(11).toInt();
          if (newBrightness >= 0 && newBrightness <= 255) {
            ledBrightness = newBrightness;
            FastLED.setBrightness(ledBrightness);
            webSocket.sendTXT(num, "brightness_changed");
            Serial.print("LED brightness changed to: ");
            Serial.println(newBrightness);
          } else {
            playErrorSound();
            webSocket.sendTXT(num, "brightness_error");
          }
        } else {
          playErrorSound();
          webSocket.sendTXT(num, "unknown_command");
          Serial.println("Unknown command received: " + message);
        }
      }
      break;
    case WStype_ERROR:
      Serial.printf("[%u] WebSocket Error: %s\n", num, payload);
      break;
    default:
      break;
  }
}

// === SETUP WITH OPTIMIZATIONS ===
void setup() {
  Serial.begin(115200);
  delay(1000); // Brief delay for serial stability
  Serial.println("=== RythmoBot with Ultra-Fast WebSocket Response Starting ===");

  // Initialize pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(SOUND_SENSOR_PIN, INPUT);

  // Setup PWM channels for motor speed control
  setupPWMChannels();

  // Setup LED strips
  setupLEDs();

  stopBase();

  // Initialize hardware
  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(50);
  lcd.init();
  lcd.backlight();

  // Play startup sound
  playStartupSound();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RythmoBot");
  lcd.setCursor(0, 1);
  lcd.print("Connecting...");

  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  int wifiRetries = 0;
  while (WiFi.status() != WL_CONNECTED && wifiRetries < 20) {
    delay(500);
    Serial.print(".");
    wifiRetries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\n=== WiFi Connected! ===");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    optimizeWiFi();
    playWifiConnectedSound();
    setLedPattern(LED_WIFI_SUCCESS);
    wifiPatternStartTime = millis();
    wifiPatternCompleted = false;
    lcdState = INIT;
    updateLcdScreenFast();
    webSocket.begin();
    webSocket.onEvent(handleWebSocketEvent);
    webSocket.enableHeartbeat(1000, 3000, 2);
    Serial.println("WebSocket server started with ultra-fast response optimizations.");
  } else {
    Serial.println("\n❌ WiFi connection failed!");
    playErrorSound();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi Failed!");
    lcd.setCursor(0, 1);
    lcd.print("Check credentials");
  }

  // Initialize servos
  resetAllServos();
  pwmWriteAngle(MOTOR_CH15, 45);
  motorCurrentAngle = 45;

  Serial.println("=== RythmoBot Setup Complete with Ultra-Fast WebSocket Response ===");
}

// === ULTRA-OPTIMIZED MAIN LOOP ===
void loop() {
  while (true) {
    // HIGHEST PRIORITY: WebSocket handling
    webSocket.loop();

    // Send heartbeat
    // if (millis() - lastKeepAlive >= KEEP_ALIVE_INTERVAL) {
    //   if (webSocketConnected) {
    //     webSocket.broadcastTXT("heartbeat");
    //   }
    //   lastKeepAlive = millis();
    // }

    if (!gPaused) {
      checkForClap();
      checkForObstacles();
    }

    // Update tasks
    updateLEDs();
    handleWifiLedPatternCompletion();
    updateBuzzer();

    if (isDancing && !obstacleDetected && !clapMovementInProgress && !shouldAbort()) {
      handleBaseMovement();
    } else {
      stopBase();
    }

    if (!shouldAbort()) {
      handleMotorCH15();
    }

    if (clapMovementInProgress) {
      executeClapResponseStep();
    }

    if (danceState != DANCE_IDLE) {
      executeDanceStep();
    }

    updateLcdScreenFast();

    if (lcdState == PLAYING && millis() - lastAnimationTime > 400 && !clapMovementInProgress) {
      dotCount = (dotCount + 1) % 4;
      String playingText = obstacleDetected ? "OBSTACLE!" : "Playing";
      if (!obstacleDetected) {
        for (int i = 0; i < dotCount; i++) playingText += ".";
      }
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);
      lcd.print(playingText);
      lastAnimationTime = millis();
    }

    yield();
  }
}

// === BASE MOVEMENT FUNCTIONS ===
void moveForward(int duration) {
  static unsigned long moveStartTime = 0;
  static bool moving = false;

  if (obstacleDetected || clapMovementInProgress || shouldAbort()) {
    moving = false;
    stopBase();
    return;
  }

  if (!moving) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    moving = true;
    moveStartTime = millis();
  }

  if (millis() - moveStartTime >= duration) {
    stopBase();
    moving = false;
  }
}

void moveBackward(int duration) {
  static unsigned long moveStartTime = 0;
  static bool moving = false;

  if (obstacleDetected || clapMovementInProgress || shouldAbort()) {
    moving = false;
    stopBase();
    return;
  }

  if (!moving) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    moving = true;
    moveStartTime = millis();
  }

  if (millis() - moveStartTime >= duration) {
    stopBase();
    moving = false;
  }
}

void stopBase() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void handleBaseMovement() {
  if (!isDancing || obstacleDetected || clapMovementInProgress || shouldAbort()) return;
  if (millis() - lastBaseMovement >= baseMovementInterval) {
    if (isMovingForward) {
      moveForward(300);
      if (++currentCycleCount >= FORWARD_CYCLES) {
        isMovingForward = false;
        currentCycleCount = 0;
      }
    } else {
      moveBackward(300);
      if (++currentCycleCount >= BACKWARD_CYCLES) {
        isMovingForward = true;
        currentCycleCount = 0;
      }
    }
    lastBaseMovement = millis();
  }
}

// === SERVO FUNCTIONS ===
int degreeToPulse(int degree) {
  return map(degree, 0, 180, 150, 600);
}

void pwmWriteAngle(uint8_t ch, float angle) {
  pwm.setPWM(ch, 0, degreeToPulse((int)angle));
  if (ch < 12) {
    currentServoAngles[ch] = angle;
  }
}

void smoothMove(uint8_t channel, int toAngle, int delayMs) {
  if (channel >= 12) return;
  int fromAngle = currentServoAngles[channel];
  int step = (toAngle > fromAngle) ? 5 : -5;
  int steps = abs(toAngle - fromAngle) / 5;

  for (int i = 0; i <= steps; i++) {
    if (shouldAbort()) {
      return;
    }
    int newAngle = fromAngle + (i * step);
    if ((step > 0 && newAngle > toAngle) || (step < 0 && newAngle < toAngle)) {
      newAngle = toAngle;
    }
    pwmWriteAngle(channel, newAngle);
    delay(delayMs);
    webSocket.loop(); // Allow WebSocket processing during servo movement
  }
}

void resetAllServos() {
  for (int i = 0; i < 12; i++) {
    smoothMove(i, servoHome[i], 10);
  }
}
