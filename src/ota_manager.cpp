#include "ota_manager.h"

#include <ArduinoOTA.h>

void OtaManager::begin(const char *hostname) {
  ArduinoOTA.setHostname(hostname);

  ArduinoOTA.onStart([this]() {
    updating_ = true;
    Serial.println("OTA start");
  });

  ArduinoOTA.onEnd([this]() {
    updating_ = false;
    Serial.println("OTA end");
  });

  ArduinoOTA.onError([this](ota_error_t error) {
    updating_ = false;
    Serial.print("OTA error: ");
    Serial.println(static_cast<int>(error));
  });

  ArduinoOTA.begin();
  Serial.println("OTA ready");
}

void OtaManager::handle() {
  ArduinoOTA.handle();
}

bool OtaManager::isUpdating() const {
  return updating_;
}
