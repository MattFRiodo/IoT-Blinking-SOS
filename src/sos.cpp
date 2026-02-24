#include "sos.h"

SosController::SosController(uint8_t ledPin) : ledPin_(ledPin) {}

void SosController::begin() {
  pinMode(ledPin_, OUTPUT);
  forceLedOff();
  stepIndex_ = 0;
  nextStepAtMs_ = millis();
}

void SosController::setEnabled(bool enabled) {
  enabled_ = enabled;
  if (!enabled_) {
    forceLedOff();
  } else {
    stepIndex_ = 0;
    nextStepAtMs_ = millis();
  }
}

void SosController::setPaused(bool paused) {
  paused_ = paused;
  if (paused_) {
    forceLedOff();
  } else {
    nextStepAtMs_ = millis();
  }
}

bool SosController::update() {
  if (!enabled_ || paused_) {
    return false;
  }

  const uint32_t now = millis();
  if (now < nextStepAtMs_) {
    return false;
  }

  const Step &step = kPattern[stepIndex_];
  digitalWrite(ledPin_, step.ledOn ? HIGH : LOW);
  nextStepAtMs_ = now + (step.durationUnits * kUnitMs);

  stepIndex_++;
  if (stepIndex_ >= (sizeof(kPattern) / sizeof(kPattern[0]))) {
    stepIndex_ = 0;
    return true;
  }

  return false;
}

void SosController::forceLedOff() {
  digitalWrite(ledPin_, LOW);
}
