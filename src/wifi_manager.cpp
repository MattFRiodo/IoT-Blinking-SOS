#include "wifi_manager.h"

#include <WiFi.h>
#include <WiFiManager.h>

bool WifiManagerService::begin() {
  WiFi.mode(WIFI_STA);

  WiFiManager wm;
  wm.setConfigPortalTimeout(180);

  const bool connected = wm.autoConnect("ESP32C3-SOS-Setup");
  if (connected) {
    Serial.print("Wi-Fi connected: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Wi-Fi setup skipped or failed. Running offline.");
  }

  return connected;
}

void WifiManagerService::maintainConnection() {
  const uint32_t now = millis();
  if (now - lastRetryAtMs_ < kRetryIntervalMs) {
    return;
  }

  lastRetryAtMs_ = now;

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi disconnected, retrying...");
    WiFi.reconnect();
  }
}
