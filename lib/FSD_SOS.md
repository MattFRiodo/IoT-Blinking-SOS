

# Blinking LED SOS

## 1. Project Description
This project implements a visual SOS Morse code signal using an LED connected to an ESP32-C3 microcontroller.  
The SOS signal is remotely controlled via the Blynk IoT mobile application and supports Wi-Fi connectivity and OTA firmware updates through Blynk Edgent.

----------

## 2. System Overview

The ESP32-C3 connects to the Blynk Cloud over Wi-Fi.  
A virtual button in the Blynk app controls whether the SOS signal is active.  
When enabled, the LED continuously blinks the SOS Morse code pattern until disabled.

----------

## 3. System Block Diagram

Blynk Mobile App  
 |  
 |  Internet (Wi-Fi)  
 v  
Blynk Cloud Server  
 |  
 v  
ESP32-C3 (Arduino + Blynk Edgent)  
 |  
 | GPIO 12  
 v  
Physical LED (SOS Morse Code)

----------

## 4. Hardware Specification

| Component | Description  |
|--|--|
| Microcontroller | CORE ESP32-C3 |
| Board | airm2m_core_esp32c3 |
| Output Device | LED |
| LED GPIO | GPIO 12 |
| Debug Interface | Serial (115200 baud) |


----------



## 5. Functional Behavior

### 5.1 SOS Control Logic

-   When Blynk Virtual Pin V0 = 1:
    
    -   The LED blink the SOS Morse code pattern continuously.
        
-   When Blynk Virtual Pin V0 = 0:
    
    -   The LED immediately turns OFF.
        

----------

## 7. SOS Timing Specification

| Signal | LED ON  | LED OFF |
|--|--|--|
| Short blink (S) | 500 ms  | 500 ms |
| Long blink (O) | 1000 ms | 500 ms |
| Long blink (O) | - | 1000 ms |



### SOS Pattern

S → ...   (3 short blinks)  
O → ---   (3 long blinks)  
S → ...   (3 short blinks)

The sequence repeats continuously while enabled.

----------

## 8. Connectivity and OTA

-   The device connects to Wi-Fi using Blynk Edgent.
    
-   OTA firmware updates are performed via Blynk Cloud.
    
-   The LED continues blinking SOS during OTA updates.
    

----------
## 9. Deployment Procedure

1.  Create a device template in the Blynk Console.
    
2.  Obtain the Template ID and Auth Token.
    
3.  Upload the firmware to the ESP32-C3.
4.  Provision Wi-Fi credentials using Blynk Edgent.
    
5.  Control SOS blinking via the Blynk mobile app.
