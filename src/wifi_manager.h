#pragma once

#include <Arduino.h>

class WifiManagerService {
 public:
  bool begin();
  void maintainConnection();

 private:
  uint32_t lastRetryAtMs_ = 0;
  static constexpr uint32_t kRetryIntervalMs = 5000;
};
