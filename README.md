# Smart-Air-Pollution-Monitoring-System

---

### Project Overview

The Smart Air Pollution Monitoring System is an embedded system designed to monitor environmental conditions in real time. It uses multiple sensors to detect air quality, temperature, humidity, and light intensity.

The system processes sensor data using an Arduino microcontroller and displays results on an LCD screen. If pollution levels exceed a predefined threshold, an alert (buzzer/LED) is triggered.

---

### Objectives
- Monitor air pollution levels in real time
- Measure environmental parameters (temperature, humidity, light)
- Provide instant visual feedback using LCD display
- Alert users when pollution exceeds safe limits

---

### Components Used
- Arduino Uno (Microcontroller)
- MQ135 Gas Sensor (Air Quality Detection)
- DHT11 Sensor (Temperature & Humidity)
- LDR Sensor (Light Intensity)
- 16x2 LCD Display
- Buzzer
- Breadboard
- Jumper Wires
- USB Power Supply

---

### Working Principle

- The system continuously collects data from sensors:
    - MQ135 detects harmful gases like CO₂, ammonia, and smoke
    - DHT11 measures temperature and humidity
    - LDR measures ambient light intensity

- The Arduino processes this data and:
    - Displays values on the LCD
    - Compares gas levels with a threshold
    - Activates buzzer/LED if pollution is high

---

### Circuit Diagram

- The circuit diagram (shown in page 3 of the document) connects:
- MQ135 → Analog pin A0
- LDR → Analog pin A1
- DHT11 → Digital pin D7
- LCD → Digital pins (D2–D12)
- Buzzer → Digital pin D8

- It uses a common ground and 5V power supply across components.

---

### Algorithm / Pseudocode

Start
Initialize LCD, sensors, and buzzer

Loop:
    Read gas sensor value
    Read temperature and humidity
    Read light intensity
    Display values on LCD
    
    If gas value > threshold:
        Turn ON buzzer
    Else:
        Turn OFF buzzer
End Loop

---

### Output Description
- Case 1: Gas & Light Monitoring
    - Gas Value: ~156 → Moderate pollution level
    - Light: Bright → High light intensity
    - LED/Buzzer: ON → Indicates pollution threshold exceeded
    - (Shown in output image on page 5)

- Case 2: Temperature & Humidity
    - Temperature: 33.6°C → Warm environment
    - Humidity: 28% → Dry conditions
    - LED: ON → System active / alert state
    - (Shown in output image on page 6)

---

### Features
- Real-time environmental monitoring
- Multi-sensor integration
- Automatic alert system
- Low-cost and efficient design
- Easy to implement and scalable

---

### Applications
- Smart homes
- Industrial safety systems
- Environmental monitoring stations
- Pollution detection in urban areas

---

### Team Members

Anand (PES1UG24AM341)
Amar (PES1UG24AM340)
Basawaraj Panchal (PES1UG24AM350)

---

### Future Enhancements
- IoT integration for remote monitoring
- Mobile app notifications
- Cloud data storage and analytics
- Advanced gas sensors for higher accuracy
