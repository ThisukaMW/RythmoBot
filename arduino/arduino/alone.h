/*
 * =========================================================
 * ALONE - DANCE CHOREOGRAPHY HEADER FILE (UPDATED)
 * =========================================================
 * Contains all 38 dance steps for "Alone" by Marshmello
 * Each step is a complete choreographed movement sequence
 * Designed for electronic/EDM style with drops and builds
 * Updated with improved leg angles (all under 45 degrees)
 * =========================================================
 */

#ifndef ALONE_H
#define ALONE_H

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

// === ALONE - 38 DANCE STEPS ===

// Step 1: Intro atmospheric build
void alone_step1() {
  Serial.println("Alone Step 1: Intro atmospheric build");

  // Subtle electronic-style movements
  smoothMove(0, 90);  // Start neutral
  smoothMove(3, 90);
  smoothMove(1, 45);
  smoothMove(4, 135);
  delay(300);

  // Gentle robotic pulses
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 80);
    smoothMove(3, 100);
    delay(200);
    smoothMove(0, 100);
    smoothMove(3, 80);
    delay(200);
  }

  // Minimal leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 26);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 26);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 2);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 5);

  delay(500);
}

// Step 2: Electronic pulse build
void alone_step2() {
  Serial.println("Alone Step 2: Electronic pulse build");

  // Robotic arm pulses
  smoothMove(0, 70, 8);
  smoothMove(3, 110, 8);
  smoothMove(2, 60, 8);
  smoothMove(5, 120, 8);
  delay(250);

  smoothMove(0, 110, 8);
  smoothMove(3, 70, 8);
  smoothMove(2, 120, 8);
  smoothMove(5, 60, 8);
  delay(250);

  // Stutter movements
  for (int i = 0; i < 3; i++) {
    smoothMove(1, 30, 5);
    smoothMove(4, 150, 5);
    delay(100);
    smoothMove(1, 50, 5);
    smoothMove(4, 130, 5);
    delay(100);
  }

  // Building leg tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 5);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 6);

  moveForward(150);
  delay(300);
}

// Step 3: Synth melody entrance
void alone_step3() {
  Serial.println("Alone Step 3: Synth melody entrance");

  // Melodic arm waves
  smoothMove(0, 60);
  smoothMove(3, 120);
  smoothMove(1, 35);
  smoothMove(4, 145);
  delay(400);

  // Wave motion
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 45 + (i * 15));
    smoothMove(3, 135 - (i * 15));
    smoothMove(2, 80 + (i * 20));
    smoothMove(5, 100 - (i * 20));
    delay(300);
  }

  // Synth-style leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 8);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 8);

  // Side movement
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(200);
  stopBase();
  delay(400);
}

// Step 4: Pre-drop tension
void alone_step4() {
  Serial.println("Alone Step 4: Pre-drop tension");

  // Building tension movements
  smoothMove(0, 75);
  smoothMove(3, 105);
  smoothMove(1, 40);
  smoothMove(4, 140);
  delay(200);

  // Rapid alternating
  for (int i = 0; i < 5; i++) {
    smoothMove(0, 60, 6);
    smoothMove(3, 120, 6);
    delay(120);
    smoothMove(0, 120, 6);
    smoothMove(3, 60, 6);
    delay(120);
  }

  // Tension in legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 15);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 15);

  moveBackward(200);
  delay(300);
}

// Step 5: First drop preparation
void alone_step5() {
  Serial.println("Alone Step 5: First drop preparation");

  // Arms raising for drop
  smoothMove(0, 45, 12);
  smoothMove(3, 135, 12);
  smoothMove(1, 20, 12);
  smoothMove(4, 160, 12);
  smoothMove(2, 40, 12);
  smoothMove(5, 140, 12);
  delay(500);

  // Hold and build
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 40);
    smoothMove(3, 140);
    delay(150);
    smoothMove(0, 50);
    smoothMove(3, 130);
    delay(150);
  }

  // Ready stance
  pwmWriteAngle(LEG1_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);

  delay(400);
}

// Step 6: First drop explosion
void alone_step6() {
  Serial.println("Alone Step 6: First drop explosion");

  // Explosive drop movement
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 20, 3);
    smoothMove(3, 160, 3);
    smoothMove(1, 10, 3);
    smoothMove(4, 170, 3);
    smoothMove(2, 30, 3);
    smoothMove(5, 150, 3);
    delay(100);

    smoothMove(0, 160, 3);
    smoothMove(3, 20, 3);
    smoothMove(1, 170, 3);
    smoothMove(4, 10, 3);
    smoothMove(2, 150, 3);
    smoothMove(5, 30, 3);
    delay(100);
  }

  // Drop leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 35);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 35);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 25);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 25);

  // Rapid movement
  moveForward(120);
  moveBackward(120);
  delay(150);
}

// Step 7: Drop continuation
void alone_step7() {
  Serial.println("Alone Step 7: Drop continuation");

  // Sustained high energy
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 30 + random(-10, 10), 4);
    smoothMove(3, 150 + random(-10, 10), 4);
    smoothMove(1, 15 + random(-5, 15), 4);
    smoothMove(4, 165 + random(-15, 5), 4);
    delay(150);
  }

  // Electronic jerky movements
  smoothMove(2, 60, 3);
  delay(80);
  smoothMove(2, 120, 3);
  delay(80);
  smoothMove(5, 120, 3);
  delay(80);
  smoothMove(5, 60, 3);
  delay(80);

  // Alternating leg pattern
  pwmWriteAngle(LEG1_HIP_CHANNEL, 30);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  delay(150);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 30);

  delay(200);
}

// Step 8: Electronic breakdown
void alone_step8() {
  Serial.println("Alone Step 8: Electronic breakdown");

  // Stutter and glitch movements
  smoothMove(0, 90, 3);
  delay(100);
  smoothMove(0, 70, 3);
  delay(50);
  smoothMove(0, 110, 3);
  delay(50);
  smoothMove(0, 90, 3);
  delay(100);

  smoothMove(3, 90, 3);
  delay(100);
  smoothMove(3, 110, 3);
  delay(50);
  smoothMove(3, 70, 3);
  delay(50);
  smoothMove(3, 90, 3);
  delay(100);

  // Glitch arms
  for (int i = 0; i < 6; i++) {
    smoothMove(1, 40 + random(-20, 20), 2);
    smoothMove(4, 140 + random(-20, 20), 2);
    delay(80);
  }

  // Reset legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);

  delay(300);
}

// Step 9: Verse buildup
void alone_step9() {
  Serial.println("Alone Step 9: Verse buildup");

  // Smooth verse movements
  smoothMove(0, 80);
  smoothMove(3, 100);
  smoothMove(1, 50);
  smoothMove(4, 130);
  smoothMove(2, 110);
  smoothMove(5, 70);
  delay(400);

  // Alternating gestures
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 70 + (i * 10));
    smoothMove(3, 110 - (i * 10));
    delay(300);
    smoothMove(0, 110 - (i * 10));
    smoothMove(3, 70 + (i * 10));
    delay(300);
  }

  // Building leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);

  moveForward(180);
  delay(400);
}

// Step 10: Melodic section
void alone_step10() {
  Serial.println("Alone Step 10: Melodic section");

  // Flowing melodic movements
  smoothMove(0, 60, 15);
  smoothMove(3, 120, 15);
  smoothMove(1, 35, 15);
  smoothMove(4, 145, 15);
  delay(600);

  // Wave-like motion
  smoothMove(0, 45);
  smoothMove(3, 135);
  smoothMove(2, 70);
  smoothMove(5, 110);
  delay(400);

  smoothMove(0, 135);
  smoothMove(3, 45);
  smoothMove(2, 110);
  smoothMove(5, 70);
  delay(400);

  // Gentle leg sway
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  delay(300);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 22);
  delay(300);
}

// Step 11: Building intensity
void alone_step11() {
  Serial.println("Alone Step 11: Building intensity");

  // Gradual intensity increase
  for (int i = 1; i <= 4; i++) {
    smoothMove(0, 90 - (i * 15));
    smoothMove(3, 90 + (i * 15));
    smoothMove(1, 45 - (i * 8));
    smoothMove(4, 135 + (i * 8));
    delay(250 - (i * 30));
  }

  // Arm pumping
  for (int i = 0; i < 3; i++) {
    smoothMove(2, 50);
    smoothMove(5, 130);
    delay(200);
    smoothMove(2, 130);
    smoothMove(5, 50);
    delay(200);
  }

  // Building leg tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);

  // Side movement
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(250);
  stopBase();
  delay(200);
}

// Step 12: Pre-chorus tension
void alone_step12() {
  Serial.println("Alone Step 12: Pre-chorus tension");

  // Rising tension
  smoothMove(0, 50, 18);
  smoothMove(3, 130, 18);
  smoothMove(1, 25, 18);
  smoothMove(4, 155, 18);
  smoothMove(2, 45, 18);
  smoothMove(5, 135, 18);
  delay(700);

  // Tension holds with micro-movements
  for (int i = 0; i < 5; i++) {
    smoothMove(0, 48, 3);
    smoothMove(3, 132, 3);
    delay(120);
    smoothMove(0, 52, 3);
    smoothMove(3, 128, 3);
    delay(120);
  }

  // High tension legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 32);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 32);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 24);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 24);

  delay(400);
}

// Step 13: Second drop preparation
void alone_step13() {
  Serial.println("Alone Step 13: Second drop preparation");

  // Ultimate preparation
  smoothMove(0, 30);
  smoothMove(3, 150);
  smoothMove(1, 10);
  smoothMove(4, 170);
  smoothMove(2, 20);
  smoothMove(5, 160);
  delay(500);

  // Build-up pulses
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 25);
    smoothMove(3, 155);
    delay(100);
    smoothMove(0, 35);
    smoothMove(3, 145);
    delay(100);
  }

  // Maximum preparation
  pwmWriteAngle(LEG1_HIP_CHANNEL, 38);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 38);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 28);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 28);

  moveBackward(300);
  delay(300);
}

// Step 14: Second drop explosion
void alone_step14() {
  Serial.println("Alone Step 14: Second drop explosion");

  // Massive drop explosion
  for (int i = 0; i < 8; i++) {
    smoothMove(0, random(5, 175), 2);
    smoothMove(3, random(5, 175), 2);
    smoothMove(1, random(5, 175), 2);
    smoothMove(4, random(5, 175), 2);
    smoothMove(2, random(15, 165), 2);
    smoothMove(5, random(15, 165), 2);
    delay(80);
  }

  // Extreme leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 42);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 32);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  delay(120);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 42);

  // Frenzied movement
  for (int i = 0; i < 3; i++) {
    moveForward(100);
    moveBackward(100);
    delay(50);
  }
}

// Step 15: Drop continuation high energy
void alone_step15() {
  Serial.println("Alone Step 15: Drop continuation high energy");

  // Sustained chaos
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 25, 4);
    smoothMove(3, 155, 4);
    smoothMove(1, 10, 4);
    smoothMove(4, 170, 4);
    delay(120);

    smoothMove(0, 155, 4);
    smoothMove(3, 25, 4);
    smoothMove(1, 170, 4);
    smoothMove(4, 10, 4);
    delay(120);
  }

  // Complex arm patterns
  smoothMove(2, 40, 5);
  smoothMove(5, 140, 5);
  delay(100);
  smoothMove(2, 140, 5);
  smoothMove(5, 40, 5);
  delay(100);

  // Active legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 36);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 36);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 26);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 26);

  delay(200);
}

// Step 16: Electronic interlude
void alone_step16() {
  Serial.println("Alone Step 16: Electronic interlude");

  // Robotic, calculated movements
  smoothMove(0, 90, 8);
  smoothMove(3, 90, 8);
  delay(200);

  // Step-by-step robotic sequence
  smoothMove(0, 60, 8);
  delay(150);
  smoothMove(3, 120, 8);
  delay(150);
  smoothMove(1, 30, 8);
  delay(150);
  smoothMove(4, 150, 8);
  delay(150);

  // Mechanical arm movements
  smoothMove(2, 70, 10);
  delay(200);
  smoothMove(2, 110, 10);
  delay(200);
  smoothMove(5, 110, 10);
  delay(200);
  smoothMove(5, 70, 10);
  delay(200);

  // Precise leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 14);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 14);

  delay(300);
}

// Step 17: Synth melody return
void alone_step17() {
  Serial.println("Alone Step 17: Synth melody return");

  // Melodic flowing movements
  smoothMove(0, 75, 12);
  smoothMove(3, 105, 12);
  smoothMove(1, 45, 12);
  smoothMove(4, 135, 12);
  delay(500);

  // Smooth transitions
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 60 + (i * 10));
    smoothMove(3, 120 - (i * 10));
    smoothMove(2, 90 + (i * 15));
    smoothMove(5, 90 - (i * 15));
    delay(350);
  }

  // Flowing leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 24);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  delay(250);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 24);
  delay(250);

  moveForward(220);
  delay(400);
}

// Step 18: Building to bridge
void alone_step18() {
  Serial.println("Alone Step 18: Building to bridge");

  // Progressive building
  for (int i = 1; i <= 5; i++) {
    smoothMove(0, 90 - (i * 12));
    smoothMove(3, 90 + (i * 12));
    smoothMove(1, 45 - (i * 6));
    smoothMove(4, 135 + (i * 6));
    delay(200 - (i * 20));
  }

  // Rapid alternation
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 30, 5);
    smoothMove(3, 150, 5);
    delay(150);
    smoothMove(0, 150, 5);
    smoothMove(3, 30, 5);
    delay(150);
  }

  // Building leg intensity
  pwmWriteAngle(LEG1_HIP_CHANNEL, 30);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 30);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 22);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 22);

  // Building movement
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(200);
  stopBase();
  delay(200);
}

// Step 19: Bridge atmospheric
void alone_step19() {
  Serial.println("Alone Step 19: Bridge atmospheric");

  // Atmospheric, spacey movements
  smoothMove(0, 90, 20);
  smoothMove(3, 90, 20);
  smoothMove(1, 60, 20);
  smoothMove(4, 120, 20);
  smoothMove(2, 120, 20);
  smoothMove(5, 60, 20);
  delay(800);

  // Slow wave motion
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 70, 15);
    smoothMove(3, 110, 15);
    delay(400);
    smoothMove(0, 110, 15);
    smoothMove(3, 70, 15);
    delay(400);
  }

  // Minimal leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);

  delay(600);
}

// Step 20: Bridge buildup
void alone_step20() {
  Serial.println("Alone Step 20: Bridge buildup");

  // Gradual energy return
  smoothMove(0, 80);
  smoothMove(3, 100);
  smoothMove(1, 50);
  smoothMove(4, 130);
  delay(300);

  // Building movements
  for (int i = 1; i <= 3; i++) {
    smoothMove(0, 90 - (i * 15));
    smoothMove(3, 90 + (i * 15));
    smoothMove(2, 90 + (i * 20));
    smoothMove(5, 90 - (i * 20));
    delay(250);
  }

  // Increasing leg activity
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 16);

  moveBackward(200);
  delay(300);
}

// Step 21: Pre-final drop tension
void alone_step21() {
  Serial.println("Alone Step 21: Pre-final drop tension");

  // Maximum tension build
  smoothMove(0, 40, 20);
  smoothMove(3, 140, 20);
  smoothMove(1, 20, 20);
  smoothMove(4, 160, 20);
  smoothMove(2, 30, 20);
  smoothMove(5, 150, 20);
  delay(800);

  // Tension trembles
  for (int i = 0; i < 8; i++) {
    smoothMove(0, 38, 2);
    smoothMove(3, 142, 2);
    delay(80);
    smoothMove(0, 42, 2);
    smoothMove(3, 138, 2);
    delay(80);
  }

  // Ultimate leg tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 40);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 40);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 30);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 30);

  delay(500);
}

// Step 22: Final drop explosion
void alone_step22() {
  Serial.println("Alone Step 22: Final drop explosion");

  // Ultimate explosion
  for (int i = 0; i < 10; i++) {
    smoothMove(0, random(0, 180), 1);
    smoothMove(3, random(0, 180), 1);
    smoothMove(1, random(0, 180), 1);
    smoothMove(4, random(0, 180), 1);
    smoothMove(2, random(10, 170), 1);
    smoothMove(5, random(10, 170), 1);
    delay(60);
  }

  // Chaos leg movement
  for (int i = 0; i < 5; i++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(25, 44));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(25, 44));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(18, 35));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(18, 35));
    delay(100);
  }

  // Maximum movement chaos
  for (int i = 0; i < 4; i++) {
    moveForward(80);
    moveBackward(80);
    delay(30);
  }
}

// Step 23: Drop continuation peak
void alone_step23() {
  Serial.println("Alone Step 23: Drop continuation peak");

  // Sustained peak energy
  for (int i = 0; i < 8; i++) {
    smoothMove(0, 20, 3);
    smoothMove(3, 160, 3);
    smoothMove(1, 5, 3);
    smoothMove(4, 175, 3);
    delay(100);

    smoothMove(0, 160, 3);
    smoothMove(3, 20, 3);
    smoothMove(1, 175, 3);
    smoothMove(4, 5, 3);
    delay(100);
  }

  // Peak arm movements
  smoothMove(2, 20, 4);
  smoothMove(5, 160, 4);
  delay(150);
  smoothMove(2, 160, 4);
  smoothMove(5, 20, 4);
  delay(150);

  // Peak leg activity
  pwmWriteAngle(LEG1_HIP_CHANNEL, 38);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 32);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 28);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 24);

  // Intense movement
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(150);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(150);
  stopBase();
}

// Step 24: Electronic breakdown 2
void alone_step24() {
  Serial.println("Alone Step 24: Electronic breakdown 2");

  // Glitchy breakdown
  smoothMove(0, 90, 5);
  delay(100);
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 90 + random(-30, 30), 3);
    smoothMove(3, 90 + random(-30, 30), 3);
    delay(80);
  }

  // Stuttering arms
  for (int i = 0; i < 8; i++) {
    smoothMove(1, 40, 2);
    smoothMove(4, 140, 2);
    delay(60);
    smoothMove(1, 60, 2);
    smoothMove(4, 120, 2);
    delay(60);
  }

  // Broken leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  delay(100);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 26);
  delay(100);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  delay(100);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);

  delay(300);
}

// Step 25: Synth solo
void alone_step25() {
  Serial.println("Alone Step 25: Synth solo");

  // Expressive synth movements
  smoothMove(0, 60, 18);
  smoothMove(3, 120, 18);
  smoothMove(1, 30, 18);
  smoothMove(4, 150, 18);
  smoothMove(2, 60, 18);
  smoothMove(5, 120, 18);
  delay(700);

  // Solo expression
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 45 + (i * 15));
    smoothMove(3, 135 - (i * 15));
    smoothMove(2, 75 + (i * 20));
    smoothMove(5, 105 - (i * 20));
    delay(400);
  }

  // Expressive leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  delay(300);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  delay(300);

  moveForward(250);
  delay(400);
}

// Step 26: Building to final section
void alone_step26() {
  Serial.println("Alone Step 26: Building to final section");

  // Progressive intensity
  for (int i = 1; i <= 5; i++) {
    smoothMove(0, 90 - (i * 10));
    smoothMove(3, 90 + (i * 10));
    smoothMove(1, 45 - (i * 5));
    smoothMove(4, 135 + (i * 5));
    smoothMove(2, 90 + (i * 12));
    smoothMove(5, 90 - (i * 12));
    delay(200 - (i * 25));
  }

  // Rapid buildup
  for (int i = 0; i < 5; i++) {
    smoothMove(0, 40, 4);
    smoothMove(3, 140, 4);
    delay(120);
    smoothMove(0, 140, 4);
    smoothMove(3, 40, 4);
    delay(120);
  }

  // Building legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 34);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 34);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 26);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 26);

  moveBackward(280);
  delay(300);
}

// Step 27: Final chorus preparation
void alone_step27() {
  Serial.println("Alone Step 27: Final chorus preparation");

  // Ultimate preparation
  smoothMove(0, 30, 25);
  smoothMove(3, 150, 25);
  smoothMove(1, 10, 25);
  smoothMove(4, 170, 25);
  smoothMove(2, 20, 25);
  smoothMove(5, 160, 25);
  delay(1000);

  // Final preparation pulses
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 25, 3);
    smoothMove(3, 155, 3);
    delay(100);
    smoothMove(0, 35, 3);
    smoothMove(3, 145, 3);
    delay(100);
  }

  // Ultimate leg preparation
  pwmWriteAngle(LEG1_HIP_CHANNEL, 44);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 44);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 34);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 34);

  delay(400);
}

// Step 28: Final drop ultimate
void alone_step28() {
  Serial.println("Alone Step 28: Final drop ultimate");

  // Ultimate chaos
  for (int i = 0; i < 12; i++) {
    smoothMove(0, random(0, 180), 1);
    smoothMove(3, random(0, 180), 1);
    smoothMove(1, random(0, 180), 1);
    smoothMove(4, random(0, 180), 1);
    smoothMove(2, random(5, 175), 1);
    smoothMove(5, random(5, 175), 1);
    delay(50);
  }

  // Ultimate leg chaos
  for (int i = 0; i < 6; i++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(30, 44));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(30, 44));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(20, 35));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(20, 35));
    delay(80);
  }

  // Ultimate movement chaos
  for (int i = 0; i < 6; i++) {
    moveForward(60);
    moveBackward(60);
    delay(20);
  }
}

// Step 29: Sustained final energy
void alone_step29() {
  Serial.println("Alone Step 29: Sustained final energy");

  // Sustained maximum energy
  for (int i = 0; i < 10; i++) {
    smoothMove(0, 15, 2);
    smoothMove(3, 165, 2);
    smoothMove(1, 0, 2);
    smoothMove(4, 180, 2);
    delay(80);

    smoothMove(0, 165, 2);
    smoothMove(3, 15, 2);
    smoothMove(1, 180, 2);
    smoothMove(4, 0, 2);
    delay(80);
  }

  // Extreme arm patterns
  smoothMove(2, 10, 3);
  smoothMove(5, 170, 3);
  delay(100);
  smoothMove(2, 170, 3);
  smoothMove(5, 10, 3);
  delay(100);

  // Maximum leg energy
  pwmWriteAngle(LEG1_HIP_CHANNEL, 42);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 36);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 32);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 28);

  delay(200);
}

// Step 30: Peak climax hold
void alone_step30() {
  Serial.println("Alone Step 30: Peak climax hold");

  // Hold peak position
  smoothMove(0, 30, 30);
  smoothMove(3, 150, 30);
  smoothMove(1, 10, 30);
  smoothMove(4, 170, 30);
  smoothMove(2, 25, 30);
  smoothMove(5, 155, 30);
  delay(1200);

  // Peak trembling
  for (int i = 0; i < 12; i++) {
    smoothMove(0, 28, 1);
    smoothMove(3, 152, 1);
    delay(60);
    smoothMove(0, 32, 1);
    smoothMove(3, 148, 1);
    delay(60);
  }

  // Climax leg hold
  pwmWriteAngle(LEG1_HIP_CHANNEL, 40);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 40);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 30);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 30);

  delay(800);
}

// Step 31: Energy release
void alone_step31() {
  Serial.println("Alone Step 31: Energy release");

  // Energy release movements
  for (int i = 5; i >= 1; i--) {
    smoothMove(0, 30 + (i * 20));
    smoothMove(3, 150 - (i * 20));
    smoothMove(1, 10 + (i * 15));
    smoothMove(4, 170 - (i * 15));
    delay(150 + (5 - i) * 50);
  }

  // Gradual arm lowering
  smoothMove(2, 80, 15);
  smoothMove(5, 100, 15);
  delay(500);

  // Energy release in legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);

  moveForward(200);
  delay(400);
}

// Step 32: Outro beginning
void alone_step32() {
  Serial.println("Alone Step 32: Outro beginning");

  // Outro movements
  smoothMove(0, 80, 20);
  smoothMove(3, 100, 20);
  smoothMove(1, 50, 20);
  smoothMove(4, 130, 20);
  smoothMove(2, 110, 20);
  smoothMove(5, 70, 20);
  delay(800);

  // Gentle outro sway
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 75);
    smoothMove(3, 105);
    delay(350);
    smoothMove(0, 105);
    smoothMove(3, 75);
    delay(350);
  }

  // Settling legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 16);

  delay(500);
}

// Step 33: Melodic outro
void alone_step33() {
  Serial.println("Alone Step 33: Melodic outro");

  // Melodic outro movements
  smoothMove(0, 70, 18);
  smoothMove(3, 110, 18);
  smoothMove(1, 40, 18);
  smoothMove(4, 140, 18);
  delay(700);

  // Soft melodic waves
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 60 + (i * 5));
    smoothMove(3, 120 - (i * 5));
    smoothMove(2, 100 + (i * 10));
    smoothMove(5, 80 - (i * 10));
    delay(500);
  }

  // Gentle leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  delay(300);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  delay(300);

  moveBackward(150);
  delay(600);
}

// Step 34: Atmospheric fade
void alone_step34() {
  Serial.println("Alone Step 34: Atmospheric fade");

  // Atmospheric movements
  smoothMove(0, 85, 25);
  smoothMove(3, 95, 25);
  smoothMove(1, 55, 25);
  smoothMove(4, 125, 25);
  smoothMove(2, 120, 25);
  smoothMove(5, 60, 25);
  delay(1000);

  // Slow breathing motion
  for (int i = 0; i < 5; i++) {
    smoothMove(0, 82, 12);
    smoothMove(3, 98, 12);
    delay(400);
    smoothMove(0, 88, 12);
    smoothMove(3, 92, 12);
    delay(400);
  }

  // Minimal leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);

  delay(700);
}

// Step 35: Gentle resolution
void alone_step35() {
  Serial.println("Alone Step 35: Gentle resolution");

  // Gentle resolving movements
  smoothMove(0, 90, 30);
  smoothMove(3, 90, 30);
  smoothMove(1, 60, 30);
  smoothMove(4, 120, 30);
  smoothMove(2, 105, 30);
  smoothMove(5, 75, 30);
  delay(1200);

  // Soft final waves
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 85);
    smoothMove(3, 95);
    delay(450);
    smoothMove(0, 95);
    smoothMove(3, 85);
    delay(450);
  }

  // Final leg settling
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 6);

  moveForward(100);
  delay(800);
}

// Step 36: Pre-final pose
void alone_step36() {
  Serial.println("Alone Step 36: Pre-final pose");

  // Preparation for final pose
  smoothMove(0, 85, 35);
  smoothMove(3, 95, 35);
  smoothMove(1, 65, 35);
  smoothMove(4, 115, 35);
  smoothMove(2, 95, 35);
  smoothMove(5, 85, 35);
  delay(1400);

  // Subtle final adjustments
  smoothMove(0, 80, 15);
  smoothMove(3, 100, 15);
  delay(600);

  // Final leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 3);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 3);

  delay(600);
}

// Step 37: Final emotional pose
void alone_step37() {
  Serial.println("Alone Step 37: Final emotional pose");

  // Final emotional gesture
  smoothMove(0, 75, 40);
  smoothMove(3, 105, 40);
  smoothMove(1, 70, 40);
  smoothMove(4, 110, 40);
  smoothMove(2, 90, 40);
  smoothMove(5, 90, 40);
  delay(1600);

  // Hold with subtle breathing
  for (int i = 0; i < 8; i++) {
    smoothMove(0, 73, 8);
    smoothMove(3, 107, 8);
    delay(300);
    smoothMove(0, 77, 8);
    smoothMove(3, 103, 8);
    delay(300);
  }

  // Final leg hold
  pwmWriteAngle(LEG1_HIP_CHANNEL, 4);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 4);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 2);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 2);

  delay(1000);
}

// Step 38: Complete silence and fade
void alone_step38() {
  Serial.println("Alone Step 38: Complete silence and fade");

  // Final silence pose
  smoothMove(0, 90, 50);
  smoothMove(3, 90, 50);
  smoothMove(1, 90, 50);
  smoothMove(4, 90, 50);
  smoothMove(2, 90, 50);
  smoothMove(5, 90, 50);
  delay(2000);

  // Final micro-movements
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 88, 20);
    smoothMove(3, 92, 20);
    delay(500);
    smoothMove(0, 92, 20);
    smoothMove(3, 88, 20);
    delay(500);
  }

  // Complete rest position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 0);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 0);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 0);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 0);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 0);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 0);

  delay(1500);

  // Song complete message
  Serial.println("'Alone' dance sequence complete - preparing to return to home position");
  delay(500);
}

// Function to execute "Alone" dance steps
void executeAloneStep(int step) {
  switch (step) {
    case 1: alone_step1(); break;
    case 2: alone_step2(); break;
    case 3: alone_step3(); break;
    case 4: alone_step4(); break;
    case 5: alone_step5(); break;
    case 6: alone_step6(); break;
    case 7: alone_step7(); break;
    case 8: alone_step8(); break;
    case 9: alone_step9(); break;
    case 10: alone_step10(); break;
    case 11: alone_step11(); break;
    case 12: alone_step12(); break;
    case 13: alone_step13(); break;
    case 14: alone_step14(); break;
    case 15: alone_step15(); break;
    case 16: alone_step16(); break;
    case 17: alone_step17(); break;
    case 18: alone_step18(); break;
    case 19: alone_step19(); break;
    case 20: alone_step20(); break;
    case 21: alone_step21(); break;
    case 22: alone_step22(); break;
    case 23: alone_step23(); break;
    case 24: alone_step24(); break;
    case 25: alone_step25(); break;
    case 26: alone_step26(); break;
    case 27: alone_step27(); break;
    case 28: alone_step28(); break;
    case 29: alone_step29(); break;
    case 30: alone_step30(); break;
    case 31: alone_step31(); break;
    case 32: alone_step32(); break;
    case 33: alone_step33(); break;
    case 34: alone_step34(); break;
    case 35: alone_step35(); break;
    case 36: alone_step36(); break;
    case 37: alone_step37(); break;
    case 38: alone_step38(); break;

    default:
      Serial.println("Unknown step - valid steps are 1-38 for 'Alone'");
      return;
  }
}

#endif
