#include <Servo.h>

// ====== CONFIG ======
const uint8_t trigPin  = 9;
const uint8_t echoPin  = 10;

// Add your servo pins here (up to ~12 on an Uno, ~48 on a Mega)
const uint8_t servoPins[] = {3, 4, 5, 6, 7};   // <- change as needed
const uint8_t N_SERVOS = sizeof(servoPins) / sizeof(servoPins[0]);

// Per-servo angle limits (optional, for mechanical safety)
const int servoMinDeg[N_SERVOS] = {  0, 10,  0, 30};
const int servoMaxDeg[N_SERVOS] = {180,140,160,120};

// Map distance (cm) to angle. Adjust to your scene.
const float mapNearCM =  2.0;  // closest distance (cm) -> high angle
const float mapFarCM  = 30.0;  // far distance (cm)     -> low angle

// Smoothing (0..1). Higher = smoother but slower response.
const float alpha = 0.25f;

// ====== STATE ======
Servo servos[N_SERVOS];

unsigned long duration = 0; // microseconds
float distanceCM = 0.0f;
float distanceIN = 0.0f;
float distanceFT = 0.0f;

float smoothedDeg = 0.0f; // low-pass filtered angle

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Attach all servos
  for (uint8_t i = 0; i < N_SERVOS; i++) {
    servos[i].attach(servoPins[i]);
  }

  // Optional: move to a safe start angle
  for (uint8_t i = 0; i < N_SERVOS; i++) {
    servos[i].write(constrain(90, servoMinDeg[i], servoMaxDeg[i]));
  }
}

void loop() {
  // --- Trigger the ultrasonic sensor ---
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure echo (timeout helps avoid 0 hang if nothing returns)
  duration = pulseIn(echoPin, HIGH, 30000UL); // 30ms timeout (~5m)

  if (duration == 0) {
    // No echo: keep previous angle (or choose a default)
    // Optionally set distance to a "far" value
    distanceCM = mapFarCM;
  } else {
    // 0.0343 cm/us is speed of sound; divide by 2 for round-trip
    distanceCM = (duration * 0.0343f) / 2.0f;
  }

  // Convert units
  distanceIN = distanceCM / 2.54f;
  distanceFT = distanceIN / 12.0f; // <-- correct conversion

  // Map distance to angle (invert so nearer -> larger angle)
  int rawDeg = mapFloatToInt(distanceCM, mapFarCM, mapNearCM, 0, 180);
  rawDeg = constrain(rawDeg, 0, 180);

  // Smooth to reduce jitter
  smoothedDeg = (1.0f - alpha) * smoothedDeg + alpha * rawDeg;

  // Write to each servo with its own safe range
  for (uint8_t i = 0; i < N_SERVOS; i++) {
    int limited = constrain((int)smoothedDeg, servoMinDeg[i], servoMaxDeg[i]);
    servos[i].write(limited);
  }

  // Debug print
  Serial.print("Distance: ");
  Serial.print(distanceCM, 1); Serial.print(" cm | ");
  Serial.print(distanceIN, 2); Serial.print(" in | ");
  Serial.print(distanceFT, 3); Serial.print(" ft | ");
  Serial.print("Angle: "); Serial.println((int)smoothedDeg);

  delay(40); // ~25 Hz update
}

// Helper: like map() but for float in/out, returns int angle
int mapFloatToInt(float x, float in_min, float in_max, int out_min, int out_max) {
  // Protect against division by zero
  if (fabs(in_max - in_min) < 1e-6) return out_min;
  float t = (x - in_min) / (in_max - in_min);
  // Clamp 0..1 to avoid weird overshoot
  if (t < 0) t = 0;
  if (t > 1) t = 1;
  float y = out_min + t * (out_max - out_min);
  return (int)(y + 0.5f);
}
