/*
 * =========================================================
 * FADED - DANCE CHOREOGRAPHY HEADER FILE
 * =========================================================
 * Contains all 30 dance steps for "Faded" by Alan Walker
 * Each step is a complete choreographed movement sequence
 * Atmospheric, melancholic electronic style with builds
 * =========================================================
 */

#ifndef FADED_H
#define FADED_H

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

// === FADED - 30 DANCE STEPS ===

// Step 1: Atmospheric intro - Ghostly movements
void faded_step1() {
  Serial.println("Faded Step 1: Atmospheric intro - Ghostly movements");
  
  // Slow, ethereal arm movements
  smoothMove(0, 85, 20);   // Very slow, haunting
  smoothMove(3, 95, 20);
  smoothMove(1, 50, 20);
  smoothMove(4, 130, 20);
  delay(800);
  
  // Floating gesture
  smoothMove(2, 110, 25);
  smoothMove(5, 70, 25);
  delay(700);
  
  // Ghost-like sway
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 80, 15);
    smoothMove(3, 100, 15);
    delay(600);
    smoothMove(0, 100, 15);
    smoothMove(3, 80, 15);
    delay(600);
  }
  
  // Minimal leg positioning - floating effect
  pwmWriteAngle(LEG1_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 3);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 3);
  
  // Gentle drift movement
  moveForward(150);
  delay(800);
}

// Step 2: Melancholic buildup
void faded_step2() {
  Serial.println("Faded Step 2: Melancholic buildup");
  
  // Sad, reaching gestures
  smoothMove(0, 70, 18);
  smoothMove(3, 110, 18);
  smoothMove(1, 35, 18);
  smoothMove(4, 145, 18);
  delay(700);
  
  // Pulling down motion (like fading away)
  smoothMove(1, 55, 12);
  smoothMove(4, 125, 12);
  smoothMove(2, 130, 15);
  smoothMove(5, 50, 15);
  delay(500);
  
  // Lonely arm extension
  smoothMove(0, 45, 16);
  smoothMove(3, 135, 16);
  delay(600);
  
  // Slight leg movement - uncertain steps
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  
  // Hesitant movement
  moveBackward(120);
  delay(600);
}

// Step 3: First vocal entry - Emotional reach
void faded_step3() {
  Serial.println("Faded Step 3: First vocal entry - Emotional reach");
  
  // Emotional reaching out
  smoothMove(0, 60, 14);
  smoothMove(3, 120, 14);
  smoothMove(1, 30, 14);
  smoothMove(4, 150, 14);
  delay(600);
  
  // Heart gesture - longing
  smoothMove(0, 105, 12);
  smoothMove(3, 75, 12);
  smoothMove(2, 125, 12);
  smoothMove(5, 55, 12);
  delay(500);
  
  // Release and fade gesture
  smoothMove(0, 90, 16);
  smoothMove(3, 90, 16);
  smoothMove(2, 90, 16);
  smoothMove(5, 90, 16);
  delay(400);
  
  // Building leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  
  // Emotional forward movement
  moveForward(200);
  delay(500);
}

// Step 4: Building atmosphere
void faded_step4() {
  Serial.println("Faded Step 4: Building atmosphere");
  
  // Atmospheric wave movements
  for (int wave = 0; wave < 4; wave++) {
    smoothMove(0, 70 + (wave * 5), 12);
    smoothMove(3, 110 - (wave * 5), 12);
    smoothMove(1, 40 + (wave * 3), 12);
    smoothMove(4, 140 - (wave * 3), 12);
    delay(400);
  }
  
  // Floating hand movements
  smoothMove(2, 60, 18);
  smoothMove(5, 120, 18);
  delay(600);
  smoothMove(2, 120, 18);
  smoothMove(5, 60, 18);
  delay(600);
  
  // Atmospheric leg sway
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  delay(400);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  delay(400);
  
  // Floating movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(300);
  stopBase();
  delay(400);
}

// Step 5: First drop approach
void faded_step5() {
  Serial.println("Faded Step 5: First drop approach");
  
  // Building tension with slow precision
  for (int build = 1; build <= 5; build++) {
    smoothMove(0, 90 - (build * 8), 15 - build);
    smoothMove(3, 90 + (build * 8), 15 - build);
    smoothMove(1, 45 - (build * 4), 15 - build);
    smoothMove(4, 135 + (build * 4), 15 - build);
    delay(500 - (build * 60));
  }
  
  // Pre-drop tension hold
  smoothMove(2, 40, 8);
  smoothMove(5, 140, 8);
  delay(400);
  
  // Tension in legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  // Building backward tension
  moveBackward(250);
  delay(400);
}

// Step 6: First drop - Electronic burst
void faded_step6() {
  Serial.println("Faded Step 6: First drop - Electronic burst");
  
  // Electronic drop explosion
  for (int burst = 0; burst < 8; burst++) {
    smoothMove(0, random(20, 160), 3);
    smoothMove(3, random(20, 160), 3);
    smoothMove(1, random(15, 165), 3);
    smoothMove(4, random(15, 165), 3);
    smoothMove(2, random(30, 150), 3);
    smoothMove(5, random(30, 150), 3);
    delay(130);
  }
  
  // Drop leg choreography
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  delay(150);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 16);
  
  // Electronic movement burst
  for (int i = 0; i < 5; i++) {
    moveForward(90);
    moveBackward(90);
    delay(80);
  }
  delay(200);
}

// Step 7: Faded theme - Disappearing gestures
void faded_step7() {
  Serial.println("Faded Step 7: Faded theme - Disappearing gestures");
  
  // Fading away arm sequence
  smoothMove(0, 75, 12);
  smoothMove(3, 105, 12);
  delay(300);
  
  // Gradual fade motion
  for (int fade = 5; fade >= 1; fade--) {
    smoothMove(1, 45 - (fade * 3), 8 + fade);
    smoothMove(4, 135 + (fade * 3), 8 + fade);
    smoothMove(2, 90 - (fade * 8), 10 + fade);
    smoothMove(5, 90 + (fade * 8), 10 + fade);
    delay(300 + (5 - fade) * 100);
  }
  
  // Return to center - faded
  smoothMove(1, 60, 15);
  smoothMove(4, 120, 15);
  smoothMove(2, 90, 15);
  smoothMove(5, 90, 15);
  delay(500);
  
  // Fading leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  
  // Fade movement
  moveForward(180);
  delay(600);
}

// Step 8: Melancholic verse
void faded_step8() {
  Serial.println("Faded Step 8: Melancholic verse");
  
  // Slow, sad storytelling gestures
  smoothMove(0, 80, 20);
  smoothMove(3, 100, 20);
  smoothMove(1, 50, 20);
  smoothMove(4, 130, 20);
  delay(800);
  
  // Longing reach
  smoothMove(0, 65, 16);
  smoothMove(3, 115, 16);
  smoothMove(2, 110, 18);
  smoothMove(5, 70, 18);
  delay(700);
  
  // Pull back - rejection/loss
  smoothMove(0, 95, 14);
  smoothMove(3, 85, 14);
  smoothMove(2, 70, 16);
  smoothMove(5, 110, 16);
  delay(600);
  
  // Melancholic leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 11);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 13);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 7);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 9);
  
  // Slow, sad movement
  moveBackward(160);
  delay(700);
}

// Step 9: Atmospheric bridge
void faded_step9() {
  Serial.println("Faded Step 9: Atmospheric bridge");
  
  // Ethereal floating movements
  for (int float_cycle = 0; float_cycle < 6; float_cycle++) {
    smoothMove(0, 85 + (float_cycle % 2 ? 5 : -5), 18);
    smoothMove(3, 95 + (float_cycle % 2 ? -5 : 5), 18);
    smoothMove(1, 45 + (float_cycle * 2), 20);
    smoothMove(4, 135 - (float_cycle * 2), 20);
    delay(600);
  }
  
  // Dreamy hand waves
  smoothMove(2, 80, 22);
  smoothMove(5, 100, 22);
  delay(800);
  smoothMove(2, 100, 22);
  smoothMove(5, 80, 22);
  delay(800);
  
  // Floating leg motion
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  delay(500);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  delay(500);
  
  // Ethereal movement
  moveForward(120);
  delay(800);
}

// Step 10: Building to second drop
void faded_step10() {
  Serial.println("Faded Step 10: Building to second drop");
  
  // Intensifying atmospheric build
  for (int intensity = 1; intensity <= 6; intensity++) {
    smoothMove(0, 90 - (intensity * 7), 12 - intensity);
    smoothMove(3, 90 + (intensity * 7), 12 - intensity);
    smoothMove(1, 45 - (intensity * 3), 12 - intensity);
    smoothMove(4, 135 + (intensity * 3), 12 - intensity);
    smoothMove(2, 90 - (intensity * 5), 14 - intensity);
    smoothMove(5, 90 + (intensity * 5), 14 - intensity);
    delay(400 - (intensity * 40));
  }
  
  // Pre-second drop tension
  smoothMove(0, 35);
  smoothMove(3, 145);
  smoothMove(1, 25);
  smoothMove(4, 155);
  delay(300);
  
  // Maximum tension legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 16);
  
  // Tension movement
  moveBackward(300);
  delay(400);
}

// Step 11: Second drop - More intense
void faded_step11() {
  Serial.println("Faded Step 11: Second drop - More intense");
  
  // More intense electronic burst
  for (int explosion = 0; explosion < 10; explosion++) {
    smoothMove(0, random(15, 165), 2);
    smoothMove(3, random(15, 165), 2);
    smoothMove(1, random(10, 170), 2);
    smoothMove(4, random(10, 170), 2);
    smoothMove(2, random(25, 155), 2);
    smoothMove(5, random(25, 155), 2);
    delay(110);
  }
  
  // Intense leg choreography
  for (int leg_cycle = 0; leg_cycle < 6; leg_cycle++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(15, 28));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(15, 28));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(12, 24));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(12, 24));
    delay(140);
  }
  
  // Intense movement sequence
  for (int i = 0; i < 6; i++) {
    moveForward(70);
    moveBackward(70);
    delay(60);
  }
  delay(250);
}

// Step 12: Electronic pulse section
void faded_step12() {
  Serial.println("Faded Step 12: Electronic pulse section");
  
  // Rhythmic electronic pulses
  for (int pulse = 0; pulse < 8; pulse++) {
    // Pulse out
    smoothMove(0, 70, 4);
    smoothMove(3, 110, 4);
    smoothMove(1, 35, 4);
    smoothMove(4, 145, 4);
    delay(160);
    
    // Pulse in
    smoothMove(0, 90, 4);
    smoothMove(3, 90, 4);
    smoothMove(1, 45, 4);
    smoothMove(4, 135, 4);
    delay(160);
  }
  
  // Pulse forearms
  for (int arm_pulse = 0; arm_pulse < 6; arm_pulse++) {
    smoothMove(2, 70, 3);
    smoothMove(5, 110, 3);
    delay(120);
    smoothMove(2, 110, 3);
    smoothMove(5, 70, 3);
    delay(120);
  }
  
  // Pulse legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  delay(200);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  
  // Pulse movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(200);
  stopBase();
  delay(300);
}

// Step 13: Faded memories - Nostalgic
void faded_step13() {
  Serial.println("Faded Step 13: Faded memories - Nostalgic");
  
  // Nostalgic, remembering gestures
  smoothMove(0, 75, 16);
  smoothMove(3, 105, 16);
  smoothMove(1, 40, 18);
  smoothMove(4, 140, 18);
  delay(600);
  
  // Memory reach - trying to grasp
  smoothMove(0, 60, 14);
  smoothMove(3, 120, 14);
  smoothMove(2, 120, 16);
  smoothMove(5, 60, 16);
  delay(500);
  
  // Memory fades - pull back
  smoothMove(0, 100, 18);
  smoothMove(3, 80, 18);
  smoothMove(2, 90, 20);
  smoothMove(5, 90, 20);
  delay(600);
  
  // Gentle sway - reminiscing
  for (int memory = 0; memory < 4; memory++) {
    smoothMove(0, 85, 12);
    smoothMove(3, 95, 12);
    delay(400);
    smoothMove(0, 95, 12);
    smoothMove(3, 85, 12);
    delay(400);
  }
  
  // Nostalgic leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  
  // Slow remembering movement
  moveForward(150);
  delay(700);
}

// Step 14: Emotional breakdown
void faded_step14() {
  Serial.println("Faded Step 14: Emotional breakdown");
  
  // Broken, fragmented movements
  smoothMove(0, 90, 8);
  delay(200);
  smoothMove(0, 70, 5);
  delay(150);
  smoothMove(0, 110, 5);
  delay(150);
  smoothMove(3, 70, 5);
  delay(150);
  smoothMove(3, 110, 5);
  delay(150);
  
  // Stuttering emotional gestures
  for (int stutter = 0; stutter < 6; stutter++) {
    smoothMove(1, 35, 3);
    smoothMove(4, 145, 3);
    delay(120);
    smoothMove(1, 55, 3);
    smoothMove(4, 125, 3);
    delay(120);
    smoothMove(2, 80, 3);
    smoothMove(5, 100, 3);
    delay(100);
    smoothMove(2, 100, 3);
    smoothMove(5, 80, 3);
    delay(100);
  }
  
  // Broken leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  delay(150);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  delay(150);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  delay(150);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  
  // Fragmented movement
  moveForward(80);
  delay(200);
  moveBackward(80);
  delay(200);
  moveForward(60);
  delay(400);
}

// Step 15: Rising from the fade
void faded_step15() {
  Serial.println("Faded Step 15: Rising from the fade");
  
  // Slow recovery movements
  for (int rise = 1; rise <= 5; rise++) {
    smoothMove(0, 90 - (rise * 6), 18 - rise);
    smoothMove(3, 90 + (rise * 6), 18 - rise);
    smoothMove(1, 45 - (rise * 2), 20 - rise);
    smoothMove(4, 135 + (rise * 2), 20 - rise);
    delay(600 - (rise * 80));
  }
  
  // Rising gesture
  smoothMove(2, 70, 12);
  smoothMove(5, 110, 12);
  delay(400);
  smoothMove(2, 50, 14);
  smoothMove(5, 130, 14);
  delay(500);
  
  // Standing stronger
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  
  // Rising movement
  moveForward(200);
  delay(500);
}

// Step 16: Third drop buildup
void faded_step16() {
  Serial.println("Faded Step 16: Third drop buildup");
  
  // Most intense buildup yet
  for (int massive_build = 1; massive_build <= 7; massive_build++) {
    int speed = 15 - (massive_build * 2);
    int amplitude = massive_build * 9;
    
    smoothMove(0, 90 - amplitude, speed);
    smoothMove(3, 90 + amplitude, speed);
    smoothMove(1, 45 - (massive_build * 4), speed);
    smoothMove(4, 135 + (massive_build * 4), speed);
    smoothMove(2, 90 - (massive_build * 6), speed);
    smoothMove(5, 90 + (massive_build * 6), speed);
    
    delay(350 - (massive_build * 35));
  }
  
  // Ultimate pre-drop position
  smoothMove(0, 25);
  smoothMove(3, 155);
  smoothMove(1, 15);
  smoothMove(4, 165);
  smoothMove(2, 40);
  smoothMove(5, 140);
  delay(400);
  
  // Ultimate tension legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  
  // Ultimate buildup movement
  moveBackward(400);
  delay(500);
}

// Step 17: Ultimate drop explosion
void faded_step17() {
  Serial.println("Faded Step 17: Ultimate drop explosion");
  
  // Most explosive drop sequence
  for (int ultimate = 0; ultimate < 12; ultimate++) {
    smoothMove(0, random(5, 175), 1);
    smoothMove(3, random(5, 175), 1);
    smoothMove(1, random(5, 175), 1);
    smoothMove(4, random(5, 175), 1);
    smoothMove(2, random(15, 165), 1);
    smoothMove(5, random(15, 165), 1);
    delay(90);
  }
  
  // Ultimate leg explosion
  for (int leg_ultimate = 0; leg_ultimate < 8; leg_ultimate++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(10, 32));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(10, 32));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(8, 26));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(8, 26));
    delay(120);
  }
  
  // Ultimate movement explosion
  for (int i = 0; i < 8; i++) {
    moveForward(60);
    moveBackward(60);
    delay(50);
  }
  delay(300);
}

// Step 18: Peak electronic energy
void faded_step18() {
  Serial.println("Faded Step 18: Peak electronic energy");
  
  // Sustained peak energy
  for (int peak = 0; peak < 10; peak++) {
    smoothMove(0, 25, 3);
    smoothMove(3, 155, 3);
    smoothMove(1, 15, 3);
    smoothMove(4, 165, 3);
    smoothMove(2, 30, 3);
    smoothMove(5, 150, 3);
    delay(140);
    
    smoothMove(0, 155, 3);
    smoothMove(3, 25, 3);
    smoothMove(1, 165, 3);
    smoothMove(4, 15, 3);
    smoothMove(2, 150, 3);
    smoothMove(5, 30, 3);
    delay(140);
  }
  
  // Peak leg choreography
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 22);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);
  delay(150);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 22);
  
  // Peak movement energy
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(180);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(180);
  stopBase();
  delay(200);
}

// Step 19: Faded climax hold
void faded_step19() {
  Serial.println("Faded Step 19: Faded climax hold");
  
  // Hold the emotional peak with faded theme
  smoothMove(0, 50, 25);
  smoothMove(3, 130, 25);
  smoothMove(1, 35, 25);
  smoothMove(4, 145, 25);
  smoothMove(2, 60, 25);
  smoothMove(5, 120, 25);
  delay(1000);
  
  // Faded trembling effect
  for (int tremble = 0; tremble < 8; tremble++) {
    smoothMove(0, 48, 3);
    smoothMove(3, 132, 3);
    delay(100);
    smoothMove(0, 52, 3);
    smoothMove(3, 128, 3);
    delay(100);
  }
  
  // Climax leg hold
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 14);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 14);
  
  delay(800);
}

// Step 20: Atmospheric breakdown
void faded_step20() {
  Serial.println("Faded Step 20: Atmospheric breakdown");
  
  // Atmospheric, floating breakdown
  for (int atmosphere = 6; atmosphere >= 1; atmosphere--) {
    int intensity = atmosphere * 8;
    int speed = 10 + (6 - atmosphere) * 3;
    
    smoothMove(0, 90 - intensity, speed);
    smoothMove(3, 90 + intensity, speed);
    smoothMove(1, 45 - (atmosphere * 3), speed);
    smoothMove(4, 135 + (atmosphere * 3), speed);
    delay(400 + (6 - atmosphere) * 150);
    
    // Ethereal pauses
    smoothMove(2, 90 - (intensity/2), speed + 5);
    smoothMove(5, 90 + (intensity/2), speed + 5);
    delay(300 + (6 - atmosphere) * 100);
  }
  
  // Final atmospheric gesture
  smoothMove(0, 85, 20);
  smoothMove(3, 95, 20);
  smoothMove(1, 50, 20);
  smoothMove(4, 130, 20);
  delay(700);
  
  // Breakdown legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  
  // Atmospheric drift
  moveForward(180);
  delay(600);
}

// Step 21: Echo effects
void faded_step21() {
  Serial.println("Faded Step 21: Echo effects");
  
  // Echo gesture sequence - repeating with diminishing intensity
  for (int echo = 4; echo >= 1; echo--) {
    int echo_intensity = echo * 12;
    int echo_speed = 20 - (echo * 3);
    
    // Main echo gesture
    smoothMove(0, 90 - echo_intensity, echo_speed);
    smoothMove(3, 90 + echo_intensity, echo_speed);
    delay(300 + (4 - echo) * 200);
    
    // Echo response
    smoothMove(1, 45 - (echo * 4), echo_speed + 2);
    smoothMove(4, 135 + (echo * 4), echo_speed + 2);
    delay(250 + (4 - echo) * 150);
    
    // Hand echo
    smoothMove(2, 90 - (echo * 6), echo_speed + 4);
    smoothMove(5, 90 + (echo * 6), echo_speed + 4);
    delay(200 + (4 - echo) * 100);
  }
  
  // Final echo fade
  smoothMove(0, 90, 25);
  smoothMove(3, 90, 25);
  smoothMove(1, 45, 25);
  smoothMove(4, 135, 25);
  smoothMove(2, 90, 25);
  smoothMove(5, 90, 25);
  delay(800);
  
  // Echo legs
  for (int leg_echo = 3; leg_echo >= 1; leg_echo--) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, 8 + (leg_echo * 3));
    pwmWriteAngle(LEG2_HIP_CHANNEL, 8 + (leg_echo * 3));
    delay(400 + (3 - leg_echo) * 200);
  }
  
  // Echo movement
  moveBackward(150);
  delay(500);
}

// Step 22: Vocal emphasis - Emotional return
void faded_step22() {
  Serial.println("Faded Step 22: Vocal emphasis - Emotional return");
  
  // Strong emotional vocal gestures
  smoothMove(0, 70, 14);
  smoothMove(3, 110, 14);
  smoothMove(1, 40, 14);
  smoothMove(4, 140, 14);
  delay(600);
  
  // Reaching out with emotion
  smoothMove(0, 55, 12);
  smoothMove(3, 125, 12);
  smoothMove(2, 125, 14);
  smoothMove(5, 55, 14);
  delay(500);
  
  // Emotional pull back
  smoothMove(0, 95, 16);
  smoothMove(3, 85, 16);
  smoothMove(2, 75, 18);
  smoothMove(5, 105, 18);
  delay(600);
  
  // Heart gesture
  smoothMove(0, 105, 12);
  smoothMove(3, 75, 12);
  smoothMove(1, 60, 12);
  smoothMove(4, 120, 12);
  delay(500);
  
  // Open wide - vulnerability
  smoothMove(0, 45, 16);
  smoothMove(3, 135, 16);
  smoothMove(2, 60, 18);
  smoothMove(5, 120, 18);
  delay(600);
  
  // Emotional leg stance
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  // Emotional forward movement
  moveForward(280);
  delay(500);
}

// Step 23: Final electronic surge
void faded_step23() {
  Serial.println("Faded Step 23: Final electronic surge");
  
  // Last major electronic burst with faded flavor
  for (int final_surge = 0; final_surge < 10; final_surge++) {
    smoothMove(0, random(30, 150), 3);
    smoothMove(3, random(30, 150), 3);
    smoothMove(1, random(25, 155), 3);
    smoothMove(4, random(25, 155), 3);
    smoothMove(2, random(40, 140), 3);
    smoothMove(5, random(40, 140), 3);
    delay(120);
  }
  
  // Final surge legs
  for (int leg_surge = 0; leg_surge < 6; leg_surge++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(14, 26));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(14, 26));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(10, 22));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(10, 22));
    delay(160);
  }
  
  // Final surge movement
  for (int i = 0; i < 6; i++) {
    moveForward(80);
    moveBackward(80);
    delay(90);
  }
  delay(300);
}

// Step 24: Fading away theme return
void faded_step24() {
  Serial.println("Faded Step 24: Fading away theme return");
  
  // Return to fading theme with resolution
  smoothMove(0, 80, 16);
  smoothMove(3, 100, 16);
  smoothMove(1, 50, 16);
  smoothMove(4, 130, 16);
  delay(600);
  
  // Gradual fade sequence
  for (int fade_return = 5; fade_return >= 1; fade_return--) {
    smoothMove(2, 90 - (fade_return * 6), 12 + fade_return);
    smoothMove(5, 90 + (fade_return * 6), 12 + fade_return);
    delay(400 + (5 - fade_return) * 150);
    
    smoothMove(2, 90 + (fade_return * 6), 12 + fade_return);
    smoothMove(5, 90 - (fade_return * 6), 12 + fade_return);
    delay(400 + (5 - fade_return) * 150);
  }
  
  // Final fade position
  smoothMove(0, 85, 20);
  smoothMove(3, 95, 20);
  smoothMove(2, 90, 20);
  smoothMove(5, 90, 20);
  delay(700);
  
  // Fading legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  
  // Fade away movement
  moveBackward(200);
  delay(600);
}

// Step 25: Emotional resolution
void faded_step25() {
  Serial.println("Faded Step 25: Emotional resolution");
  
  // Slow emotional resolution
  smoothMove(0, 75, 20);
  smoothMove(3, 105, 20);
  smoothMove(1, 45, 20);
  smoothMove(4, 135, 20);
  delay(800);
  
  // Acceptance gesture
  smoothMove(0, 90, 18);
  smoothMove(3, 90, 18);
  smoothMove(2, 110, 22);
  smoothMove(5, 70, 22);
  delay(700);
  
  // Peace gesture
  smoothMove(2, 80, 25);
  smoothMove(5, 100, 25);
  delay(800);
  
  // Final emotional sway
  for (int resolution = 0; resolution < 5; resolution++) {
    smoothMove(0, 82, 15);
    smoothMove(3, 98, 15);
    delay(500);
    smoothMove(0, 98, 15);
    smoothMove(3, 82, 15);
    delay(500);
  }
  
  // Resolution leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 6);
  
  // Peaceful movement
  moveForward(160);
  delay(700);
}

// Step 26: Atmospheric wind down
void faded_step26() {
  Serial.println("Faded Step 26: Atmospheric wind down");
  
  // Slow atmospheric wind down
  for (int wind_down = 6; wind_down >= 1; wind_down--) {
    int amplitude = wind_down * 6;
    int speed = 18 + (6 - wind_down) * 4;
    
    smoothMove(0, 90 - amplitude, speed);
    smoothMove(3, 90 + amplitude, speed);
    smoothMove(1, 45 - (wind_down * 2), speed);
    smoothMove(4, 135 + (wind_down * 2), speed);
    delay(500 + (6 - wind_down) * 200);
  }
  
  // Gentle atmospheric gestures
  smoothMove(2, 85, 25);
  smoothMove(5, 95, 25);
  delay(800);
  smoothMove(2, 95, 25);
  smoothMove(5, 85, 25);
  delay(800);
  
  // Wind down legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 5);
  
  // Gentle drift
  moveBackward(180);
  delay(700);
}

// Step 27: Ghostly finale approach
void faded_step27() {
  Serial.println("Faded Step 27: Ghostly finale approach");
  
  // Return to ghostly, ethereal movements
  smoothMove(0, 88, 25);
  smoothMove(3, 92, 25);
  smoothMove(1, 48, 25);
  smoothMove(4, 132, 25);
  delay(900);
  
  // Ghostly floating
  for (int ghost = 0; ghost < 4; ghost++) {
    smoothMove(2, 88, 20);
    smoothMove(5, 92, 20);
    delay(700);
    smoothMove(2, 92, 20);
    smoothMove(5, 88, 20);
    delay(700);
  }
  
  // Ethereal sway
  for (int ethereal = 0; ethereal < 3; ethereal++) {
    smoothMove(0, 85, 18);
    smoothMove(3, 95, 18);
    delay(600);
    smoothMove(0, 95, 18);
    smoothMove(3, 85, 18);
    delay(600);
  }
  
  // Ghostly leg position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 4);
  
  // Floating movement
  moveForward(120);
  delay(800);
}

// Step 28: Final fade sequence
void faded_step28() {
  Serial.println("Faded Step 28: Final fade sequence");
  
  // Ultimate fading sequence
  for (int ultimate_fade = 8; ultimate_fade >= 1; ultimate_fade--) {
    int fade_intensity = ultimate_fade * 3;
    int fade_speed = 25 + (8 - ultimate_fade) * 5;
    
    smoothMove(0, 90 - fade_intensity, fade_speed);
    smoothMove(3, 90 + fade_intensity, fade_speed);
    delay(600 + (8 - ultimate_fade) * 200);
    
    smoothMove(1, 45 - fade_intensity, fade_speed + 5);
    smoothMove(4, 135 + fade_intensity, fade_speed + 5);
    delay(500 + (8 - ultimate_fade) * 150);
  }
  
  // Final hand fade
  smoothMove(2, 90, 30);
  smoothMove(5, 90, 30);
  delay(1000);
  
  // Complete fade legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 4);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 4);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 3);
  
  // Final fade movement
  moveBackward(100);
  delay(800);
}

// Step 29: Almost gone
void faded_step29() {
  Serial.println("Faded Step 29: Almost gone");
  
  // Barely perceptible movements - almost faded away
  smoothMove(0, 89, 35);
  smoothMove(3, 91, 35);
  delay(1200);
  
  smoothMove(0, 91, 35);
  smoothMove(3, 89, 35);
  delay(1200);
  
  // Whisper movements
  smoothMove(1, 47, 30);
  smoothMove(4, 133, 30);
  delay(1000);
  
  smoothMove(1, 43, 30);
  smoothMove(4, 137, 30);
  delay(1000);
  
  // Final breath in hands
  smoothMove(2, 88, 40);
  smoothMove(5, 92, 40);
  delay(1500);
  smoothMove(2, 92, 40);
  smoothMove(5, 88, 40);
  delay(1500);
  
  // Almost gone legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 3);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 3);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 2);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 2);
  
  // Barely there movement
  moveForward(60);
  delay(1000);
}

// Step 30: Complete fade - Final pose
void faded_step30() {
  Serial.println("Faded Step 30: Complete fade - Final pose");
  
  // Final positioning - completely faded
  smoothMove(0, 90, 45);   // Extremely slow final fade
  smoothMove(3, 90, 45);
  smoothMove(1, 45, 45);
  smoothMove(4, 135, 45);
  smoothMove(2, 90, 45);
  smoothMove(5, 90, 45);
  delay(2000);
  
  // Final breathing effect - very subtle
  for (int final_breath = 0; final_breath < 3; final_breath++) {
    smoothMove(0, 89, 25);
    smoothMove(3, 91, 25);
    delay(800);
    smoothMove(0, 91, 25);
    smoothMove(3, 89, 25);
    delay(800);
  }
  
  // Complete stillness with micro movement
  for (int micro = 0; micro < 5; micro++) {
    smoothMove(2, 89, 20);
    delay(600);
    smoothMove(2, 91, 20);
    delay(600);
    smoothMove(5, 91, 20);
    delay(600);
    smoothMove(5, 89, 20);
    delay(600);
  }
  
  // Final rest position - completely faded
  pwmWriteAngle(LEG1_HIP_CHANNEL, 2);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 2);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 1);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 1);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 1);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 1);
  
  delay(2000);
  
  // Final fade message
  Serial.println("Faded complete - Lost in the memories, completely faded away...");
  delay(1000);
}

// Function to execute "Faded" dance steps
void executeFadedStep(int step) {
  switch (step) {
    case 1: faded_step1(); break;
    case 2: faded_step2(); break;
    case 3: faded_step3(); break;
    case 4: faded_step4(); break;
    case 5: faded_step5(); break;
    case 6: faded_step6(); break;
    case 7: faded_step7(); break;
    case 8: faded_step8(); break;
    case 9: faded_step9(); break;
    case 10: faded_step10(); break;
    case 11: faded_step11(); break;
    case 12: faded_step12(); break;
    case 13: faded_step13(); break;
    case 14: faded_step14(); break;
    case 15: faded_step15(); break;
    case 16: faded_step16(); break;
    case 17: faded_step17(); break;
    case 18: faded_step18(); break;
    case 19: faded_step19(); break;
    case 20: faded_step20(); break;
    case 21: faded_step21(); break;
    case 22: faded_step22(); break;
    case 23: faded_step23(); break;
    case 24: faded_step24(); break;
    case 25: faded_step25(); break;
    case 26: faded_step26(); break;
    case 27: faded_step27(); break;
    case 28: faded_step28(); break;
    case 29: faded_step29(); break;
    case 30: faded_step30(); break;
    
    default: 
      Serial.println("Unknown step - valid steps are 1-30 for 'Faded'"); 
      return;
  }
}

#endif
