# ESP UART Bridge
[![CC BY-NC 4.0][cc-by-nc-shield]][cc-by-nc]

## Overview

**ESP UART Bridge** creates a UART bridge on the ESP32 using ESP-IDF. The bridge supports communication between UART1 (as one interface) and a UART micro USB cable (UART0), Bluetooth, and Wi-Fi. The project is created since there is no official support for uart bridge for ESP32 (not ESP32-S2 or ESP32-S3).

### Features

- **UART micro USB Cable**: Bridges between UART0 (default debug UART) and UART1.
- **Bluetooth (Classic/LE)**
- **Wi-Fi**
- **Configurable Interface**: Dynamically forward data between any combination of UART, Bluetooth, and Wi-Fi.

## Building and Flashing

1. **Install ESP-IDF**

Ensure ESP-IDF is correctly installed and configured on your system. Follow the official [ESP-IDF Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/).

2. **Clone the Repository**
```bash
git clone https://github.com/your-repo/uart-bridge.git
cd uart-bridge
```

3. **Set the Target Chip**
```bash
idf.py set-target esp32
```

4. **Configure the Project**
Run the following command to configure the project
```bash
idf.py menuconfig
```

5. **Build the Project**
```bash
idf.py build
```

6. **Flash the Firmware**
```bash
idf.py flash
```
   
7. **Monitor the Serial Output**
```bash
idf.py monitor
```

## Contributing

We welcome contributions to the **ESP UART Bridge** project!

## License

This work is licensed under a
[Creative Commons Attribution-NonCommercial 4.0 International License][cc-by-nc].

[![CC BY-NC 4.0][cc-by-nc-image]][cc-by-nc]

[cc-by-nc]: https://creativecommons.org/licenses/by-nc/4.0/
[cc-by-nc-image]: https://licensebuttons.net/l/by-nc/4.0/88x31.png
[cc-by-nc-shield]: https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg
