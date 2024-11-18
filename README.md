# ESP UART Bridge
[![CC BY-NC 4.0][cc-by-nc-shield]][cc-by-nc]

## Overview

**ESP UART Bridge** creates a UART bridge on the ESP32 using ESP-IDF. The bridge supports communication between UART1 (as one interface) and a UART micro USB cable (UART0), Bluetooth, and Wi-Fi. The project is created since there is no official support for uart bridge for ESP32 (not ESP32-S2 or ESP32-S3).

### Features

- **UART micro USB Cable**: Bridges between UART0 (default debug UART) and UART1.
- **Bluetooth (Classic/LE)**
- **Wi-Fi**
- **Configurable Interface**: Dynamically forward data between any combination of UART, Bluetooth, and Wi-Fi.

## Development

This project is currently under devlopment checkout **dev** branch to look at lastest devlopment.

## Contributing

We welcome contributions to the **ESP UART Bridge** project!

## License

This work is licensed under a
[Creative Commons Attribution-NonCommercial 4.0 International License][cc-by-nc].

[![CC BY-NC 4.0][cc-by-nc-image]][cc-by-nc]

[cc-by-nc]: https://creativecommons.org/licenses/by-nc/4.0/
[cc-by-nc-image]: https://licensebuttons.net/l/by-nc/4.0/88x31.png
[cc-by-nc-shield]: https://img.shields.io/badge/License-CC%20BY--NC%204.0-lightgrey.svg
