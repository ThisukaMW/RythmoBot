/*
 * =========================================================
 * TITANIUM - DANCE CHOREOGRAPHY HEADER FILE
 * =========================================================
 * Contains all 30 dance steps for "Titanium" by David Guetta ft. Sia
 * Each step is a complete choreographed movement sequence
 * Powerful, uplifting electronic style with strength themes
 * =========================================================
 */

#ifndef OTHER_H
#define OTHER_H

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

// === TITANIUM - 30 DANCE STEPS ===

// Step 1: Gentle intro - Building strength
void titanium_step1() {
  Serial.println("Titanium Step 1: Gentle intro - Building strength");
  
  // Gentle, growing movements
  smoothMove(0, 90, 18);   // Centered start
  smoothMove(3, 90, 18);
  smoothMove(1, 45, 18);
  smoothMove(4, 135, 18);
  delay(700);
  
  // Subtle strength building
  smoothMove(0, 85, 16);
  smoothMove(3, 95, 16);
  smoothMove(2, 100, 20);
  smoothMove(5, 80, 20);
  delay(600);
  
  // Growing confidence
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 90 - (i * 2), 15);
    smoothMove(3, 90 + (i * 2), 15);
    delay(400);
  }
  
  // Strong foundation legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 4);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 4);
  
  // Forward momentum
  moveForward(180);
  delay(600);
}

// Step 2: First verse - Vulnerable but growing
void titanium_step2() {
  Serial.println("Titanium Step 2: First verse - Vulnerable but growing");
  
  // Vulnerable opening gestures
  smoothMove(0, 75, 16);
  smoothMove(3, 105, 16);
  smoothMove(1, 40, 16);
  smoothMove(4, 140, 16);
  delay(600);
  
  // Protective stance
  smoothMove(0, 95, 14);
  smoothMove(3, 85, 14);
  smoothMove(2, 120, 16);
  smoothMove(5, 60, 16);
  delay(500);
  
  // Building inner strength
  smoothMove(0, 80, 12);
  smoothMove(3, 100, 12);
  smoothMove(1, 50, 12);
  smoothMove(4, 130, 12);
  delay(400);
  
  // Stance of growing confidence
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 7);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 7);
  
  // Cautious but forward movement
  moveForward(160);
  delay(500);
}

// Step 3: "You shout it out" - Defiant response
void titanium_step3() {
  Serial.println("Titanium Step 3: You shout it out - Defiant response");
  
  // Defiant arm positions
  smoothMove(0, 70, 12);
  smoothMove(3, 110, 12);
  smoothMove(1, 35, 12);
  smoothMove(4, 145, 12);
  delay(500);
  
  // Strong response gesture
  smoothMove(0, 60, 10);
  smoothMove(3, 120, 10);
  smoothMove(2, 130, 12);
  smoothMove(5, 50, 12);
  delay(400);
  
  // Standing ground
  smoothMove(0, 90, 14);
  smoothMove(3, 90, 14);
  smoothMove(2, 90, 14);
  smoothMove(5, 90, 14);
  delay(300);
  
  // Strong defensive legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 9);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 9);
  
  // Stand firm
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(200);
  stopBase();
  delay(400);
}

// Step 4: Building verse - Growing resilience
void titanium_step4() {
  Serial.println("Titanium Step 4: Building verse - Growing resilience");
  
  // Resilience building movements
  for (int resilience = 1; resilience <= 5; resilience++) {
    smoothMove(0, 90 - (resilience * 4), 16 - resilience);
    smoothMove(3, 90 + (resilience * 4), 16 - resilience);
    smoothMove(1, 45 - (resilience * 2), 16 - resilience);
    smoothMove(4, 135 + (resilience * 2), 16 - resilience);
    delay(500 - (resilience * 60));
  }
  
  // Strong wave motion
  smoothMove(2, 70, 14);
  smoothMove(5, 110, 14);
  delay(500);
  smoothMove(2, 110, 14);
  smoothMove(5, 70, 14);
  delay(500);
  
  // Building strength in legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  
  // Forward with purpose
  moveForward(220);
  delay(500);
}

// Step 5: Pre-chorus buildup - "I'm bulletproof"
void titanium_step5() {
  Serial.println("Titanium Step 5: Pre-chorus buildup - I'm bulletproof");
  
  // Bulletproof stance building
  smoothMove(0, 65, 14);
  smoothMove(3, 115, 14);
  smoothMove(1, 30, 14);
  smoothMove(4, 150, 14);
  delay(600);
  
  // Shield gestures
  smoothMove(0, 50, 12);
  smoothMove(3, 130, 12);
  smoothMove(2, 120, 14);
  smoothMove(5, 60, 14);
  delay(500);
  
  // Nothing can touch me
  smoothMove(0, 45, 10);
  smoothMove(3, 135, 10);
  smoothMove(1, 25, 10);
  smoothMove(4, 155, 10);
  delay(400);
  
  // Bulletproof legs - strong stance
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  // Powerful forward movement
  moveForward(280);
  delay(400);
}

// Step 6: Chorus explosion - "I am titanium!"
void titanium_step6() {
  Serial.println("Titanium Step 6: Chorus explosion - I am titanium!");
  
  // Explosive titanium declaration
  smoothMove(0, 30, 8);
  smoothMove(3, 150, 8);
  smoothMove(1, 20, 8);
  smoothMove(4, 160, 8);
  smoothMove(2, 40, 8);
  smoothMove(5, 140, 8);
  delay(400);
  
  // Titanium power surge
  for (int power = 0; power < 6; power++) {
    smoothMove(0, 150, 5);
    smoothMove(3, 30, 5);
    delay(150);
    smoothMove(0, 30, 5);
    smoothMove(3, 150, 5);
    delay(150);
  }
  
  // Strong titanium gestures
  smoothMove(1, 15, 6);
  smoothMove(4, 165, 6);
  smoothMove(2, 30, 6);
  smoothMove(5, 150, 6);
  delay(300);
  
  // Titanium legs - maximum strength
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 16);
  
  // Powerful titanium movement
  for (int i = 0; i < 4; i++) {
    moveForward(100);
    moveBackward(100);
    delay(100);
  }
  delay(300);
}

// Step 7: Titanium strength display
void titanium_step7() {
  Serial.println("Titanium Step 7: Titanium strength display");
  
  // Display of unbreakable strength
  smoothMove(0, 45, 10);
  smoothMove(3, 135, 10);
  smoothMove(1, 30, 10);
  smoothMove(4, 150, 10);
  delay(500);
  
  // Flexing titanium power
  for (int flex = 0; flex < 5; flex++) {
    smoothMove(2, 60, 8);
    smoothMove(5, 120, 8);
    delay(200);
    smoothMove(2, 120, 8);
    smoothMove(5, 60, 8);
    delay(200);
  }
  
  // Unbreakable stance
  smoothMove(0, 50, 12);
  smoothMove(3, 130, 12);
  smoothMove(1, 35, 12);
  smoothMove(4, 145, 12);
  delay(600);
  
  // Strong titanium legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 14);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 14);
  
  // Confident movement
  moveForward(250);
  delay(500);
}

// Step 8: Electronic interlude - Titanium shimmer
void titanium_step8() {
  Serial.println("Titanium Step 8: Electronic interlude - Titanium shimmer");
  
  // Shimmering titanium effects
  for (int shimmer = 0; shimmer < 8; shimmer++) {
    smoothMove(0, 60 + (shimmer % 2 ? 10 : -10), 6);
    smoothMove(3, 120 + (shimmer % 2 ? -10 : 10), 6);
    smoothMove(1, 40 + (shimmer % 2 ? 5 : -5), 6);
    smoothMove(4, 140 + (shimmer % 2 ? -5 : 5), 6);
    delay(180);
  }
  
  // Metallic wave effects
  smoothMove(2, 50, 12);
  smoothMove(5, 130, 12);
  delay(400);
  smoothMove(2, 130, 12);
  smoothMove(5, 50, 12);
  delay(400);
  
  // Electronic pulse legs
  for (int pulse = 0; pulse < 4; pulse++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, 15);
    pwmWriteAngle(LEG2_HIP_CHANNEL, 19);
    delay(200);
    pwmWriteAngle(LEG1_HIP_CHANNEL, 19);
    pwmWriteAngle(LEG2_HIP_CHANNEL, 15);
    delay(200);
  }
  
  // Shimmer movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(250);
  stopBase();
  delay(350);
}

// Step 9: Second verse - Stronger foundation
void titanium_step9() {
  Serial.println("Titanium Step 9: Second verse - Stronger foundation");
  
  // Stronger, more confident movements
  smoothMove(0, 70, 14);
  smoothMove(3, 110, 14);
  smoothMove(1, 40, 14);
  smoothMove(4, 140, 14);
  delay(600);
  
  // Showing resilience
  smoothMove(0, 80, 12);
  smoothMove(3, 100, 12);
  smoothMove(2, 110, 14);
  smoothMove(5, 70, 14);
  delay(500);
  
  // Confident gestures
  smoothMove(0, 65, 10);
  smoothMove(3, 115, 10);
  smoothMove(1, 35, 10);
  smoothMove(4, 145, 10);
  delay(400);
  
  // Stronger foundation legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  // Confident forward movement
  moveForward(200);
  delay(500);
}

// Step 10: Building to second chorus
void titanium_step10() {
  Serial.println("Titanium Step 10: Building to second chorus");
  
  // Intensifying build with more confidence
  for (int build = 1; build <= 6; build++) {
    smoothMove(0, 90 - (build * 6), 14 - build);
    smoothMove(3, 90 + (build * 6), 14 - build);
    smoothMove(1, 45 - (build * 3), 14 - build);
    smoothMove(4, 135 + (build * 3), 14 - build);
    smoothMove(2, 90 - (build * 4), 16 - build);
    smoothMove(5, 90 + (build * 4), 16 - build);
    delay(400 - (build * 40));
  }
  
  // Pre-second chorus power
  smoothMove(0, 40, 8);
  smoothMove(3, 140, 8);
  smoothMove(1, 25, 8);
  smoothMove(4, 155, 8);
  delay(400);
  
  // Maximum build legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);
  
  // Power build movement
  moveBackward(320);
  delay(400);
}

// Step 11: Second chorus - Even more powerful
void titanium_step11() {
  Serial.println("Titanium Step 11: Second chorus - Even more powerful");
  
  // More powerful titanium explosion
  for (int explosion = 0; explosion < 8; explosion++) {
    smoothMove(0, random(20, 160), 4);
    smoothMove(3, random(20, 160), 4);
    smoothMove(1, random(15, 165), 4);
    smoothMove(4, random(15, 165), 4);
    smoothMove(2, random(30, 150), 4);
    smoothMove(5, random(30, 150), 4);
    delay(140);
  }
  
  // Titanium dominance
  smoothMove(0, 25, 6);
  smoothMove(3, 155, 6);
  smoothMove(1, 15, 6);
  smoothMove(4, 165, 6);
  delay(300);
  
  // Powerful leg choreography
  pwmWriteAngle(LEG1_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 16);
  delay(200);
  
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 25);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  
  // Dominant movement
  for (int i = 0; i < 6; i++) {
    moveForward(90);
    moveBackward(90);
    delay(90);
  }
  delay(250);
}

// Step 12: Titanium theme variation
void titanium_step12() {
  Serial.println("Titanium Step 12: Titanium theme variation");
  
  // Variations on titanium strength
  smoothMove(0, 55, 10);
  smoothMove(3, 125, 10);
  smoothMove(1, 40, 10);
  smoothMove(4, 140, 10);
  delay(500);
  
  // Metallic flow movements
  for (int flow = 0; flow < 6; flow++) {
    smoothMove(2, 70 + (flow % 2 ? 20 : 0), 8);
    smoothMove(5, 110 - (flow % 2 ? 20 : 0), 8);
    delay(250);
  }
  
  // Titanium resilience display
  smoothMove(0, 45, 12);
  smoothMove(3, 135, 12);
  smoothMove(1, 30, 12);
  smoothMove(4, 150, 12);
  delay(600);
  
  // Resilient legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 14);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 14);
  
  // Flowing titanium movement
  moveForward(240);
  delay(500);
}

// Step 13: Bridge section - Inner strength
void titanium_step13() {
  Serial.println("Titanium Step 13: Bridge section - Inner strength");
  
  // Inner strength visualization
  smoothMove(0, 90, 16);
  smoothMove(3, 90, 16);
  smoothMove(1, 45, 16);
  smoothMove(4, 135, 16);
  delay(700);
  
  // Heart of titanium
  smoothMove(0, 105, 14);
  smoothMove(3, 75, 14);
  smoothMove(2, 120, 16);
  smoothMove(5, 60, 16);
  delay(600);
  
  // Expanding inner power
  for (int expand = 1; expand <= 4; expand++) {
    smoothMove(0, 90 - (expand * 8), 12);
    smoothMove(3, 90 + (expand * 8), 12);
    delay(400);
  }
  
  // Core strength
  smoothMove(2, 80, 18);
  smoothMove(5, 100, 18);
  delay(700);
  
  // Inner strength legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  
  // Centered movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(300);
  stopBase();
  delay(500);
}

// Step 14: Electronic breakdown - Titanium fragments
void titanium_step14() {
  Serial.println("Titanium Step 14: Electronic breakdown - Titanium fragments");
  
  // Titanium fragmentation effects
  for (int fragment = 0; fragment < 10; fragment++) {
    smoothMove(0, random(40, 140), 3);
    smoothMove(3, random(40, 140), 3);
    smoothMove(1, random(30, 150), 3);
    smoothMove(4, random(30, 150), 3);
    delay(120);
  }
  
  // Reassembling titanium strength
  smoothMove(0, 60, 8);
  smoothMove(3, 120, 8);
  smoothMove(1, 45, 8);
  smoothMove(4, 135, 8);
  delay(400);
  
  // Fragment dance with hands
  for (int hand_frag = 0; hand_frag < 5; hand_frag++) {
    smoothMove(2, random(50, 130), 4);
    smoothMove(5, random(50, 130), 4);
    delay(150);
  }
  
  // Fragmented legs
  for (int leg_frag = 0; leg_frag < 4; leg_frag++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(10, 20));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(10, 20));
    delay(180);
  }
  
  // Fragmented movement
  moveForward(100);
  moveBackward(120);
  moveForward(80);
  delay(400);
}

// Step 15: Rebuilding strength
void titanium_step15() {
  Serial.println("Titanium Step 15: Rebuilding strength");
  
  // Systematic rebuilding of strength
  for (int rebuild = 1; rebuild <= 5; rebuild++) {
    smoothMove(0, 90 - (rebuild * 5), 16 - rebuild);
    smoothMove(3, 90 + (rebuild * 5), 16 - rebuild);
    smoothMove(1, 45 - (rebuild * 3), 16 - rebuild);
    smoothMove(4, 135 + (rebuild * 3), 16 - rebuild);
    delay(500 - (rebuild * 60));
  }
  
  // Strength reconstruction
  smoothMove(2, 70, 12);
  smoothMove(5, 110, 12);
  delay(500);
  smoothMove(2, 110, 12);
  smoothMove(5, 70, 12);
  delay(500);
  
  // Rebuilt stance
  smoothMove(0, 65, 14);
  smoothMove(3, 115, 14);
  delay(600);
  
  // Rebuilding legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  // Strong rebuilding movement
  moveForward(260);
  delay(500);
}

// Step 16: Third chorus buildup
void titanium_step16() {
  Serial.println("Titanium Step 16: Third chorus buildup");
  
  // Most intense buildup - ultimate titanium preparation
  for (int ultimate = 1; ultimate <= 7; ultimate++) {
    int intensity = ultimate * 8;
    int speed = 16 - (ultimate * 2);
    
    smoothMove(0, 90 - intensity, speed);
    smoothMove(3, 90 + intensity, speed);
    smoothMove(1, 45 - (ultimate * 4), speed);
    smoothMove(4, 135 + (ultimate * 4), speed);
    smoothMove(2, 90 - (ultimate * 5), speed);
    smoothMove(5, 90 + (ultimate * 5), speed);
    
    delay(350 - (ultimate * 35));
  }
  
  // Ultimate titanium pre-position
  smoothMove(0, 20, 6);
  smoothMove(3, 160, 6);
  smoothMove(1, 10, 6);
  smoothMove(4, 170, 6);
  smoothMove(2, 25, 6);
  smoothMove(5, 155, 6);
  delay(500);
  
  // Ultimate strength legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 28);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 22);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 22);
  
  // Ultimate buildup movement
  moveBackward(450);
  delay(500);
}

// Step 17: Ultimate titanium chorus
void titanium_step17() {
  Serial.println("Titanium Step 17: Ultimate titanium chorus");
  
  // Ultimate titanium explosion - most powerful yet
  for (int ultimate = 0; ultimate < 12; ultimate++) {
    smoothMove(0, random(10, 170), 2);
    smoothMove(3, random(10, 170), 2);
    smoothMove(1, random(5, 175), 2);
    smoothMove(4, random(5, 175), 2);
    smoothMove(2, random(20, 160), 2);
    smoothMove(5, random(20, 160), 2);
    delay(100);
  }
  
  // Ultimate titanium dominance
  smoothMove(0, 15, 4);
  smoothMove(3, 165, 4);
  smoothMove(1, 5, 4);
  smoothMove(4, 175, 4);
  delay(300);
  
  // Ultimate leg power
  for (int leg_power = 0; leg_power < 6; leg_power++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(20, 35));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(20, 35));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(16, 28));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(16, 28));
    delay(130);
  }
  
  // Ultimate power movement
  for (int i = 0; i < 8; i++) {
    moveForward(70);
    moveBackward(70);
    delay(60);
  }
  delay(350);
}

// Step 18: Titanium supremacy
void titanium_step18() {
  Serial.println("Titanium Step 18: Titanium supremacy");
  
  // Display of complete titanium supremacy
  smoothMove(0, 25, 6);
  smoothMove(3, 155, 6);
  smoothMove(1, 15, 6);
  smoothMove(4, 165, 6);
  smoothMove(2, 30, 6);
  smoothMove(5, 150, 6);
  delay(500);
  
  // Supremacy gestures
  for (int supreme = 0; supreme < 6; supreme++) {
    smoothMove(0, 155, 4);
    smoothMove(3, 25, 4);
    delay(160);
    smoothMove(0, 25, 4);
    smoothMove(3, 155, 4);
    delay(160);
  }
  
  // Victory stance
  smoothMove(1, 20, 8);
  smoothMove(4, 160, 8);
  smoothMove(2, 40, 8);
  smoothMove(5, 140, 8);
  delay(600);
  
  // Supreme legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 30);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 26);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 24);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  
  // Victory movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(300);
  stopBase();
  delay(400);
}

// Function to execute "Stereo Love" dance steps
void executeOtherStep(int step) {
  switch (step) {
    case 1: titanium_step1(); break;
    case 2: titanium_step2(); break;
    case 3: titanium_step3(); break;
    case 4: titanium_step4(); break;
    case 5: titanium_step5(); break;
    case 6: titanium_step6(); break;
    case 7: titanium_step7(); break;
    case 8: titanium_step8(); break;
    case 9: titanium_step9(); break;
    case 10: titanium_step10(); break;
    case 11: titanium_step11(); break;
    case 12: titanium_step12(); break;
    case 13: titanium_step13(); break;
    case 14: titanium_step14(); break;
    case 15: titanium_step15(); break;
    case 16: titanium_step16(); break;
    case 17: titanium_step17(); break;
    case 18: titanium_step18(); break;
    default: 
      Serial.println("Unknown step - valid steps are 1-18 for 'any song'"); 
      return;
  }
}
#endif
