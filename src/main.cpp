#include <Arduino.h>
#define BLYNK_TEMPLATE_ID "TMPL6gd5frN3K"
#define BLYNK_TEMPLATE_NAME "Blink LED SOS"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define LED_PIN 12

#include "BlynkEdgent.h"


BLYNK_WRITE(V0)
{
  int value = param.asInt();

  if (value == 1) {
    for(int i = 0; i < 3; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(500);
      digitalWrite(LED_PIN, LOW);
      delay(500);
    }
    Serial.println("S");

    delay(1000);
    for(int i = 0; i < 3; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(1000);
      digitalWrite(LED_PIN, LOW);
      delay(500);
    }
    Serial.println("O"); 

    delay(1000);
    for(int i = 0; i < 3; i++) {
      digitalWrite(LED_PIN, HIGH);
      delay(500);
      digitalWrite(LED_PIN, LOW);
      delay(500);
    }
    Serial.println("S");
  
    Serial.print("value =");
    Serial.println(value);

  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.print("value = ");
    Serial.println(value);
  }
}
void setup()
{
  pinMode(LED_PIN, OUTPUT);

  Serial.begin(115200);
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  delay(10);
}

/*void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  for(int i = 0; i < 3; i++) {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  }
  Serial.println("S");

  delay(1000);
  for(int i = 0; i < 3; i++) {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(500);
  }
  Serial.println("O"); 

  delay(1000);
  for(int i = 0; i < 3; i++) {
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  }
  Serial.println("S");

} */