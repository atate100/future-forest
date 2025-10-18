#include <FastLED.h>

// ---------------- LED CONFIG ----------------
#define NUM_STRIPS 5
#define NUM_LEDS_PER_STRIP 7
#define TOTAL_LEDS (NUM_STRIPS * NUM_LEDS_PER_STRIP)

#define DATA_PIN_1 3
#define DATA_PIN_2 4
#define DATA_PIN_3 5
#define DATA_PIN_4 6
#define DATA_PIN_5 7

CRGB leds[TOTAL_LEDS];

uint8_t globalBrightness = 50;   // overall brightness


// ---------------- ULTRASONIC CONFIG ----------------
const uint8_t TRIG_PIN = 8;
const uint8_t ECHO_PIN = 9;

const float HEARTBEAT_ENTER_MIN_CM = 15.0;
const float HEARTBEAT_ENTER_MAX_CM = 91.0;
const float HEARTBEAT_EXIT_MAX_CM  = 100.0;


// ---------------- MODE STATE ----------------
unsigned long nowMs;
enum Mode { MODE_CHASE, MODE_HEARTBEAT, MODE_TRANSITION_IN, MODE_TRANSITION_OUT };
Mode currentMode = MODE_CHASE;


// ---------------- TRANSITION STATE ----------------
const uint8_t  TRANSITION_STEPS    = 25;
const uint8_t  TRANSITION_DELAY_MS = 12;
uint8_t        transitionStep      = 0;
unsigned long  lastTransitionTick  = 0;


// ---------------- HEARTBEAT @ 75 BPM ----------------
#define HEARTBEAT_BPM 75
const float HB_CYCLE_MS = 60000.0f / HEARTBEAT_BPM; // 800 ms per full cycle

// stage durations sum to 800 ms
const uint16_t HB_RISE_MS   = 120;
const uint16_t HB_FALL1_MS  = 160;
const uint16_t HB_PAUSE1_MS = 80;
const uint16_t HB_FALL2_MS  = 160;
const uint16_t HB_PAUSE2_MS = (uint16_t)(HB_CYCLE_MS - (HB_RISE_MS + HB_FALL1_MS + HB_PAUSE1_MS + HB_FALL2_MS)); // ≈280 ms

const uint8_t HB_BASE1 = 40;
const uint8_t HB_BASE2 = 30;
const uint8_t HB_PEAK  = 200;
const uint8_t HB_POP   = 150;

uint8_t       hbStage       = 0;
uint8_t       hbBrightness  = 0;
unsigned long hbStageStart  = 0;

static uint8_t lerp8_u8(uint8_t a, uint8_t b, float t) {
  if (t <= 0.0f) return a;
  if (t >= 1.0f) return b;
  return a + (int)((b - a) * t + 0.5f);
}

void heartbeatStep() {
  unsigned long now = nowMs;
  unsigned long elapsed = now - hbStageStart;

  switch (hbStage) {
    case 0: { // rise
      float t = (float)elapsed / HB_RISE_MS;
      hbBrightness = lerp8_u8(HB_BASE1, HB_PEAK, t);
      if (elapsed >= HB_RISE_MS) { hbStage = 1; hbStageStart = now; }
      break;
    }
    case 1: { // fall1
      float t = (float)elapsed / HB_FALL1_MS;
      hbBrightness = lerp8_u8(HB_PEAK, HB_BASE1, t);
      if (elapsed >= HB_FALL1_MS) { hbStage = 2; hbStageStart = now; }
      break;
    }
    case 2: { // pause1
      hbBrightness = HB_BASE1;
      if (elapsed >= HB_PAUSE1_MS) { hbStage = 3; hbStageStart = now; }
      break;
    }
    case 3: { // second bump
      hbBrightness = HB_POP;
      hbStage = 4; hbStageStart = now;
      break;
    }
    case 4: { // fall2
      float t = (float)elapsed / HB_FALL2_MS;
      hbBrightness = lerp8_u8(HB_POP, HB_BASE2, t);
      if (elapsed >= HB_FALL2_MS) { hbStage = 5; hbStageStart = now; }
      break;
    }
    case 5: { // pause2
      hbBrightness = HB_BASE2;
      if (elapsed >= HB_PAUSE2_MS) { hbStage = 0; hbStageStart = now; }
      break;
    }
  }

  fill_solid(leds, TOTAL_LEDS, CRGB(hbBrightness, 0, 0));
  FastLED.setBrightness(globalBrightness);
  FastLED.show();
}


// ---------------- BLUE TWINKLE + SPARKS ----------------
const CRGB BLUE_A = CRGB(0, 40, 120);
const CRGB BLUE_B = CRGB(40, 224, 208);
const CRGB BLUE_C = CRGB(0, 150, 230);

CRGB        twinkleTarget[TOTAL_LEDS];
uint8_t     twinkleSpeed[TOTAL_LEDS];
unsigned long lastTwinkleBlend = 0;
unsigned long lastTwinkleRetarget = 0;

const uint16_t TWINKLE_BLEND_INTERVAL_MS    = 20;
const uint16_t TWINKLE_RETARGET_INTERVAL_MS = 150;
const uint8_t  TWINKLE_NEW_TARGET_PROB      = 20;

// Sparks
bool         sparkOn[TOTAL_LEDS];
unsigned long sparkStart[TOTAL_LEDS];
unsigned long lastSparkCheck = 0;
const uint16_t SPARK_INTERVAL_MS      = 70;
const uint8_t  SPARK_CHANCE_PER_LED   = 2;
const uint16_t SPARK_DURATION_MS      = 120;

CRGB randomBlueChoice() {
  switch (random8(3)) {
    case 0: return BLUE_A;
    case 1: return BLUE_B;
    default: return BLUE_C;
  }
}

void initTwinkle() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    twinkleTarget[i] = randomBlueChoice();
    leds[i] = twinkleTarget[i];
    twinkleSpeed[i] = 8 + random8(24);
    sparkOn[i] = false;
    sparkStart[i] = 0;
  }
  FastLED.show();
  lastTwinkleBlend = nowMs;
  lastTwinkleRetarget = nowMs;
  lastSparkCheck = nowMs;
}

void twinkleBlueStep() {
  if (nowMs - lastTwinkleRetarget >= TWINKLE_RETARGET_INTERVAL_MS) {
    lastTwinkleRetarget = nowMs;
    for (int i = 0; i < TOTAL_LEDS; i++) {
      if (random8(100) < TWINKLE_NEW_TARGET_PROB) {
        twinkleTarget[i] = randomBlueChoice();
        twinkleSpeed[i] = 8 + random8(24);
      }
    }
  }

  if (nowMs - lastSparkCheck >= SPARK_INTERVAL_MS) {
    lastSparkCheck = nowMs;
    for (int i = 0; i < TOTAL_LEDS; i++) {
      if (!sparkOn[i] && random8(100) < SPARK_CHANCE_PER_LED) {
        sparkOn[i] = true;
        sparkStart[i] = nowMs;
      }
    }
  }

  if (nowMs - lastTwinkleBlend >= TWINKLE_BLEND_INTERVAL_MS) {
    lastTwinkleBlend = nowMs;
    for (int i = 0; i < TOTAL_LEDS; i++) {
      nblend(leds[i], twinkleTarget[i], twinkleSpeed[i]);
    }
  }

  for (int i = 0; i < TOTAL_LEDS; i++) {
    if (sparkOn[i]) {
      unsigned long elapsed = nowMs - sparkStart[i];
      if (elapsed >= SPARK_DURATION_MS) {
        sparkOn[i] = false;
      } else {
        uint8_t amt = 220 - (uint8_t)map(elapsed, 0, SPARK_DURATION_MS, 0, 220);
        nblend(leds[i], CRGB::White, amt);
      }
    }
  }

  FastLED.setBrightness(globalBrightness);
  FastLED.show();
}


// ---------------- UTILS ----------------
void setAll(CRGB c) { fill_solid(leds, TOTAL_LEDS, c); }

bool fadeToBlackStep() {
  for (int i = 0; i < TOTAL_LEDS; i++) leds[i].nscale8_video(230);
  FastLED.show();
  return true;
}

bool fadeInToRedStep(uint8_t step, uint8_t totalSteps) {
  uint8_t level = map(step, 0, totalSteps, 0, 180);
  setAll(CRGB(level, 0, 0));
  FastLED.show();
  return true;
}

float readDistanceCm() {
  const uint8_t samples = 3;
  float sum = 0.0f; uint8_t good = 0;
  for (uint8_t i = 0; i < samples; i++) {
    digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
    if (!duration) continue;
    float cm = (duration * 0.0343f) / 2.0f;
    if (cm >= 5.0f && cm < 400.0f) { sum += cm; good++; }
    delay(3);
  }
  return good ? (sum / good) : -1.0f;
}

Mode decideTargetMode(float cm, Mode current) {
  if (cm < 0) return current;
  bool inHeartbeat = (cm >= HEARTBEAT_ENTER_MIN_CM && cm <= HEARTBEAT_ENTER_MAX_CM);
  bool farEnoughToExit = (cm > HEARTBEAT_EXIT_MAX_CM);
  if (current == MODE_HEARTBEAT || current == MODE_TRANSITION_IN) {
    if (farEnoughToExit) return MODE_CHASE;
    return MODE_HEARTBEAT;
  } else {
    if (inHeartbeat) return MODE_HEARTBEAT;
    return MODE_CHASE;
  }
}


// ---------------- ARDUINO SETUP/LOOP ----------------
void setup() {
  FastLED.setBrightness(globalBrightness);
  FastLED.addLeds<WS2812B, DATA_PIN_1, GRB>(leds + 0 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2812B, DATA_PIN_2, GRB>(leds + 1 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2812B, DATA_PIN_3, GRB>(leds + 2 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2812B, DATA_PIN_4, GRB>(leds + 3 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  FastLED.addLeds<WS2812B, DATA_PIN_5, GRB>(leds + 4 * NUM_LEDS_PER_STRIP, NUM_LEDS_PER_STRIP);
  setAll(CRGB::Black); FastLED.show();

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);

  nowMs = millis();
  hbStageStart = nowMs;
  lastTransitionTick = nowMs;

  initTwinkle();
}

void loop() {
  nowMs = millis();
  float cm = readDistanceCm();
  Mode target = decideTargetMode(cm, currentMode);

  if (currentMode == MODE_CHASE && target == MODE_HEARTBEAT) {
    currentMode = MODE_TRANSITION_IN;
    transitionStep = 0; lastTransitionTick = nowMs;
    setAll(CRGB::Black); FastLED.show();
  } else if (currentMode == MODE_HEARTBEAT && target == MODE_CHASE) {
    currentMode = MODE_TRANSITION_OUT;
    transitionStep = 0; lastTransitionTick = nowMs;
  }

  switch (currentMode) {
    case MODE_TRANSITION_IN:
      if (nowMs - lastTransitionTick >= TRANSITION_DELAY_MS) {
        lastTransitionTick = nowMs;
        fadeInToRedStep(transitionStep, TRANSITION_STEPS);
        if (++transitionStep >= TRANSITION_STEPS) {
          hbStage = 0; hbStageStart = nowMs; hbBrightness = HB_BASE1;
          currentMode = MODE_HEARTBEAT;
        }
      }
      break;

    case MODE_TRANSITION_OUT:
      if (nowMs - lastTransitionTick >= TRANSITION_DELAY_MS) {
        lastTransitionTick = nowMs;
        fadeToBlackStep();
        if (++transitionStep >= TRANSITION_STEPS) {
          initTwinkle();
          currentMode = MODE_CHASE;
        }
      }
      break;

    case MODE_HEARTBEAT:
      heartbeatStep();
      break;

    case MODE_CHASE:
    default:
      twinkleBlueStep();
      break;
  }
}
