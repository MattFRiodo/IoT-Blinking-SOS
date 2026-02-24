#pragma once

#include <Arduino.h>

class SosController {
 public:
  explicit SosController(uint8_t ledPin);

  void begin();
  void setEnabled(bool enabled);
  void setPaused(bool paused);
  bool update();

 private:
  struct Step {
    bool ledOn;
    uint16_t durationUnits;
  };

  static constexpr uint16_t kUnitMs = 200;
  static constexpr Step kPattern[] = {
      {true, 1}, {false, 1}, {true, 1}, {false, 1}, {true, 1}, {false, 3},
      {true, 3}, {false, 1}, {true, 3}, {false, 1}, {true, 3}, {false, 3},
      {true, 1}, {false, 1}, {true, 1}, {false, 1}, {true, 1}, {false, 7},
  };

  uint8_t ledPin_;
  bool enabled_ = true;
  bool paused_ = false;
  size_t stepIndex_ = 0;
  uint32_t nextStepAtMs_ = 0;

  void forceLedOff();
};
