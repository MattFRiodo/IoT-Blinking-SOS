#include <Arduino.h>

#include "ota_manager.h"
#include "sos.h"
#include "wifi_manager.h"

namespace {
constexpr uint8_t kLedPin = 12;

SosController sos(kLedPin);
WifiManagerService wifi;
OtaManager ota;
}  // namespace

void setup() {
  Serial.begin(115200);
  delay(100);

  sos.begin();
  sos.setEnabled(true);

  wifi.begin();
  ota.begin("coreesp32c3-sos");
}

void loop() {
  wifi.maintainConnection();
  ota.handle();

  sos.setPaused(ota.isUpdating());
  if (sos.update()) {
    Serial.println("SOS");
  }
}
