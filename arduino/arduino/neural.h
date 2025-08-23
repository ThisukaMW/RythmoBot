/*
 * =========================================================
 * NEURAL THREADS - DANCE CHOREOGRAPHY HEADER FILE
 * =========================================================
 * Contains all 35 dance steps for "Neural Threads" beat
 * Each step is a complete choreographed movement sequence
 * Designed for cyberpunk/neural network inspired movements
 * =========================================================
 */

#ifndef NEURAL_H
#define NEURAL_H

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

// === NEURAL THREADS - 35 DANCE STEPS ===

// Step 1: System boot sequence
void neural_step1() {
  Serial.println("Neural Step 1: System boot sequence");
  
  // Robotic initialization movements
  smoothMove(0, 90, 3);   // Precise, mechanical start
  delay(150);
  smoothMove(3, 90, 3);
  delay(150);
  smoothMove(1, 90, 3);
  delay(150);
  smoothMove(4, 90, 3);
  delay(150);
  smoothMove(2, 90, 3);
  delay(150);
  smoothMove(5, 90, 3);
  delay(150);
  
  // System check movements
  smoothMove(0, 80, 5);
  smoothMove(3, 100, 5);
  delay(200);
  smoothMove(0, 100, 5);
  smoothMove(3, 80, 5);
  delay(200);
  
  // Boot leg positioning
  pwmWriteAngle(LEG1_HIP_CHANNEL, 2);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 2);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 1);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 1);
  
  delay(400);
}

// Step 2: Neural network activation
void neural_step2() {
  Serial.println("Neural Step 2: Neural network activation");
  
  // Network firing patterns
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 75, 4);
    smoothMove(1, 45, 4);
    delay(80);
    smoothMove(3, 105, 4);
    smoothMove(4, 135, 4);
    delay(80);
    smoothMove(2, 60, 4);
    delay(80);
    smoothMove(5, 120, 4);
    delay(80);
  }
  
  // Reset to neutral
  smoothMove(0, 90, 6);
  smoothMove(3, 90, 6);
  smoothMove(1, 90, 6);
  smoothMove(4, 90, 6);
  smoothMove(2, 90, 6);
  smoothMove(5, 90, 6);
  
  // Neural leg pattern
  pwmWriteAngle(LEG1_HIP_CHANNEL, 4);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 4);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 3);
  
  delay(300);
}

// Step 3: Data flow initialization
void neural_step3() {
  Serial.println("Neural Step 3: Data flow initialization");
  
  // Sequential data flow movements
  smoothMove(0, 70);
  delay(100);
  smoothMove(1, 50);
  delay(100);
  smoothMove(2, 70);
  delay(100);
  smoothMove(3, 110);
  delay(100);
  smoothMove(4, 130);
  delay(100);
  smoothMove(5, 110);
  delay(100);
  
  // Flow pattern
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 60 + (i * 10));
    smoothMove(3, 120 - (i * 10));
    delay(200);
  }
  
  // Data stream legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 5);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 5);
  
  moveForward(120);
  delay(300);
}

// Step 4: Beat sync establishment
void neural_step4() {
  Serial.println("Neural Step 4: Beat sync establishment");
  
  // Rhythmic synchronization
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 80, 5);
    smoothMove(3, 100, 5);
    smoothMove(1, 60, 5);
    smoothMove(4, 120, 5);
    delay(150);
    
    smoothMove(0, 100, 5);
    smoothMove(3, 80, 5);
    smoothMove(1, 120, 5);
    smoothMove(4, 60, 5);
    delay(150);
  }
  
  // Beat emphasis
  smoothMove(2, 70, 3);
  smoothMove(5, 110, 3);
  delay(100);
  smoothMove(2, 110, 3);
  smoothMove(5, 70, 3);
  delay(100);
  
  // Sync leg movement
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 6);
  
  delay(250);
}

// Step 5: Thread pattern emergence
void neural_step5() {
  Serial.println("Neural Step 5: Thread pattern emergence");
  
  // Thread-like interconnected movements
  smoothMove(0, 60);
  smoothMove(1, 40);
  smoothMove(2, 60);
  delay(200);
  
  smoothMove(3, 120);
  smoothMove(4, 140);
  smoothMove(5, 120);
  delay(200);
  
  // Weaving pattern
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 70 + (i * 15));
    smoothMove(3, 110 - (i * 15));
    smoothMove(1, 50 + (i * 20));
    smoothMove(4, 130 - (i * 20));
    delay(250);
  }
  
  // Threading legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 4);
  
  // Side weave movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(200);
  stopBase();
  delay(200);
}

// Step 6: Beat drop preparation
void neural_step6() {
  Serial.println("Neural Step 6: Beat drop preparation");
  
  // Building tension for drop
  smoothMove(0, 75, 8);
  smoothMove(3, 105, 8);
  smoothMove(1, 55, 8);
  smoothMove(4, 125, 8);
  smoothMove(2, 75, 8);
  smoothMove(5, 105, 8);
  delay(400);
  
  // Tension pulses
  for (int i = 0; i < 5; i++) {
    smoothMove(0, 70, 3);
    smoothMove(3, 110, 3);
    delay(100);
    smoothMove(0, 80, 3);
    smoothMove(3, 100, 3);
    delay(100);
  }
  
  // Pre-drop leg tension
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 10);
  
  moveBackward(150);
  delay(300);
}

// Step 7: First beat drop
void neural_step7() {
  Serial.println("Neural Step 7: First beat drop");
  
  // Sharp drop movements
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 40, 2);
    smoothMove(3, 140, 2);
    smoothMove(1, 20, 2);
    smoothMove(4, 160, 2);
    smoothMove(2, 40, 2);
    smoothMove(5, 140, 2);
    delay(80);
    
    smoothMove(0, 140, 2);
    smoothMove(3, 40, 2);
    smoothMove(1, 160, 2);
    smoothMove(4, 20, 2);
    smoothMove(2, 140, 2);
    smoothMove(5, 40, 2);
    delay(80);
  }
  
  // Drop leg activation
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  // Rapid movement
  moveForward(100);
  moveBackward(100);
  delay(150);
}

// Step 8: Neural pulse rhythm
void neural_step8() {
  Serial.println("Neural Step 8: Neural pulse rhythm");
  
  // Rhythmic pulse patterns
  for (int i = 0; i < 8; i++) {
    smoothMove(0, 60 + (i % 2) * 40, 4);
    smoothMove(3, 120 - (i % 2) * 40, 4);
    delay(120);
  }
  
  // Pulse arms
  for (int i = 0; i < 4; i++) {
    smoothMove(1, 45, 3);
    smoothMove(4, 135, 3);
    smoothMove(2, 60, 3);
    smoothMove(5, 120, 3);
    delay(100);
    
    smoothMove(1, 75, 3);
    smoothMove(4, 105, 3);
    smoothMove(2, 120, 3);
    smoothMove(5, 60, 3);
    delay(100);
  }
  
  // Pulse legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  delay(150);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  
  delay(200);
}

// Step 9: Data processing phase
void neural_step9() {
  Serial.println("Neural Step 9: Data processing phase");
  
  // Complex processing movements
  smoothMove(0, 80, 10);
  smoothMove(3, 100, 10);
  smoothMove(1, 60, 10);
  smoothMove(4, 120, 10);
  delay(400);
  
  // Processing algorithm simulation
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 70 + (i * 5));
    smoothMove(3, 110 - (i * 5));
    smoothMove(2, 85 + (i * 10));
    smoothMove(5, 95 - (i * 10));
    delay(200);
    
    smoothMove(1, 55 + (i * 10));
    smoothMove(4, 125 - (i * 10));
    delay(200);
  }
  
  // Processing legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  
  moveForward(180);
  delay(350);
}

// Step 10: Thread convergence
void neural_step10() {
  Serial.println("Neural Step 10: Thread convergence");
  
  // Converging movements
  smoothMove(0, 45, 12);
  smoothMove(3, 135, 12);
  smoothMove(1, 30, 12);
  smoothMove(4, 150, 12);
  smoothMove(2, 45, 12);
  smoothMove(5, 135, 12);
  delay(500);
  
  // Convergence pattern
  for (int i = 5; i >= 1; i--) {
    smoothMove(0, 45 + (i * 8));
    smoothMove(3, 135 - (i * 8));
    smoothMove(1, 30 + (i * 12));
    smoothMove(4, 150 - (i * 12));
    delay(150);
  }
  
  // Converged position
  smoothMove(0, 90);
  smoothMove(3, 90);
  smoothMove(1, 90);
  smoothMove(4, 90);
  delay(300);
  
  // Convergence legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 6);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 6);
  
  delay(400);
}

// Step 11: Beat intensification
void neural_step11() {
  Serial.println("Neural Step 11: Beat intensification");
  
  // Intensifying rhythm
  for (int i = 1; i <= 5; i++) {
    smoothMove(0, 90 - (i * 12), 6 - i);
    smoothMove(3, 90 + (i * 12), 6 - i);
    smoothMove(1, 90 - (i * 10), 6 - i);
    smoothMove(4, 90 + (i * 10), 6 - i);
    delay(180 - (i * 20));
    
    smoothMove(0, 90 + (i * 12), 6 - i);
    smoothMove(3, 90 - (i * 12), 6 - i);
    smoothMove(1, 90 + (i * 10), 6 - i);
    smoothMove(4, 90 - (i * 10), 6 - i);
    delay(180 - (i * 20));
  }
  
  // Intensified arms
  smoothMove(2, 50, 3);
  smoothMove(5, 130, 3);
  delay(100);
  smoothMove(2, 130, 3);
  smoothMove(5, 50, 3);
  delay(100);
  
  // Intensified legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  // Directional change
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(200);
  stopBase();
  delay(200);
}

// Step 12: Neural storm
void neural_step12() {
  Serial.println("Neural Step 12: Neural storm");
  
  // Chaotic neural firing
  for (int i = 0; i < 10; i++) {
    smoothMove(0, random(30, 150), 2);
    smoothMove(3, random(30, 150), 2);
    smoothMove(1, random(20, 160), 2);
    smoothMove(4, random(20, 160), 2);
    smoothMove(2, random(40, 140), 2);
    smoothMove(5, random(40, 140), 2);
    delay(60);
  }
  
  // Storm calming
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 75 + random(-15, 15), 5);
    smoothMove(3, 105 + random(-15, 15), 5);
    delay(150);
  }
  
  // Storm legs
  for (int i = 0; i < 4; i++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(8, 20));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(8, 20));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(6, 16));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(6, 16));
    delay(100);
  }
  
  delay(300);
}

// Step 13: System stabilization
void neural_step13() {
  Serial.println("Neural Step 13: System stabilization");
  
  // Gradual stabilization
  smoothMove(0, 85, 15);
  smoothMove(3, 95, 15);
  smoothMove(1, 75, 15);
  smoothMove(4, 105, 15);
  smoothMove(2, 85, 15);
  smoothMove(5, 95, 15);
  delay(600);
  
  // Stability check
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 82, 8);
    smoothMove(3, 98, 8);
    delay(200);
    smoothMove(0, 88, 8);
    smoothMove(3, 92, 8);
    delay(200);
  }
  
  // Stable legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  
  moveForward(150);
  delay(400);
}

// Step 14: Thread pattern revival
void neural_step14() {
  Serial.println("Neural Step 14: Thread pattern revival");
  
  // Reviving thread patterns
  smoothMove(0, 70);
  smoothMove(1, 50);
  smoothMove(2, 70);
  delay(250);
  
  smoothMove(3, 110);
  smoothMove(4, 130);
  smoothMove(5, 110);
  delay(250);
  
  // Complex threading
  for (int i = 0; i < 4; i++) {
    smoothMove(0, 60 + (i * 8));
    smoothMove(3, 120 - (i * 8));
    smoothMove(1, 45 + (i * 15));
    smoothMove(4, 135 - (i * 15));
    smoothMove(2, 75 + (i * 10));
    smoothMove(5, 105 - (i * 10));
    delay(200);
  }
  
  // Revival legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 10);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 6);
  
  delay(350);
}

// Step 15: Beat evolution
void neural_step15() {
  Serial.println("Neural Step 15: Beat evolution");
  
  // Evolving beat patterns
  for (int evolution = 0; evolution < 4; evolution++) {
    for (int beat = 0; beat < 4; beat++) {
      smoothMove(0, 70 + (evolution * 10) + (beat * 5), 4);
      smoothMove(3, 110 - (evolution * 10) - (beat * 5), 4);
      smoothMove(1, 55 + (evolution * 8), 4);
      smoothMove(4, 125 - (evolution * 8), 4);
      delay(120 - (evolution * 20));
    }
  }
  
  // Evolution arms
  smoothMove(2, 60 + (20));
  smoothMove(5, 120 - (20));
  delay(300);
  
  // Evolved legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  moveBackward(200);
  delay(300);
}

// Step 16: Neural feedback loop
void neural_step16() {
  Serial.println("Neural Step 16: Neural feedback loop");
  
  // Feedback loop simulation
  int positions[6] = {75, 105, 60, 120, 75, 105};
  
  for (int loop = 0; loop < 3; loop++) {
    for (int i = 0; i < 6; i++) {
      smoothMove(i, positions[i] + (loop * 10), 5);
      delay(80);
    }
    
    for (int i = 5; i >= 0; i--) {
      smoothMove(i, positions[i] - (loop * 5), 5);
      delay(80);
    }
  }
  
  // Loop completion
  for (int i = 0; i < 6; i++) {
    smoothMove(i, 90, 8);
    delay(100);
  }
  
  // Feedback legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 9);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 9);
  
  delay(400);
}

// Step 17: Peak processing
void neural_step17() {
  Serial.println("Neural Step 17: Peak processing");
  
  // Peak performance movements
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 50, 3);
    smoothMove(3, 130, 3);
    smoothMove(1, 30, 3);
    smoothMove(4, 150, 3);
    smoothMove(2, 50, 3);
    smoothMove(5, 130, 3);
    delay(100);
    
    smoothMove(0, 130, 3);
    smoothMove(3, 50, 3);
    smoothMove(1, 150, 3);
    smoothMove(4, 30, 3);
    smoothMove(2, 130, 3);
    smoothMove(5, 50, 3);
    delay(100);
  }
  
  // Peak hold
  smoothMove(0, 45, 15);
  smoothMove(3, 135, 15);
  smoothMove(1, 25, 15);
  smoothMove(4, 155, 15);
  delay(500);
  
  // Peak legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 18);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 14);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 14);
  
  // Peak movement
  moveForward(120);
  moveBackward(120);
  moveForward(120);
  delay(200);
}

// Step 18: Data compression
void neural_step18() {
  Serial.println("Neural Step 18: Data compression");
  
  // Compression sequence
  for (int compress = 5; compress >= 1; compress--) {
    smoothMove(0, 90 - (compress * 15));
    smoothMove(3, 90 + (compress * 15));
    smoothMove(1, 90 - (compress * 12));
    smoothMove(4, 90 + (compress * 12));
    smoothMove(2, 90 - (compress * 10));
    smoothMove(5, 90 + (compress * 10));
    delay(200 - (compress * 30));
  }
  
  // Compressed state
  smoothMove(0, 90, 12);
  smoothMove(3, 90, 12);
  smoothMove(1, 90, 12);
  smoothMove(4, 90, 12);
  smoothMove(2, 90, 12);
  smoothMove(5, 90, 12);
  delay(400);
  
  // Compression legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 4);
  
  delay(300);
}

// Step 19: Expansion burst
void neural_step19() {
  Serial.println("Neural Step 19: Expansion burst");
  
  // Sudden expansion
  smoothMove(0, 30, 2);
  smoothMove(3, 150, 2);
  smoothMove(1, 15, 2);
  smoothMove(4, 165, 2);
  smoothMove(2, 30, 2);
  smoothMove(5, 150, 2);
  delay(300);
  
  // Expansion waves
  for (int wave = 0; wave < 4; wave++) {
    smoothMove(0, 30 + (wave * 15));
    smoothMove(3, 150 - (wave * 15));
    smoothMove(1, 15 + (wave * 20));
    smoothMove(4, 165 - (wave * 20));
    delay(150);
  }
  
  // Expansion legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 20);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 16);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 16);
  
  // Expansion movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(200);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(200);
  stopBase();
  delay(200);
}

// Step 20: Mid-beat climax
void neural_step20() {
  Serial.println("Neural Step 20: Mid-beat climax");
  
  // Climactic movements
  for (int climax = 0; climax < 8; climax++) {
    smoothMove(0, 40 + random(-10, 10), 2);
    smoothMove(3, 140 + random(-10, 10), 2);
    smoothMove(1, 25 + random(-15, 15), 2);
    smoothMove(4, 155 + random(-15, 15), 2);
    smoothMove(2, 40 + random(-20, 20), 2);
    smoothMove(5, 140 + random(-20, 20), 2);
    delay(80);
  }
  
  // Climax hold
  smoothMove(0, 45, 20);
  smoothMove(3, 135, 20);
  smoothMove(1, 30, 20);
  smoothMove(4, 150, 20);
  smoothMove(2, 45, 20);
  smoothMove(5, 135, 20);
  delay(600);
  
  // Climax trembling
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 43, 1);
    smoothMove(3, 137, 1);
    delay(60);
    smoothMove(0, 47, 1);
    smoothMove(3, 133, 1);
    delay(60);
  }
  
  // Climax legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 22);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 18);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 18);
  
  delay(500);
}

// Step 21: Beat breakdown
void neural_step21() {
  Serial.println("Neural Step 21: Beat breakdown");
  
  // System breakdown simulation
  smoothMove(0, 90, 8);
  smoothMove(3, 90, 8);
  delay(200);
  
  // Glitchy breakdown
  for (int glitch = 0; glitch < 8; glitch++) {
    smoothMove(0, 90 + random(-40, 40), 3);
    smoothMove(3, 90 + random(-40, 40), 3);
    smoothMove(1, 90 + random(-50, 50), 3);
    smoothMove(4, 90 + random(-50, 50), 3);
    delay(100);
  }
  
  // Stuttering breakdown
  for (int i = 0; i < 6; i++) {
    smoothMove(2, 70, 2);
    delay(80);
    smoothMove(2, 110, 2);
    delay(80);
    smoothMove(5, 110, 2);
    delay(80);
    smoothMove(5, 70, 2);
    delay(80);
  }
  
  // Breakdown legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 8);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  delay(150);
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 8);
  delay(150);
  
  delay(300);
}

// Step 22: System recovery
void neural_step22() {
  Serial.println("Neural Step 22: System recovery");
  
  // Gradual system recovery
  for (int recovery = 1; recovery <= 4; recovery++) {
    smoothMove(0, 90 - (20 / recovery));
    smoothMove(3, 90 + (20 / recovery));
    smoothMove(1, 90 - (15 / recovery));
    smoothMove(4, 90 + (15 / recovery));
    smoothMove(2, 90 - (10 / recovery));
    smoothMove(5, 90 + (10 / recovery));
    delay(250 + (recovery * 50));
  }
  
  // Recovery stabilization
  smoothMove(0, 85, 12);
  smoothMove(3, 95, 12);
  smoothMove(1, 80, 12);
  smoothMove(4, 100, 12);
  smoothMove(2, 85, 12);
  smoothMove(5, 95, 12);
  delay(500);
  
  // Recovery legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  
  moveForward(160);
  delay(400);
}

// Step 23: Enhanced processing
void neural_step23() {
  Serial.println("Neural Step 23: Enhanced processing");
  
  // Enhanced neural processing
  for (int enhance = 0; enhance < 5; enhance++) {
    smoothMove(0, 75 - (enhance * 5));
    smoothMove(3, 105 + (enhance * 5));
    smoothMove(1, 70 - (enhance * 8));
    smoothMove(4, 110 + (enhance * 8));
    smoothMove(2, 80 - (enhance * 6));
    smoothMove(5, 100 + (enhance * 6));
    delay(180);
    
    // Quick processing bursts
    for (int burst = 0; burst < 3; burst++) {
      smoothMove(0, 75 - (enhance * 5) - 5, 3);
      smoothMove(3, 105 + (enhance * 5) + 5, 3);
      delay(60);
      smoothMove(0, 75 - (enhance * 5) + 5, 3);
      smoothMove(3, 105 + (enhance * 5) - 5, 3);
      delay(60);
    }
  }
  
  // Enhanced legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 14);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 11);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 11);
  
  delay(350);
}

// Step 24: Thread multiplication
void neural_step24() {
  Serial.println("Neural Step 24: Thread multiplication");
  
  // Multiple thread simulation
  for (int thread = 0; thread < 4; thread++) {
    smoothMove(0, 60 + (thread * 5));
    smoothMove(1, 45 + (thread * 10));
    smoothMove(2, 70 + (thread * 8));
    delay(150);
    
    smoothMove(3, 120 - (thread * 5));
    smoothMove(4, 135 - (thread * 10));
    smoothMove(5, 110 - (thread * 8));
    delay(150);
  }
  
  // Thread synchronization
  for (int sync = 0; sync < 3; sync++) {
    for (int i = 0; i < 6; i++) {
      smoothMove(i, 90 + (i % 2 ? 20 : -20), 4);
    }
    delay(200);
    for (int i = 0; i < 6; i++) {
      smoothMove(i, 90, 6);
    }
    delay(200);
  }
  
  // Multiplication legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 9);
  
  // Multi-directional movement
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  delay(150);
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  delay(150);
  stopBase();
  delay(200);
}

// Step 25: Peak neural activity
void neural_step25() {
  Serial.println("Neural Step 25: Peak neural activity");
  
  // Maximum neural firing rate
  for (int peak = 0; peak < 10; peak++) {
    smoothMove(0, random(20, 160), 1);
    smoothMove(3, random(20, 160), 1);
    smoothMove(1, random(10, 170), 1);
    smoothMove(4, random(10, 170), 1);
    smoothMove(2, random(30, 150), 1);
    smoothMove(5, random(30, 150), 1);
    delay(50);
  }
  
  // Peak stabilization attempt
  for (int attempt = 0; attempt < 5; attempt++) {
    smoothMove(0, 45 + random(-15, 15), 3);
    smoothMove(3, 135 + random(-15, 15), 3);
    smoothMove(1, 30 + random(-10, 10), 3);
    smoothMove(4, 150 + random(-10, 10), 3);
    delay(100);
  }
  
  // Peak legs
  for (int i = 0; i < 5; i++) {
    pwmWriteAngle(LEG1_HIP_CHANNEL, random(12, 25));
    pwmWriteAngle(LEG2_HIP_CHANNEL, random(12, 25));
    pwmWriteAngle(LEG1_KNEE_CHANNEL, random(8, 20));
    pwmWriteAngle(LEG2_KNEE_CHANNEL, random(8, 20));
    delay(80);
  }
  
  // Peak movement chaos
  for (int i = 0; i < 3; i++) {
    moveForward(80);
    moveBackward(80);
    delay(40);
  }
}

// Step 26: Neural harmony
void neural_step26() {
  Serial.println("Neural Step 26: Neural harmony");
  
  // Harmonious movements
  smoothMove(0, 75, 18);
  smoothMove(3, 105, 18);
  smoothMove(1, 65, 18);
  smoothMove(4, 115, 18);
  smoothMove(2, 80, 18);
  smoothMove(5, 100, 18);
  delay(700);
  
  // Harmonic patterns
  for (int harmony = 0; harmony < 4; harmony++) {
    smoothMove(0, 75 + (harmony * 5));
    smoothMove(3, 105 - (harmony * 5));
    smoothMove(1, 65 + (harmony * 8));
    smoothMove(4, 115 - (harmony * 8));
    delay(300);
    
    smoothMove(2, 80 + (harmony * 6));
    smoothMove(5, 100 - (harmony * 6));
    delay(300);
  }
  
  // Harmony legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 12);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 9);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 9);
  
  moveForward(200);
  delay(400);
}

// Step 27: Beat synthesis
void neural_step27() {
  Serial.println("Neural Step 27: Beat synthesis");
  
  // Synthesizing beat elements
  for (int synth = 0; synth < 6; synth++) {
    // Layer 1
    smoothMove(0, 70, 5);
    smoothMove(1, 55, 5);
    delay(100);
    
    // Layer 2
    smoothMove(3, 110, 5);
    smoothMove(4, 125, 5);
    delay(100);
    
    // Layer 3
    smoothMove(2, 75 + (synth * 5), 5);
    smoothMove(5, 105 - (synth * 5), 5);
    delay(100);
    
    // Combined synthesis
    smoothMove(0, 90, 4);
    smoothMove(3, 90, 4);
    delay(80);
  }
  
  // Synthesis completion
  smoothMove(0, 80, 10);
  smoothMove(3, 100, 10);
  smoothMove(1, 70, 10);
  smoothMove(4, 110, 10);
  smoothMove(2, 85, 10);
  smoothMove(5, 95, 10);
  delay(400);
  
  // Synthesis legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 15);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  delay(350);
}

// Step 28: Final neural burst
void neural_step28() {
  Serial.println("Neural Step 28: Final neural burst");
  
  // Ultimate neural burst
  for (int burst = 0; burst < 8; burst++) {
    smoothMove(0, 30 + random(-15, 15), 2);
    smoothMove(3, 150 + random(-15, 15), 2);
    smoothMove(1, 20 + random(-10, 20), 2);
    smoothMove(4, 160 + random(-20, 10), 2);
    smoothMove(2, 35 + random(-25, 25), 2);
    smoothMove(5, 145 + random(-25, 25), 2);
    delay(70);
  }
  
  // Burst culmination
  smoothMove(0, 40, 15);
  smoothMove(3, 140, 15);
  smoothMove(1, 25, 15);
  smoothMove(4, 155, 15);
  smoothMove(2, 40, 15);
  smoothMove(5, 140, 15);
  delay(600);
  
  // Final burst trembling
  for (int i = 0; i < 8; i++) {
    smoothMove(0, 38, 2);
    smoothMove(3, 142, 2);
    delay(70);
    smoothMove(0, 42, 2);
    smoothMove(3, 138, 2);
    delay(70);
  }
  
  // Burst legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 24);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 24);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 20);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 20);
  
  // Final burst movement
  for (int i = 0; i < 4; i++) {
    moveForward(60);
    moveBackward(60);
    delay(30);
  }
}

// Step 29: Energy dissipation
void neural_step29() {
  Serial.println("Neural Step 29: Energy dissipation");
  
  // Gradual energy release
  for (int dissipate = 6; dissipate >= 1; dissipate--) {
    smoothMove(0, 40 + (dissipate * 10));
    smoothMove(3, 140 - (dissipate * 10));
    smoothMove(1, 25 + (dissipate * 12));
    smoothMove(4, 155 - (dissipate * 12));
    smoothMove(2, 40 + (dissipate * 8));
    smoothMove(5, 140 - (dissipate * 8));
    delay(200 + (6 - dissipate) * 100);
  }
  
  // Dissipation waves
  for (int wave = 0; wave < 3; wave++) {
    smoothMove(0, 85 - (wave * 5));
    smoothMove(3, 95 + (wave * 5));
    delay(400);
    smoothMove(0, 95 + (wave * 5));
    smoothMove(3, 85 - (wave * 5));
    delay(400);
  }
  
  // Dissipating legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 16);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 12);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 12);
  
  moveBackward(180);
  delay(500);
}

// Step 30: Beat fade transition
void neural_step30() {
  Serial.println("Neural Step 30: Beat fade transition");
  
  // Fading beat elements
  smoothMove(0, 85, 20);
  smoothMove(3, 95, 20);
  smoothMove(1, 80, 20);
  smoothMove(4, 100, 20);
  smoothMove(2, 90, 20);
  smoothMove(5, 90, 20);
  delay(800);
  
  // Fade oscillations
  for (int fade = 0; fade < 5; fade++) {
    smoothMove(0, 85 - (fade * 2));
    smoothMove(3, 95 + (fade * 2));
    smoothMove(1, 80 - (fade * 3));
    smoothMove(4, 100 + (fade * 3));
    delay(300 + (fade * 100));
  }
  
  // Transition legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 10);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 8);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 8);
  
  delay(600);
}

// Step 31: Neural shutdown sequence
void neural_step31() {
  Serial.println("Neural Step 31: Neural shutdown sequence");
  
  // Systematic shutdown
  smoothMove(0, 90, 25);
  delay(200);
  smoothMove(3, 90, 25);
  delay(200);
  smoothMove(1, 90, 25);
  delay(200);
  smoothMove(4, 90, 25);
  delay(200);
  smoothMove(2, 90, 25);
  delay(200);
  smoothMove(5, 90, 25);
  delay(200);
  
  // Shutdown confirmation pulses
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 85, 10);
    smoothMove(3, 95, 10);
    delay(250);
    smoothMove(0, 95, 10);
    smoothMove(3, 85, 10);
    delay(250);
  }
  
  // Shutdown legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 6);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 4);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 4);
  
  delay(700);
}

// Step 32: System standby
void neural_step32() {
  Serial.println("Neural Step 32: System standby");
  
  // Standby mode movements
  smoothMove(0, 90, 30);
  smoothMove(3, 90, 30);
  smoothMove(1, 90, 30);
  smoothMove(4, 90, 30);
  smoothMove(2, 90, 30);
  smoothMove(5, 90, 30);
  delay(1200);
  
  // Minimal standby activity
  for (int i = 0; i < 6; i++) {
    smoothMove(0, 88, 15);
    smoothMove(3, 92, 15);
    delay(400);
    smoothMove(0, 92, 15);
    smoothMove(3, 88, 15);
    delay(400);
  }
  
  // Standby legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 4);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 4);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 3);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 3);
  
  moveForward(80);
  delay(800);
}

// Step 33: Final processing echo
void neural_step33() {
  Serial.println("Neural Step 33: Final processing echo");
  
  // Echo of previous processing
  smoothMove(0, 85, 35);
  smoothMove(3, 95, 35);
  smoothMove(1, 85, 35);
  smoothMove(4, 95, 35);
  delay(1400);
  
  // Fading echoes
  for (int echo = 0; echo < 4; echo++) {
    smoothMove(0, 85 - (echo * 1));
    smoothMove(3, 95 + (echo * 1));
    smoothMove(1, 85 - (echo * 2));
    smoothMove(4, 95 + (echo * 2));
    delay(400 + (echo * 200));
  }
  
  // Echo legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 3);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 3);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 2);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 2);
  
  delay(800);
}

// Step 34: Neural silence approach
void neural_step34() {
  Serial.println("Neural Step 34: Neural silence approach");
  
  // Approaching complete silence
  smoothMove(0, 90, 40);
  smoothMove(3, 90, 40);
  smoothMove(1, 90, 40);
  smoothMove(4, 90, 40);
  smoothMove(2, 90, 40);
  smoothMove(5, 90, 40);
  delay(1600);
  
  // Final micro-adjustments
  for (int i = 0; i < 3; i++) {
    smoothMove(0, 89, 20);
    delay(500);
    smoothMove(0, 91, 20);
    delay(500);
    smoothMove(3, 91, 20);
    delay(500);
    smoothMove(3, 89, 20);
    delay(500);
  }
  
  // Near-silence legs
  pwmWriteAngle(LEG1_HIP_CHANNEL, 2);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 2);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 1);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 1);
  
  delay(1000);
}

// Step 35: Complete neural silence
void neural_step35() {
  Serial.println("Neural Step 35: Complete neural silence");
  
  // Final positioning to complete rest
  smoothMove(0, 90, 50);
  smoothMove(3, 90, 50);
  smoothMove(1, 90, 50);
  smoothMove(4, 90, 50);
  smoothMove(2, 90, 50);
  smoothMove(5, 90, 50);
  delay(2000);
  
  // One last breath-like movement
  for (int i = 0; i < 2; i++) {
    smoothMove(0, 89, 25);
    smoothMove(3, 91, 25);
    delay(600);
    smoothMove(0, 91, 25);
    smoothMove(3, 89, 25);
    delay(600);
  }
  
  // Complete rest position
  pwmWriteAngle(LEG1_HIP_CHANNEL, 0);
  pwmWriteAngle(LEG2_HIP_CHANNEL, 0);
  pwmWriteAngle(LEG1_KNEE_CHANNEL, 0);
  pwmWriteAngle(LEG2_KNEE_CHANNEL, 0);
  pwmWriteAngle(LEG1_ANKLE_CHANNEL, 0);
  pwmWriteAngle(LEG2_ANKLE_CHANNEL, 0);
  
  delay(2000);
  
  // Neural threads complete
  Serial.println("Neural threads processing complete - system in rest state");
  delay(500);
}

// Function to execute "Neural Threads" dance steps
void executeNeuralStep(int step) {
  switch (step) {
    case 1: neural_step1(); break;
    case 2: neural_step2(); break;
    case 3: neural_step3(); break;
    case 4: neural_step4(); break;
    case 5: neural_step5(); break;
    case 6: neural_step6(); break;
    case 7: neural_step7(); break;
    case 8: neural_step8(); break;
    case 9: neural_step9(); break;
    case 10: neural_step10(); break;
    case 11: neural_step11(); break;
    case 12: neural_step12(); break;
    case 13: neural_step13(); break;
    case 14: neural_step14(); break;
    case 15: neural_step15(); break;
    case 16: neural_step16(); break;
    case 17: neural_step17(); break;
    case 18: neural_step18(); break;
    case 19: neural_step19(); break;
    case 20: neural_step20(); break;
    case 21: neural_step21(); break;
    case 22: neural_step22(); break;
    case 23: neural_step23(); break;
    case 24: neural_step24(); break;
    case 25: neural_step25(); break;
    case 26: neural_step26(); break;
    case 27: neural_step27(); break;
    case 28: neural_step28(); break;
    case 29: neural_step29(); break;
    case 30: neural_step30(); break;
    case 31: neural_step31(); break;
    case 32: neural_step32(); break;
    case 33: neural_step33(); break;
    case 34: neural_step34(); break;
    case 35: neural_step35(); break;
    
    default: 
      Serial.println("Unknown step - valid steps are 1-35 for 'Neural Threads'"); 
      return;
  }
}

#endif
