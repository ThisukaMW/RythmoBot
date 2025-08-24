/*
 * =========================================================
 * FALLING FOR YOU - DANCE CHOREOGRAPHY HEADER FILE
 * =========================================================
 * Contains all 26 dance steps for "Falling for you" song
 * Each step is a complete choreographed movement sequence
 * =========================================================
 */

#ifndef FALLINGFORYOU_H
#define FALLINGFORYOU_H

// Include required libraries
#include <Arduino.h>

// External function declarations (these will be defined in the main file)
extern void smoothMove(uint8_t s, int to, int stepD = 10);
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

// === FALLING FOR YOU - 26 DANCE STEPS ===

// Step 1: Song Intro - Gentle arm sway
void falling_step1() {
  Serial.println("Falling Step 1: Song Intro - Gentle arm sway");
  
  // Gentle alternating arm waves
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 70);   // Left shoulder slight up
    smoothMove(3, 110);  // Right shoulder slight up
    smoothMove(1, 25);   // Left bicep adjust
    smoothMove(4, 80);   // Right bicep adjust
    delay(400);
    
    smoothMove(0, 110);  // Switch positions
    smoothMove(3, 70);
    smoothMove(1, 65);
    smoothMove(4, 40);
    delay(400);
  }
  
  // Soft leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 2);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 2);
  
  // Gentle forward movement
  moveForward(200);
  delay(600);
}

// Step 2: Building up - More arm movement
void falling_step2() {
  Serial.println("Falling Step 2: Building up - More arm movement");
  
  // More dynamic arm movements
  smoothMove(0, 45);   // Arms spread wider
  smoothMove(3, 135);
  smoothMove(2, 60);   // Forearms out
  smoothMove(5, 120);
  delay(300);
  
  // Cross and uncross
  smoothMove(0, 120);
  smoothMove(3, 60);
  smoothMove(2, 90);
  smoothMove(5, 90);
  delay(400);
  
  // Legs with more bend
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 5);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 5);
  
  // Side movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(250);
  stopBase();
  delay(400);
}

// Step 3: First chorus approach
void falling_step3() {
  Serial.println("Falling Step 3: First chorus approach");
  
  // Reaching gestures
  smoothMove(0, 30);   // Reach up
  smoothMove(3, 150);
  smoothMove(1, 10);   // Extend arms
  smoothMove(4, 170);
  delay(500);
  
  // Pull back motion
  smoothMove(0, 80);
  smoothMove(3, 100);
  smoothMove(1, 50);
  smoothMove(4, 130);
  delay(300);
  
  // Dynamic leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 8);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 8);
  
  // Backward movement
  moveBackward(300);
  delay(500);
}

// Step 4: "I'm falling" - Dramatic gesture
void falling_step4() {
  Serial.println("Falling Step 4: I'm falling - Dramatic gesture");
  
  // Falling gesture - arms sweep down
  smoothMove(0, 130);  // Arms high
  smoothMove(3, 50);
  smoothMove(2, 30);   // Hands up
  smoothMove(5, 150);
  delay(400);
  
  // Sweep down motion
  smoothMove(2, 140);  // Hands sweep down
  smoothMove(5, 40);
  delay(300);
  
  // Recovery gesture
  smoothMove(0, 90);
  smoothMove(3, 90);
  smoothMove(2, 90);
  smoothMove(5, 90);
  delay(200);
  
  // Legs react to "falling"
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 10);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 10);
  
  delay(600);
}

// Step 5: "For you" - Pointing/reaching gesture
void falling_step5() {
  Serial.println("Falling Step 5: For you - Pointing/reaching gesture");
  
  // Pointing gesture sequence
  smoothMove(0, 60);   // Left arm point
  smoothMove(1, 30);
  smoothMove(2, 45);
  delay(300);
  
  smoothMove(3, 120);  // Right arm point
  smoothMove(4, 150);
  smoothMove(5, 135);
  delay(300);
  
  // Both arms reaching forward
  smoothMove(0, 75);
  smoothMove(3, 105);
  smoothMove(1, 45);
  smoothMove(4, 135);
  smoothMove(2, 60);
  smoothMove(5, 120);
  delay(400);
  
  // Legs in stable position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 5);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 5);
  
  // Forward movement
  moveForward(250);
  delay(450);
}

// Step 6: Chorus energy build
void falling_step6() {
  Serial.println("Falling Step 6: Chorus energy build");
  
  // Energetic alternating arm pumps
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 45 + (i * 10));
    smoothMove(3, 135 - (i * 10));
    smoothMove(1, 20 + (i * 5));
    smoothMove(4, 160 - (i * 5));
    delay(200);
  }
  
  // Quick arm crosses
  smoothMove(0, 135);
  smoothMove(3, 45);
  delay(200);
  smoothMove(0, 45);
  smoothMove(3, 135);
  delay(200);
  
  // Active leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 15);
  delay(200);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 15);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  
  // Side-to-side movement
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(200);
  stopBase();
  delay(300);
}

// Step 7: High energy dance
void falling_step7() {
  Serial.println("Falling Step 7: High energy dance");
  
  // Rapid arm movements
  for (int i = 0; i < 5; i++) {
    smoothMove(0, 20, 5);   // Fast movements
    smoothMove(3, 160, 5);
    smoothMove(1, 10, 5);
    smoothMove(4, 170, 5);
    delay(150);
    
    smoothMove(0, 160, 5);
    smoothMove(3, 20, 5);
    smoothMove(1, 170, 5);
    smoothMove(4, 10, 5);
    delay(150);
  }
  
  // Dynamic leg choreography
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 15);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 15);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 15);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 15);
  
  // Multiple direction changes
  moveForward(150);
  moveBackward(150);
  delay(200);
}

// Step 8: Emotional peak
void falling_step8() {
  Serial.println("Falling Step 8: Emotional peak");
  
  // Slow, expressive arm movements
  smoothMove(0, 60, 15);   // Slower, more deliberate
  smoothMove(3, 120, 15);
  smoothMove(1, 40, 15);
  smoothMove(4, 140, 15);
  delay(600);
  
  // Heart gesture (arms to chest)
  smoothMove(0, 100);
  smoothMove(3, 80);
  smoothMove(2, 110);
  smoothMove(5, 70);
  delay(500);
  
  // Open arms wide
  smoothMove(0, 30);
  smoothMove(3, 150);
  smoothMove(2, 45);
  smoothMove(5, 135);
  delay(400);
  
  // Emotional leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 6);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 6);
  
  delay(600);
}

// Step 9: Bridge transition
void falling_step9() {
  Serial.println("Falling Step 9: Bridge transition");
  
  // Transitional wave motion
  smoothMove(0, 90);   // Return to center
  smoothMove(3, 90);
  smoothMove(1, 45);
  smoothMove(4, 60);
  smoothMove(2, 135);
  smoothMove(5, 135);
  delay(300);
  
  // Wave arms left to right
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 45 + (i * 15));
    smoothMove(3, 135 - (i * 15));
    delay(250);
    smoothMove(0, 135 - (i * 15));
    smoothMove(3, 45 + (i * 15));
    delay(250);
  }
  
  // Reset leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 3);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 3);
  
  // Gentle movement
  moveForward(200);
  delay(400);
}

// Step 10: Second verse begins
void falling_step10() {
  Serial.println("Falling Step 10: Second verse begins");
  
  // Subtle storytelling gestures
  smoothMove(0, 75);   // Gentle narrative gestures
  smoothMove(3, 105);
  smoothMove(1, 35);
  smoothMove(4, 145);
  smoothMove(2, 110);
  smoothMove(5, 70);
  delay(500);
  
  // Alternate gesture
  smoothMove(0, 105);
  smoothMove(3, 75);
  smoothMove(1, 55);
  smoothMove(4, 125);
  smoothMove(2, 70);
  smoothMove(5, 110);
  delay(500);
  
  // Quiet leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 4);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 4);
  
  // Slow movement
  moveBackward(180);
  delay(500);
}

// Step 11: Building emotion again
void falling_step11() {
  Serial.println("Falling Step 11: Building emotion again");
  
  // Gradual arm elevation
  for (int angle = 90; angle >= 60; angle -= 10) {
    smoothMove(0, angle);
    smoothMove(3, 180 - angle);
    delay(200);
  }
  
  // Expressive forearm movement
  smoothMove(1, 20);
  smoothMove(4, 160);
  smoothMove(2, 50);
  smoothMove(5, 130);
  delay(400);
  
  // Building leg tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 8);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 8);
  
  // Building movement energy
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(300);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(300);
  stopBase();
  delay(200);
}

// Step 12: Second "I'm falling"
void falling_step12() {
  Serial.println("Falling Step 12: Second I'm falling");
  
  // More intense falling gesture
  smoothMove(0, 150);  // Arms higher than first time
  smoothMove(3, 30);
  smoothMove(2, 20);   // Hands reach higher
  smoothMove(5, 160);
  delay(400);
  
  // Dramatic sweep with pause
  smoothMove(2, 160);  // Bigger sweep motion
  smoothMove(5, 20);
  delay(200);
  
  // Hold the emotion
  smoothMove(0, 75);
  smoothMove(3, 105);
  delay(300);
  
  // Legs show more "falling" motion
  pwmWriteAngle(LEG1_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 15);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 15);
  
  // Dramatic backward movement
  moveBackward(350);
  delay(400);
}

// Step 13: "For you" - Second time, more intense
void falling_step13() {
  Serial.println("Falling Step 13: For you - Second time, more intense");
  
  // Double pointing gesture
  smoothMove(0, 45);   // Left point
  smoothMove(1, 20);
  smoothMove(2, 30);
  delay(200);
  
  smoothMove(3, 135);  // Right point
  smoothMove(4, 160);
  smoothMove(5, 150);
  delay(200);
  
  // Both arms reach with more intensity
  smoothMove(0, 60);
  smoothMove(3, 120);
  smoothMove(1, 30);
  smoothMove(4, 150);
  smoothMove(2, 45);
  smoothMove(5, 135);
  delay(300);
  
  // Push forward gesture
  smoothMove(1, 60);
  smoothMove(4, 120);
  delay(200);
  
  // Strong leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 12);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 12);
  
  // Strong forward movement
  moveForward(400);
  delay(300);
}

// Step 14: Second chorus - Peak energy
void falling_step14() {
  Serial.println("Falling Step 14: Second chorus - Peak energy");
  
  // Explosive arm movements
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 20 + random(-10, 10), 3);  // Add randomness
    smoothMove(3, 160 + random(-10, 10), 3);
    smoothMove(1, 10 + random(-5, 15), 3);
    smoothMove(4, 170 + random(-15, 5), 3);
    delay(120);
    
    smoothMove(0, 160 + random(-10, 10), 3);
    smoothMove(3, 20 + random(-10, 10), 3);
    smoothMove(1, 170 + random(-15, 5), 3);
    smoothMove(4, 10 + random(-5, 15), 3);
    delay(120);
  }
  
  // Peak leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 18);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 14);
  
  // Rapid direction changes
  moveForward(120);
  moveBackward(120);
  moveForward(120);
  delay(200);
}

// Step 15: Emotional climax
void falling_step15() {
  Serial.println("Falling Step 15: Emotional climax");
  
  // Slow, powerful arm raise
  smoothMove(0, 45, 20);   // Very slow, deliberate
  smoothMove(3, 135, 20);
  smoothMove(1, 30, 20);
  smoothMove(4, 150, 20);
  smoothMove(2, 45, 20);
  smoothMove(5, 135, 20);
  delay(800);
  
  // Hold pose with slight sway
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 40);
    smoothMove(3, 140);
    delay(300);
    smoothMove(0, 50);
    smoothMove(3, 130);
    delay(300);
  }
  
  // Emotional leg hold
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 10);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 10);
  
  delay(700);
}

// Step 16: Bridge/Breakdown
void falling_step16() {
  Serial.println("Falling Step 16: Bridge/Breakdown");
  
  // Broken, stuttering movements
  smoothMove(0, 90);   // Return to neutral
  smoothMove(3, 90);
  delay(200);
  
  smoothMove(0, 70, 5);   // Quick jerky movements
  delay(100);
  smoothMove(0, 110, 5);
  delay(100);
  smoothMove(3, 70, 5);
  delay(100);
  smoothMove(3, 110, 5);
  delay(100);
  
  // Stuttering arm gestures
  for (int i = 0; i < 4; i++) {
    smoothMove(1, 30, 3);
    smoothMove(4, 150, 3);
    delay(150);
    smoothMove(1, 50, 3);
    smoothMove(4, 130, 3);
    delay(150);
  }
  
  // Unsure leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  delay(200);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  delay(200);
  
  // Hesitant movement
  moveForward(100);
  delay(200);
  moveBackward(100);
  delay(400);
}

// Step 17: Building back up
void falling_step17() {
  Serial.println("Falling Step 17: Building back up");
  
  // Gradual return to energy
  for (int i = 0; i < 5; i++) {
    int amplitude = 20 + (i * 10);  // Increasing amplitude
    smoothMove(0, 90 - amplitude);
    smoothMove(3, 90 + amplitude);
    delay(300 - (i * 30));  // Increasing speed
    
    smoothMove(0, 90 + amplitude);
    smoothMove(3, 90 - amplitude);
    delay(300 - (i * 30));
  }
  
  // Arms building energy
  smoothMove(1, 25);
  smoothMove(4, 155);
  smoothMove(2, 60);
  smoothMove(5, 120);
  delay(300);
  
  // Legs building tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 10);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 10);
  
  // Building movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(250);
  stopBase();
  delay(250);
}

// Step 18: Final chorus approach
void falling_step18() {
  Serial.println("Falling Step 18: Final chorus approach");
  
  // Anticipatory arm movements
  smoothMove(0, 60);
  smoothMove(3, 120);
  smoothMove(1, 40);
  smoothMove(4, 140);
  delay(200);
  
  // Quick preparation movements
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 45 + (i * 5));
    smoothMove(3, 135 - (i * 5));
    smoothMove(2, 90 + (i * 10));
    smoothMove(5, 90 - (i * 10));
    delay(200);
  }
  
  // Ready position legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 14);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 14);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 12);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 12);
  
  // Anticipatory movement
  moveForward(200);
  moveBackward(200);
  delay(300);
}

// Step 19: Final "I'm falling" - Most dramatic
void falling_step19() {
  Serial.println("Falling Step 19: Final I'm falling - Most dramatic");
  
  // Ultimate dramatic gesture
  smoothMove(0, 170);  // Highest reach yet
  smoothMove(3, 10);
  smoothMove(2, 10);   // Hands reach highest
  smoothMove(5, 170);
  delay(600);
  
  // Most dramatic fall
  smoothMove(2, 170);  // Biggest sweep
  smoothMove(5, 10);
  delay(400);
  
  // Catch and hold
  smoothMove(0, 80);
  smoothMove(3, 100);
  smoothMove(1, 60);
  smoothMove(4, 120);
  delay(500);
  
  // Ultimate falling leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 30);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 30);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 25);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 25);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 20);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 20);
  
  // Dramatic movement
  moveBackward(400);
  delay(500);
}

// Step 20: Final "For you" - Ultimate dedication
void falling_step20() {
  Serial.println("Falling Step 20: Final For you - Ultimate dedication");
  
  // Ultimate pointing/reaching sequence
  smoothMove(0, 30);   // Most extended reach
  smoothMove(1, 10);
  smoothMove(2, 20);
  delay(300);
  
  smoothMove(3, 150);  // Opposite extreme
  smoothMove(4, 170);
  smoothMove(5, 160);
  delay(300);
  
  // Ultimate combined reach
  smoothMove(0, 45);
  smoothMove(3, 135);
  smoothMove(1, 20);
  smoothMove(4, 160);
  smoothMove(2, 30);
  smoothMove(5, 150);
  delay(400);
  
  // Push everything forward
  smoothMove(1, 80);
  smoothMove(4, 100);
  delay(300);
  
  // Ultimate dedication leg stance
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 15);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 15);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 15);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 15);
  
  // Ultimate forward commitment
  moveForward(500);
  delay(400);
}

// Step 21: Final chorus explosion
void falling_step21() {
  Serial.println("Falling Step 21: Final chorus explosion");
  
  // Ultimate energy explosion
  for (int i = 0; i < 8; i++) {
    smoothMove(0, random(10, 170), 2);  // Maximum randomness and speed
    smoothMove(3, random(10, 170), 2);
    smoothMove(1, random(10, 170), 2);
    smoothMove(4, random(10, 170), 2);
    smoothMove(2, random(20, 160), 2);
    smoothMove(5, random(20, 160), 2);
    delay(100);
  }
  
  // Extreme leg choreography
  pwmWriteAngle(LEG1_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  delay(150);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  
  // Frenzied movement
  for (int i = 0; i < 4; i++) {
    moveForward(100);
    moveBackward(100);
    delay(50);
  }
  delay(200);
}

// Step 22: Sustained high energy
void falling_step22() {
  Serial.println("Falling Step 22: Sustained high energy");
  
  // Sustained powerful movements
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 30, 4);
    smoothMove(3, 150, 4);
    smoothMove(1, 15, 4);
    smoothMove(4, 165, 4);
    delay(180);
    
    smoothMove(0, 150, 4);
    smoothMove(3, 30, 4);
    smoothMove(1, 165, 4);
    smoothMove(4, 15, 4);
    delay(180);
  }
  
  // Sustained leg power
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 16);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 16);
  
  // Sustained movement energy
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(200);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(200);
  stopBase();
  delay(200);
}

// Step 23: Emotional peak hold
void falling_step23() {
  Serial.println("Falling Step 23: Emotional peak hold");
  
  // Hold the emotional peak
  smoothMove(0, 45, 25);   // Extremely slow, powerful
  smoothMove(3, 135, 25);
  smoothMove(1, 30, 25);
  smoothMove(4, 150, 25);
  smoothMove(2, 45, 25);
  smoothMove(5, 135, 25);
  delay(1000);
  
  // Trembling/vibrating effect
  for (int i = 0; i < 10; i++) {
    smoothMove(0, 43, 2);
    smoothMove(3, 137, 2);
    delay(80);
    smoothMove(0, 47, 2);
    smoothMove(3, 133, 2);
    delay(80);
  }
  
  // Emotional leg hold
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 10);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 10);
  
  delay(700);
}

// Step 24: Begin wind down
void falling_step24() {
  Serial.println("Falling Step 24: Begin wind down");
  
  // Gradual energy decrease
  for (int i = 5; i >= 1; i--) {
    int amplitude = i * 15;
    smoothMove(0, 90 - amplitude);
    smoothMove(3, 90 + amplitude);
    smoothMove(1, 45 - (i * 5));
    smoothMove(4, 60 + (i * 5));
    delay(300 + (5 - i) * 100);  // Slowing down
    
    smoothMove(0, 90 + amplitude);
    smoothMove(3, 90 - amplitude);
    delay(300 + (5 - i) * 100);
  }
  
  // Winding down arms
  smoothMove(2, 90 + (25));
  smoothMove(5, 90 - (25));
  delay(400);
  smoothMove(2, 90 + (15));
  smoothMove(5, 90 - (15));
  delay(400);
  
  // Relaxing legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 6);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 6);
  
  // Slower movement
  moveForward(250);
  delay(600);
}

// Step 25: Soft resolution
void falling_step25() {
  Serial.println("Falling Step 25: Soft resolution");
  
  // Gentle, resolving movements
  smoothMove(0, 80, 18);   // Slow, gentle movements
  smoothMove(3, 100, 18);
  smoothMove(1, 50, 18);
  smoothMove(4, 130, 18);
  smoothMove(2, 120, 18);
  smoothMove(5, 60, 18);
  delay(600);
  
  // Peaceful sway
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 85);
    smoothMove(3, 95);
    delay(400);
    smoothMove(0, 95);
    smoothMove(3, 85);
    delay(400);
  }
  
  // Settling legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 4);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 4);
  
  // Gentle backward movement
  moveBackward(200);
  delay(500);
}

// Step 26: Final pose and fade out
void falling_step26() {
  Serial.println("Falling Step 26: Final pose and fade out");
  
  // Final emotional gesture
  smoothMove(0, 75, 20);   // Very slow final positioning
  smoothMove(3, 105, 20);
  smoothMove(1, 45, 20);
  smoothMove(4, 135, 20);
  smoothMove(2, 90, 20);
  smoothMove(5, 90, 20);
  delay(800);
  
  // Hold final pose with slight breathing motion
  for (int i = 0; i < 5; i++) {
    smoothMove(0, 73, 8);
    smoothMove(3, 107, 8);
    delay(300);
    smoothMove(0, 77, 8);
    smoothMove(3, 103, 8);
    delay(300);
  }
  
  // Final leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 5);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 2);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 2);
  
  delay(1000);
  
  // Slow fade to home - this will be handled by resetAllServos() after step execution
  Serial.println("Song complete - preparing to return to home position");
  delay(500);
}

// Function to execute "Falling for you" dance steps
void executeFallingStep(int step) {
  switch (step) {
    case 1: falling_step1(); break;
    case 2: falling_step2(); break;
    case 3: falling_step3(); break;
    case 4: falling_step4(); break;
    case 5: falling_step5(); break;
    case 6: falling_step6(); break;
    case 7: falling_step7(); break;
    case 8: falling_step8(); break;
    case 9: falling_step9(); break;
    case 10: falling_step10(); break;
    case 11: falling_step11(); break;
    case 12: falling_step12(); break;
    case 13: falling_step13(); break;
    case 14: falling_step14(); break;
    case 15: falling_step15(); break;
    case 16: falling_step16(); break;
    case 17: falling_step17(); break;
    case 18: falling_step18(); break;
    case 19: falling_step19(); break;
    case 20: falling_step20(); break;
    case 21: falling_step21(); break;
    case 22: falling_step22(); break;
    case 23: falling_step23(); break;
    case 24: falling_step24(); break;
    case 25: falling_step25(); break;
    case 26: falling_step26(); break;
    
    default: 
      Serial.println("Unknown step - valid steps are 1-26 for 'Falling for you'"); 
      return;
  }
}

#endif
