/*
 * =========================================================
 * STEREO LOVE - DANCE CHOREOGRAPHY HEADER FILE
 * =========================================================
 * Contains all 28 dance steps for "Stereo Love" song
 * Each step is a complete choreographed movement sequence
 * Electronic dance music style with rhythmic movements
 * =========================================================
 */

#ifndef STEREO_H
#define STEREO_H

// Include required libraries
#include <Arduino.h>

// External function declarations (these will be defined in the main file)
extern void smoothMove(uint8_t s, int to, int stepD);
extern void pwmWriteAngle(uint8_t ch, float angle);
extern void moveForward(int duration);
extern void moveBackward(int duration);
extern void stopBase();
extern void playStepSound(int stepNumber);

// External pin definitions
extern const int LEG1_HIP_CHANNEL;
extern const int LEG1_KNEE_CHANNEL;
extern const int LEG1_ANKLE_CHANNEL;
extern const int LEG2_HIP_CHANNEL;
extern const int LEG2_KNEE_CHANNEL;
extern const int LEG2_ANKLE_CHANNEL;
extern const int IN1, IN2, IN3, IN4;

// === STEREO LOVE - 28 DANCE STEPS ===

// Step 1: Electronic intro - Sharp robotic movements
void stereo_step1() {
  Serial.println("Stereo Step 1: Electronic intro - Sharp robotic movements");
  
  // Sharp, angular arm movements
  smoothMove(0, 90, 5);   // Quick, precise movements
  smoothMove(3, 90, 5);
  delay(200);
  
  smoothMove(0, 45, 3);   // Sharp angle
  smoothMove(3, 135, 3);
  smoothMove(1, 90, 3);   // 90-degree angles
  smoothMove(4, 90, 3);
  delay(300);
  
  smoothMove(0, 135, 3);  // Switch positions sharply
  smoothMove(3, 45, 3);
  delay(300);
  
  // Robotic leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 8);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 8);
  
  // Mechanical movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(300);
  stopBase();
  delay(200);
}

// Step 2: Beat drop preparation
void stereo_step2() {
  Serial.println("Stereo Step 2: Beat drop preparation");
  
  // Build-up arm movements
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 60 - (i * 5), 4);
    smoothMove(3, 120 + (i * 5), 4);
    smoothMove(2, 45 + (i * 10), 4);
    smoothMove(5, 135 - (i * 10), 4);
    delay(250);
  }
  
  // Preparation pause
  smoothMove(0, 30);
  smoothMove(3, 150);
  smoothMove(1, 45);
  smoothMove(4, 135);
  delay(400);
  
  // Building leg tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 12);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 12);
  
  // Anticipatory movement
  moveForward(150);
  moveBackward(150);
  delay(300);
}

// Step 3: First beat drop - Explosive energy
void stereo_step3() {
  Serial.println("Stereo Step 3: First beat drop - Explosive energy");
  
  // Explosive arm burst
  smoothMove(0, 10, 2);   // Maximum speed
  smoothMove(3, 170, 2);
  smoothMove(1, 10, 2);
  smoothMove(4, 170, 2);
  smoothMove(2, 20, 2);
  smoothMove(5, 160, 2);
  delay(200);
  
  // Rapid alternating
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 170, 2);
    smoothMove(3, 10, 2);
    delay(150);
    smoothMove(0, 10, 2);
    smoothMove(3, 170, 2);
    delay(150);
  }
  
  // Explosive leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 15);
  delay(200);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 25);
  
  // Explosive movement
  moveForward(200);
  delay(300);
}

// Step 4: Electronic pulse rhythm
void stereo_step4() {
  Serial.println("Stereo Step 4: Electronic pulse rhythm");
  
  // Pulsing arm movements in sync with beat
  for (int i = 0; i < 8; i++) {
    // Pulse out
    smoothMove(0, 60, 3);
    smoothMove(3, 120, 3);
    smoothMove(1, 30, 3);
    smoothMove(4, 150, 3);
    delay(180);
    
    // Pulse in
    smoothMove(0, 90, 3);
    smoothMove(3, 90, 3);
    smoothMove(1, 45, 3);
    smoothMove(4, 135, 3);
    delay(180);
  }
  
  // Rhythmic leg pulses
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  delay(200);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  
  // Pulsing movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(200);
  stopBase();
  delay(200);
}

// Step 5: Stereo effect - Left/Right alternating
void stereo_step5() {
  Serial.println("Stereo Step 5: Stereo effect - Left/Right alternating");
  
  // Strong left-right alternating movements
  for (int i = 0; i < 6; i++) {
    // Left side dominant
    smoothMove(0, 30, 4);
    smoothMove(1, 20, 4);
    smoothMove(2, 30, 4);
    smoothMove(3, 90, 4);   // Right side neutral
    smoothMove(4, 90, 4);
    smoothMove(5, 90, 4);
    delay(250);
    
    // Right side dominant
    smoothMove(0, 90, 4);   // Left side neutral
    smoothMove(1, 90, 4);
    smoothMove(2, 90, 4);
    smoothMove(3, 150, 4);
    smoothMove(4, 160, 4);
    smoothMove(5, 150, 4);
    delay(250);
  }
  
  // Alternating leg emphasis
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  delay(250);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  delay(250);
  
  // Side-to-side movement
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(300);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(300);
  stopBase();
}

// Step 6: Love theme introduction - Softer movements
void stereo_step6() {
  Serial.println("Stereo Step 6: Love theme introduction - Softer movements");
  
  // Flowing, romantic arm gestures
  smoothMove(0, 70, 12);   // Slower, smoother
  smoothMove(3, 110, 12);
  smoothMove(1, 40, 12);
  smoothMove(4, 140, 12);
  smoothMove(2, 110, 12);
  smoothMove(5, 70, 12);
  delay(500);
  
  // Heart-like gesture
  smoothMove(0, 100, 10);
  smoothMove(3, 80, 10);
  smoothMove(2, 120, 10);
  smoothMove(5, 60, 10);
  delay(400);
  
  // Open embrace gesture
  smoothMove(0, 50, 15);
  smoothMove(3, 130, 15);
  smoothMove(2, 70, 15);
  smoothMove(5, 110, 15);
  delay(600);
  
  // Gentle leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 6);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 6);
  
  // Gentle forward movement
  moveForward(250);
  delay(400);
}

// Step 7: Building electronic intensity
void stereo_step7() {
  Serial.println("Stereo Step 7: Building electronic intensity");
  
  // Gradually increasing intensity
  for (int i = 1; i <= 5; i++) {
    smoothMove(0, 90 - (i * 12), 8 - i);
    smoothMove(3, 90 + (i * 12), 8 - i);
    smoothMove(1, 45 - (i * 5), 8 - i);
    smoothMove(4, 135 + (i * 5), 8 - i);
    delay(300 - (i * 30));
  }
  
  // Sharp directional changes
  smoothMove(2, 45, 3);
  smoothMove(5, 135, 3);
  delay(200);
  smoothMove(2, 135, 3);
  smoothMove(5, 45, 3);
  delay(200);
  
  // Building leg energy
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16 + random(-3, 3));
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16 + random(-3, 3));
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12 + random(-2, 2));
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12 + random(-2, 2));
  
  // Increasing movement intensity
  moveForward(180);
  moveBackward(180);
  moveForward(120);
  delay(250);
}

// Step 8: Chorus explosion
void stereo_step8() {
  Serial.println("Stereo Step 8: Chorus explosion");
  
  // Maximum energy explosion
  for (int i = 0; i < 10; i++) {
    smoothMove(0, random(10, 170), 2);
    smoothMove(3, random(10, 170), 2);
    smoothMove(1, random(10, 170), 2);
    smoothMove(4, random(10, 170), 2);
    smoothMove(2, random(20, 160), 2);
    smoothMove(5, random(20, 160), 2);
    delay(120);
  }
  
  // Explosive leg choreography
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 22);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);
  delay(150);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 22);
  
  // Frenzied movement
  for (int i = 0; i < 5; i++) {
    moveForward(100);
    moveBackward(100);
    delay(80);
  }
}

// Step 9: Stereo wave effect
void stereo_step9() {
  Serial.println("Stereo Step 9: Stereo wave effect");
  
  // Wave motion from left to right
  for (int wave = 0; wave < 4; wave++) {
    // Left arm up
    smoothMove(0, 45, 4);
    smoothMove(1, 30, 4);
    delay(150);
    
    // Left bicep follows
    smoothMove(2, 60, 4);
    delay(150);
    
    // Right shoulder starts
    smoothMove(3, 135, 4);
    smoothMove(4, 150, 4);
    delay(150);
    
    // Right bicep completes wave
    smoothMove(5, 120, 4);
    delay(150);
    
    // Reset for next wave
    smoothMove(0, 90, 4);
    smoothMove(1, 90, 4);
    smoothMove(2, 90, 4);
    smoothMove(3, 90, 4);
    smoothMove(4, 90, 4);
    smoothMove(5, 90, 4);
    delay(200);
  }
  
  // Wave motion in legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  delay(200);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  delay(200);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  delay(200);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  
  // Wave-like movement
  moveForward(200);
  delay(400);
}

// Step 10: Electronic breakdown
void stereo_step10() {
  Serial.println("Stereo Step 10: Electronic breakdown");
  
  // Glitchy, broken movements
  for (int i = 0; i < 8; i++) {
    smoothMove(0, 90 + random(-30, 30), 2);
    delay(100);
    smoothMove(3, 90 + random(-30, 30), 2);
    delay(100);
    smoothMove(1, 45 + random(-15, 15), 3);
    delay(150);
    smoothMove(4, 135 + random(-15, 15), 3);
    delay(150);
  }
  
  // Stuttering forearm movements
  for (int stutter = 0; stutter < 6; stutter++) {
    smoothMove(2, 70, 2);
    delay(80);
    smoothMove(2, 110, 2);
    delay(80);
    smoothMove(5, 70, 2);
    delay(80);
    smoothMove(5, 110, 2);
    delay(80);
  }
  
  // Broken leg movements
  pwmWriteAngle(LEG1_HIP_CHANNEL, 15);
  delay(100);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  delay(100);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 15);
  delay(100);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  
  // Stuttering movement
  moveForward(80);
  delay(100);
  moveBackward(80);
  delay(100);
  moveForward(80);
  delay(300);
}

// Step 11: Love vocal emphasis
void stereo_step11() {
  Serial.println("Stereo Step 11: Love vocal emphasis");
  
  // Emotional reaching gestures
  smoothMove(0, 60, 15);   // Slow, emotional
  smoothMove(3, 120, 15);
  smoothMove(1, 35, 15);
  smoothMove(4, 145, 15);
  delay(600);
  
  // Embrace motion
  smoothMove(0, 110, 12);
  smoothMove(3, 70, 12);
  smoothMove(2, 130, 12);
  smoothMove(5, 50, 12);
  delay(500);
  
  // Release and reach again
  smoothMove(0, 45, 15);
  smoothMove(3, 135, 15);
  smoothMove(2, 60, 15);
  smoothMove(5, 120, 15);
  delay(600);
  
  // Emotional leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 8);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 8);
  
  // Slow, meaningful movement
  moveForward(300);
  delay(500);
}

// Step 12: Build to second drop
void stereo_step12() {
  Serial.println("Stereo Step 12: Build to second drop");
  
  // Escalating arm movements
  for (int level = 1; level <= 6; level++) {
    smoothMove(0, 90 - (level * 8), 10 - level);
    smoothMove(3, 90 + (level * 8), 10 - level);
    smoothMove(1, 45 - (level * 3), 10 - level);
    smoothMove(4, 135 + (level * 3), 10 - level);
    smoothMove(2, 90 - (level * 5), 10 - level);
    smoothMove(5, 90 + (level * 5), 10 - level);
    delay(400 - (level * 50));
  }
  
  // Pre-drop tension
  smoothMove(0, 30);
  smoothMove(3, 150);
  smoothMove(1, 20);
  smoothMove(4, 160);
  delay(300);
  
  // Building leg tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 14);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 14);
  
  // Building movement
  moveBackward(200);
  delay(300);
}

// Step 13: Second massive drop
void stereo_step13() {
  Serial.println("Stereo Step 13: Second massive drop");
  
  // Even more explosive than first drop
  for (int burst = 0; burst < 12; burst++) {
    smoothMove(0, random(5, 175), 1);   // Maximum speed
    smoothMove(3, random(5, 175), 1);
    smoothMove(1, random(5, 175), 1);
    smoothMove(4, random(5, 175), 1);
    smoothMove(2, random(15, 165), 1);
    smoothMove(5, random(15, 165), 1);
    delay(100);
  }
  
  // Extreme leg choreography
  pwmWriteAngle(LEG1_HIP_CHANNEL, 30);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 25);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  delay(120);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 30);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 25);
  
  // Extreme movement burst
  for (int i = 0; i < 6; i++) {
    moveForward(80);
    moveBackward(80);
    delay(60);
  }
  delay(200);
}

// Step 14: Sustained electronic energy
void stereo_step14() {
  Serial.println("Stereo Step 14: Sustained electronic energy");
  
  // High-energy sustained movements
  for (int i = 0; i < 8; i++) {
    smoothMove(0, 25, 3);
    smoothMove(3, 155, 3);
    smoothMove(1, 15, 3);
    smoothMove(4, 165, 3);
    delay(200);
    
    smoothMove(0, 155, 3);
    smoothMove(3, 25, 3);
    smoothMove(1, 165, 3);
    smoothMove(4, 15, 3);
    delay(200);
  }
  
  // Continuous forearm action
  for (int i = 0; i < 10; i++) {
    smoothMove(2, 45, 3);
    smoothMove(5, 135, 3);
    delay(150);
    smoothMove(2, 135, 3);
    smoothMove(5, 45, 3);
    delay(150);
  }
  
  // Sustained leg energy
  pwmWriteAngle(LEG1_HIP_CHANNEL, 24);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 24);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);
  
  // Continuous movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(250);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(250);
  stopBase();
}

// Step 15: Electronic love theme
void stereo_step15() {
  Serial.println("Stereo Step 15: Electronic love theme");
  
  // Blend of electronic precision with emotional flow
  smoothMove(0, 70, 8);
  smoothMove(3, 110, 8);
  delay(300);
  
  // Sharp electronic accent
  smoothMove(1, 25, 2);
  smoothMove(4, 155, 2);
  delay(150);
  
  // Smooth love flow
  smoothMove(2, 120, 12);
  smoothMove(5, 60, 12);
  delay(400);
  
  // Electronic pulse
  smoothMove(0, 45, 3);
  smoothMove(3, 135, 3);
  delay(200);
  
  // Love gesture
  smoothMove(0, 100, 10);
  smoothMove(3, 80, 10);
  delay(400);
  
  // Mixed leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  // Smooth movement with electronic accent
  moveForward(250);
  delay(200);
  moveForward(100);
  delay(300);
}

// Step 16: Stereo separation effect
void stereo_step16() {
  Serial.println("Stereo Step 16: Stereo separation effect");
  
  // Extreme left-right separation
  for (int sep = 0; sep < 8; sep++) {
    // Maximum left
    smoothMove(0, 10, 4);
    smoothMove(1, 5, 4);
    smoothMove(2, 20, 4);
    smoothMove(3, 90, 6);   // Right side stays neutral
    smoothMove(4, 90, 6);
    smoothMove(5, 90, 6);
    delay(300);
    
    // Maximum right
    smoothMove(0, 90, 6);   // Left side stays neutral
    smoothMove(1, 90, 6);
    smoothMove(2, 90, 6);
    smoothMove(3, 170, 4);
    smoothMove(4, 175, 4);
    smoothMove(5, 160, 4);
    delay(300);
  }
  
  // Extreme leg separation
  pwmWriteAngle(LEG1_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 5);
  delay(400);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 25);
  delay(400);
  
  // Separation movement
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(400);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(400);
  stopBase();
}

// Step 17: Bridge section - Atmospheric
void stereo_step17() {
  Serial.println("Stereo Step 17: Bridge section - Atmospheric");
  
  // Atmospheric, floating movements
  smoothMove(0, 75, 20);   // Very slow, dreamy
  smoothMove(3, 105, 20);
  smoothMove(1, 50, 20);
  smoothMove(4, 130, 20);
  delay(800);
  
  // Floating gestures
  for (int float_cycle = 0; float_cycle < 4; float_cycle++) {
    smoothMove(2, 60 + (float_cycle * 5), 15);
    smoothMove(5, 120 - (float_cycle * 5), 15);
    delay(600);
    smoothMove(2, 120 - (float_cycle * 5), 15);
    smoothMove(5, 60 + (float_cycle * 5), 15);
    delay(600);
  }
  
  // Gentle leg sway
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  delay(500);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  delay(500);
  
  // Floating movement
  moveForward(180);
  delay(600);
}

// Step 18: Building to final drop
void stereo_step18() {
  Serial.println("Stereo Step 18: Building to final drop");
  
  // Massive build-up
  for (int build = 1; build <= 8; build++) {
    int speed = 12 - build;
    int amplitude = build * 10;
    
    smoothMove(0, 90 - amplitude, speed);
    smoothMove(3, 90 + amplitude, speed);
    smoothMove(1, 45 - (build * 4), speed);
    smoothMove(4, 135 + (build * 4), speed);
    smoothMove(2, 90 - (build * 6), speed);
    smoothMove(5, 90 + (build * 6), speed);
    
    delay(500 - (build * 40));
  }
  
  // Final build tension
  smoothMove(0, 10);
  smoothMove(3, 170);
  smoothMove(1, 10);
  smoothMove(4, 170);
  smoothMove(2, 30);
  smoothMove(5, 150);
  delay(400);
  
  // Maximum leg tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 22);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 22);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 18);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 18);
  
  // Build-up movement
  moveBackward(300);
  delay(400);
}

// Step 19: Ultimate final drop
void stereo_step19() {
  Serial.println("Stereo Step 19: Ultimate final drop");
  
  // Most explosive drop yet
  for (int explosion = 0; explosion < 15; explosion++) {
    smoothMove(0, random(0, 180), 1);   // Absolute maximum speed
    smoothMove(3, random(0, 180), 1);
    smoothMove(1, random(0, 180), 1);
    smoothMove(4, random(0, 180), 1);
    smoothMove(2, random(10, 170), 1);
    smoothMove(5, random(10, 170), 1);
    delay(90);
  }
  
  // Ultimate leg explosion
  for (int leg_burst = 0; leg_burst < 8; leg_burst++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(5, 35));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(5, 35));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(10, 30));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(10, 30));
    delay(150);
  }
  
  // Ultimate movement explosion
  for (int i = 0; i < 8; i++) {
    moveForward(60);
    moveBackward(60);
    delay(50);
  }
  delay(300);
}

// Step 20: Peak electronic energy
void stereo_step20() {
  Serial.println("Stereo Step 20: Peak electronic energy");
  
  // Sustained maximum energy
  for (int peak = 0; peak < 12; peak++) {
    smoothMove(0, 15, 2);
    smoothMove(3, 165, 2);
    smoothMove(1, 10, 2);
    smoothMove(4, 170, 2);
    smoothMove(2, 25, 2);
    smoothMove(5, 155, 2);
    delay(140);
    
    smoothMove(0, 165, 2);
    smoothMove(3, 15, 2);
    smoothMove(1, 170, 2);
    smoothMove(4, 10, 2);
    smoothMove(2, 155, 2);
    smoothMove(5, 25, 2);
    delay(140);
  }
  
  // Peak leg performance
  pwmWriteAngle(LEG1_HIP_CHANNEL, 26);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 24);
  delay(150);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 26);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 24);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  
  // Peak movement energy
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(180);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(180);
  stopBase();
  delay(200);
}

// Step 21: Electronic love climax
void stereo_step21() {
  Serial.println("Stereo Step 21: Electronic love climax");
  
  // Perfect blend of electronic and emotional
  smoothMove(0, 45, 6);
  smoothMove(3, 135, 6);
  smoothMove(1, 30, 6);
  smoothMove(4, 150, 6);
  delay(300);
  
  // Electronic accent with love gesture
  smoothMove(2, 120, 3);
  smoothMove(5, 60, 3);
  delay(200);
  smoothMove(2, 60, 12);
  smoothMove(5, 120, 12);
  delay(400);
  
  // Heart gesture with electronic pulse
  smoothMove(0, 110, 8);
  smoothMove(3, 70, 8);
  delay(300);
  smoothMove(0, 70, 3);
  smoothMove(3, 110, 3);
  delay(150);
  smoothMove(0, 100, 8);
  smoothMove(3, 80, 8);
  delay(400);
  
  // Climactic leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 14);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 14);
  
  // Climactic movement
  moveForward(350);
  delay(400);
}

// Step 22: Stereo love echo
void stereo_step22() {
  Serial.println("Stereo Step 22: Stereo love echo");
  
  // Echo effects - repeating gestures with decreasing intensity
  for (int echo = 4; echo >= 1; echo--) {
    int intensity = echo * 15;
    int speed = 15 - (echo * 2);
    
    // Love gesture echo
    smoothMove(0, 90 - intensity, speed);
    smoothMove(3, 90 + intensity, speed);
    smoothMove(1, 45 - (echo * 5), speed);
    smoothMove(4, 135 + (echo * 5), speed);
    delay(400 + (4 - echo) * 100);
    
    // Electronic accent echo
    smoothMove(2, 90 - intensity, speed/2);
    smoothMove(5, 90 + intensity, speed/2);
    delay(200 + (4 - echo) * 50);
  }
  
  // Echoing leg movements
  for (int leg_echo = 3; leg_echo >= 1; leg_echo--) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, 10 + (leg_echo * 4));
    pwmWriteAngle(LEG2_HIP_CHANNEL, 10 + (leg_echo * 4));
    delay(300 + (3 - leg_echo) * 100);
  }
  
  // Echoing movement
  moveForward(200);
  delay(300);
  moveForward(100);
  delay(500);
}

// Step 23: Final electronic surge
void stereo_step23() {
  Serial.println("Stereo Step 23: Final electronic surge");
  
  // Last major electronic burst
  for (int surge = 0; surge < 10; surge++) {
    smoothMove(0, 20 + random(-10, 20), 2);
    smoothMove(3, 160 + random(-20, 10), 2);
    smoothMove(1, 15 + random(-5, 25), 2);
    smoothMove(4, 165 + random(-25, 5), 2);
    smoothMove(2, 30 + random(-10, 30), 2);
    smoothMove(5, 150 + random(-30, 10), 2);
    delay(130);
  }
  
  // Final surge in legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 24);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 22);
  delay(200);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 24);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 22);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);
  
  // Final movement surge
  for (int i = 0; i < 6; i++) {
    moveForward(90);
    moveBackward(90);
    delay(100);
  }
  delay(300);
}

// Step 24: Love theme return
void stereo_step24() {
  Serial.println("Stereo Step 24: Love theme return");
  
  // Return to love theme with electronic undertones
  smoothMove(0, 75, 12);
  smoothMove(3, 105, 12);
  smoothMove(1, 45, 12);
  smoothMove(4, 135, 12);
  delay(500);
  
  // Gentle electronic pulses within love gestures
  for (int pulse = 0; pulse < 6; pulse++) {
    smoothMove(2, 110, 8);
    smoothMove(5, 70, 8);
    delay(300);
    
    // Electronic accent
    smoothMove(2, 115, 2);
    smoothMove(5, 65, 2);
    delay(100);
    smoothMove(2, 105, 8);
    smoothMove(5, 75, 8);
    delay(300);
  }
  
  // Gentle but electronic-influenced legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  
  // Smooth movement with subtle accents
  moveForward(200);
  delay(200);
  moveForward(50);
  delay(400);
}

// Step 25: Begin wind down
void stereo_step25() {
  Serial.println("Stereo Step 25: Begin wind down");
  
  // Gradual energy decrease with electronic flavor
  for (int wind = 6; wind >= 1; wind--) {
    int amplitude = wind * 10;
    int speed = 8 + (6 - wind) * 2;
    
    smoothMove(0, 90 - amplitude, speed);
    smoothMove(3, 90 + amplitude, speed);
    smoothMove(1, 45 - (wind * 3), speed);
    smoothMove(4, 135 + (wind * 3), speed);
    delay(250 + (6 - wind) * 100);
    
    // Electronic accents getting softer
    if (wind > 2) {
      smoothMove(2, 90 - (amplitude/2), speed/2);
      smoothMove(5, 90 + (amplitude/2), speed/2);
      delay(150);
    }
  }
  
  // Winding down legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  delay(300);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  delay(400);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  
  // Slowing movement
  moveBackward(250);
  delay(600);
}

// Step 26: Electronic fadeout
void stereo_step26() {
  Serial.println("Stereo Step 26: Electronic fadeout");
  
  // Soft electronic pulses fading out
  for (int fade = 0; fade < 8; fade++) {
    int intensity = 8 - fade;
    
    smoothMove(0, 90 - (intensity * 3), 12 + fade);
    smoothMove(3, 90 + (intensity * 3), 12 + fade);
    delay(400 + (fade * 100));
    
    smoothMove(0, 90 + (intensity * 3), 12 + fade);
    smoothMove(3, 90 - (intensity * 3), 12 + fade);
    delay(400 + (fade * 100));
  }
  
  // Final gentle positioning
  smoothMove(1, 60, 15);
  smoothMove(4, 120, 15);
  smoothMove(2, 105, 15);
  smoothMove(5, 75, 15);
  delay(600);
  
  // Gentle leg settling
  pwmWriteAngle(LEG1_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 3);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 3);
  
  // Gentle retreat movement
  moveBackward(180);
  delay(500);
}

// Step 27: Love resolution
void stereo_step27() {
  Serial.println("Stereo Step 27: Love resolution");
  
  // Final love gestures with electronic essence
  smoothMove(0, 80, 18);
  smoothMove(3, 100, 18);
  smoothMove(1, 50, 18);
  smoothMove(4, 130, 18);
  delay(700);
  
  // Heart gesture resolution
  smoothMove(0, 105, 15);
  smoothMove(3, 75, 15);
  smoothMove(2, 125, 15);
  smoothMove(5, 55, 15);
  delay(600);
  
  // Open to embrace gesture
  smoothMove(0, 60, 20);
  smoothMove(3, 120, 20);
  smoothMove(2, 80, 20);
  smoothMove(5, 100, 20);
  delay(800);
  
  // Final gentle sway
  for (int sway = 0; sway < 4; sway++) {
    smoothMove(0, 65, 12);
    smoothMove(3, 115, 12);
    delay(400);
    smoothMove(0, 75, 12);
    smoothMove(3, 105, 12);
    delay(400);
  }
  
  // Love resolution leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 5);
  
  // Final gentle movement
  moveForward(150);
  delay(600);
}

// Step 28: Final pose and complete fadeout
void stereo_step28() {
  Serial.println("Stereo Step 28: Final pose and complete fadeout");
  
  // Ultimate final positioning
  smoothMove(0, 75, 25);   // Very slow, deliberate final pose
  smoothMove(3, 105, 25);
  smoothMove(1, 45, 25);
  smoothMove(4, 135, 25);
  smoothMove(2, 90, 25);
  smoothMove(5, 90, 25);
  delay(1000);
  
  // Final breathing effect
  for (int breath = 0; breath < 6; breath++) {
    smoothMove(0, 72, 10);
    smoothMove(3, 108, 10);
    delay(400);
    smoothMove(0, 78, 10);
    smoothMove(3, 102, 10);
    delay(400);
  }
  
  // Electronic glitch farewell
  for (int glitch = 0; glitch < 3; glitch++) {
    smoothMove(2, 92, 3);
    delay(100);
    smoothMove(2, 88, 3);
    delay(100);
    smoothMove(5, 88, 3);
    delay(100);
    smoothMove(5, 92, 3);
    delay(200);
  }
  
  // Final complete rest position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 2);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 2);
  
  delay(1000);
  
  // Final electronic fadeout
  Serial.println("Stereo Love complete - Love transmitted electronically");
  delay(500);
}

// Function to execute "Stereo Love" dance steps
void executeStereoStep(int step) {
  switch (step) {
    case 1: stereo_step1(); break;
    case 2: stereo_step2(); break;
    case 3: stereo_step3(); break;
    case 4: stereo_step4(); break;
    case 5: stereo_step5(); break;
    case 6: stereo_step6(); break;
    case 7: stereo_step7(); break;
    case 8: stereo_step8(); break;
    case 9: stereo_step9(); break;
    case 10: stereo_step10(); break;
    case 11: stereo_step11(); break;
    case 12: stereo_step12(); break;
    case 13: stereo_step13(); break;
    case 14: stereo_step14(); break;
    case 15: stereo_step15(); break;
    case 16: stereo_step16(); break;
    case 17: stereo_step17(); break;
    case 18: stereo_step18(); break;
    case 19: stereo_step19(); break;
    case 20: stereo_step20(); break;
    case 21: stereo_step21(); break;
    case 22: stereo_step22(); break;
    case 23: stereo_step23(); break;
    case 24: stereo_step24(); break;
    case 25: stereo_step25(); break;
    case 26: stereo_step26(); break;
    case 27: stereo_step27(); break;
    case 28: stereo_step28(); break;
    
    default: 
      Serial.println("Unknown step - valid steps are 1-28 for 'Stereo Love'"); 
      return;
  }
}

#endif
