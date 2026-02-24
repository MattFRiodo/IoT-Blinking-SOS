

# Blinking LED SOS

## Document Information

| Field | Value  |
|--|--|
| Version | 1.1 |
| Status | Draft |
| Created | 2026-02-21 |
| Updated | 2026-02-24 |

## 1. Project Description

### 1.1 Purpose
This document implements a functional requirement for visual SOS Morse code signal using a built-in LED of a CORE ESP32-C3 microcontroller. 
the system outputs the text “SOS” to the serial monitor for each signaling cycle, enabling basic monitoring and debugging. 
The firmware incorporates Wi-Fi connectivity using a Wi-Fi manager with an automatic retry mechanism to ensure stable network access. 
Over-the-air (OTA) firmware update functionality is included to demonstrate remote maintainability without physical access to the device.

System is created simple for demonstration purposes. 

### 1.2. System Block Diagram

```
┌──────────────────────┐
|    User / Developer  |
|──────────────────────|
| - Power via USB      |
| - Serial Monitor     |
| - OTA Upload (Wi-Fi) |
└──────────────────────┘
           |
           | USB / Wi-Fi
           v
┌────────────────────────────────────┐
|        CORE ESP32-C3 System        |
|────────────────────────────────────|
|                                    |
|  ┌──────────────────────────────┐  |
|  | SOS Signaling Subsystem      |  |
|  |──────────────────────────────|  |
|  | - Morse timing (... --- ...) |  |
|  | - GPIO LED control           |  |
|  | - Continuous loop execution  |  |
|  └──────────────────────────────┘  |
|                 |                  |
|                 ▼                  |
|  ┌──────────────────────────────┐  |
|  | Monitoring & Debug Subsystem |  |
|  |──────────────────────────────|  |
|  | - Serial output: "SOS"       |  |
|  | - Debug visibility           |  |
|  └──────────────────────────────┘  |
|                 |                  |
|                 ▼                  |
|  ┌──────────────────────────────┐  |
|  | Connectivity & Maintenance   |  |
|  | Subsystem                    |  |
|  |──────────────────────────────|  |
|  | - Wi-Fi manager (retry)      |  |
|  | - ArduinoOTA handling        |  |
|  └──────────────────────────────┘  |
|                 |                  |
|                 ▼                  |
|        ┌─────────────────┐         |
|        | Built-in LED    |         |
|        └─────────────────┘         |
└────────────────────────────────────┘
           |
           ▼
┌──────────────────────┐
|   Wi-Fi Access Point |
└──────────────────────┘

```

### 1.3. Context Explanation

#### 1. SOS Signaling Subsystem

- Controls the built-in LED using GPIO
- Implements Morse code timing for the SOS pattern (... --- ...)
- Runs continuously in the main application loop
- Operates independently of Wi-Fi connectivity
- Pauses operation during OTA firmware updates

#### 2. Monitoring & Debug Subsystem

- Uses the USB serial interface for communication with a host computer
- Outputs the text SOS once per signaling cycle
- Provides basic visibility into system operation for debugging and validation

#### 3. Connectivity & Maintenance Subsystem

- Manages Wi-Fi connectivity using a Wi-Fi manager with automatic retry
- Handles over-the-air firmware updates using ArduinoOTA
- Operates in the background alongside the main loop

### User Interaction Context
#### User / Developer
- Supplies power and accesses logs via USB serial connection
- Uploads firmware and OTA updates using Arduino IDE or PlatformIO
- Does not directly interact with SOS signaling during normal operation


### 1.4. Goals
1. Transmits an SOS Morse code signal through the built-in LED
2. Integrate Wi-Fi connectivity using a Wi-Fi manager with an automatic retry mechanism.
3. Enable OTA firmware updates to allow remote maintenance and firmware improvements.

## 2. Hardware Specification

| Component | Description  |
|--|--|
| Microcontroller | LuatOS CORE ESP32-C3 |
| Output Device | Built-in LED |
| LED GPIO | GPIO 12 |
| WiFi | Built-in ESP32-C3 WiFi |
| Debug Interface | Serial (115200 baud) |

### 2.1 PlatformIO Build Configuration

The project uses PlatformIO build system with build config as follows

```
[env:airm2m_core_esp32c3]
platform = espressif32
board = airm2m_core_esp32c3
framework = arduino
monitor_speed = 115200
```


## 3. Functional Behavior

### 3.1 SOS LED Signaling

- SOS-001: The system shall blink the built-in LED in Morse code representing SOS (... --- ...).
- SOS-002: The SOS signaling sequence shall repeat continuously.
- SOS-003: Timing between dots, dashes, and letters shall follow standard Morse code conventions.

### 3.2 Serial Output

- SER-001: The system shall output the text SOS to the serial monitor once per signaling cycle.
- SER-002: Serial output shall operate at 115200 baud.

### 3.3 Wi-Fi Connectivity

- WIFI-001: The system shall connect to a Wi-Fi network using a Wi-Fi manager.
- WIFI-002: The system shall automatically retry connection if Wi-Fi is lost.
- WIFI-003: Wi-Fi credentials shall be stored persistently.

### 3.4 OTA Firmware Update

- OTA-001: The system shall support firmware updates using ArduinoOTA over Wi-Fi.
- OTA-002: OTA updates shall be initiated from the PlatformIO without physical access.
- OTA-003: The system shall pause SOS LED signaling during an active OTA update.
- OTA-004: The system shall resume normal operation after a successful OTA update.

## 4. Non-functional Requirements

| Metric  | Target |
| -- | -- |
| Boot time     | < 5 seconds   |
| WiFi connect  | < 15 seconds  |
| LED timing accuracy | ±10 ms  |
| OTA reliability  | No firmware corruption |

## 4. Project Structure

### 4.1. Firmware Architecture

```
coreesp32c3-sos/
├── src/
│   ├── main.cpp              
│   ├── sos.cpp               
│   ├── sos.h                 
│   ├── wifi_manager.cpp      
│   ├── wifi_manager.h        
│   ├── ota_manager.cpp       
│   └── ota_manager.h         
│
├── lib/
│   ├── sos_controller.cpp
│   ├── sos_controller.cpp
│   ├── wifi_helper.cpp
│   ├── wifi_helper.h
│   ├── ota_helper.cpp
│   └── ota_helper.h
│
├── docs/
│   └── FSD.md                
│
├── include/                  
├── platformio.ini            
└── README.md                 

```
### 

## 5. Constraints

1. The system SHALL use the onboard LED only
2. The firmware SHALL be built using Arduino framework under PlatformIO
3. OTA updates SHALL rely solely on ArduinoOTA 
4. The system is intended for demonstration purposes only

## Revision History

| Version | Date  | Author | Changes
|--|--|--| -- |
| 1.0 | 2026-02-21 | - | Initial specification
| 1.1 | 2026-02-24 | - | Updated specification & Eliminated Blynk usage