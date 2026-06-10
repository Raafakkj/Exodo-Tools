# Exodo Tools

```text
@@@@@@@@ @@@  @@@  @@@@@@  @@@@@@@   @@@@@@ 
@@!      @@!  !@@ @@!  @@@ @@!  @@@ @@!  @@@
@!!!:!    !@@!@!  @!@  !@! @!@  !@! @!@  !@!
!!:       !: :!!  !!:  !!! !!:  !!! !!:  !!!
: :: ::: :::  :::  : :. :  :: :  :   : :. : 
```

**Exodo Tools** is an open-source educational project focused on building a low-cost, portable, ESP32-based toolkit inspired by devices like the **M5Stick** and the **Flipper Zero**.

The goal of this project is to create an accessible learning platform for students, makers, and hardware enthusiasts who want to study embedded systems, menus, displays, buttons, communication modules, and basic hardware interaction in a practical and affordable way.

> This project is designed for **educational and ethical purposes only**.

---

## About the Project

Exodo Tools was created as a simple and affordable alternative for learning how small portable hardware tools work. Instead of focusing on expensive components or complex assembly, the project uses easy-to-find modules such as an ESP32, a small OLED display, and three navigation buttons.

The project can be used to study:

* ESP32 development
* OLED display interfaces
* Button-based menu systems
* I2C communication
* Basic embedded UI design
* Modular hardware expansion
* Safe and ethical radio-frequency experimentation
* Open-source hardware/software development

The NRF24L01 module is optional and should only be used in controlled, legal, and educational environments.

---

## Features

* Simple menu-based interface
* OLED display support
* Three-button navigation
* ESP32-based system
* Low-cost hardware design
* Optional NRF24L01 module support
* Beginner-friendly structure
* Open-source and easy to modify
* Designed for educational experiments

---

## Hardware Requirements

### Required Components

| Component    | Description                    |
| ------------ | ------------------------------ |
| ESP32        | DevKit or similar ESP32 board  |
| OLED Display | I2C OLED display, 0.92 inch    |
| 3 Buttons    | Left, OK, and Right navigation |
| Jumper Wires | For connections                |
| USB Cable    | For programming and power      |

### Optional Components

| Component             | Description                                              |
| --------------------- | -------------------------------------------------------- |
| NRF24L01 with Antenna | Optional radio module for controlled educational testing |
| Breadboard            | Useful for prototyping                                   |
| Case/Enclosure        | Optional, for a more polished handheld device            |

---

## Wiring

### OLED Display

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3V3       |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

### Buttons

Each button should be connected between the selected GPIO pin and GND.

| Button       | ESP32 Pin     |
| ------------ | ------------- |
| Left Button  | GPIO 32 + GND |
| OK Button    | GPIO 33 + GND |
| Right Button | GPIO 25 + GND |

---

## Simulation Without NRF24L01

The project can be tested without the NRF24L01 module. This is useful for developing the menu system, testing the OLED display, and validating the button navigation before adding extra modules.

<img width="639" height="650" alt="Exodo Tools simulation without NRF24L01" src="https://github.com/user-attachments/assets/a3f95183-5d00-44e5-83c2-91ec566e9b41" />

---

## Educational Purpose

Exodo Tools is meant to help beginners understand how embedded devices are built. It is not intended to be a commercial security device or a tool for unauthorized access, interference, or malicious activity.

This project can be used in:

* School projects
* College assignments
* Maker labs
* Embedded systems classes
* Personal learning
* Hardware prototyping
* Ethical technology research

---

## Ethical Use Policy

This project must only be used in legal, safe, and authorized environments.

You are responsible for following the laws and regulations of your country regarding radio communication, wireless testing, embedded devices, and electronic experimentation.

The Exodo Team does **not** support:

* Unauthorized access to devices or networks
* Signal interference or jamming
* Attacks against wireless systems
* Malicious use of radio modules
* Any activity that violates local laws or ethical standards

By using this project, you agree to use it only for educational, ethical, and legal purposes.

---

## Getting Started

1. Connect the OLED display to the ESP32 using the I2C pins.
2. Connect the three buttons to the configured GPIO pins and GND.
3. Open the project in the Arduino IDE or PlatformIO.
4. Install the required libraries.
5. Upload the code to the ESP32.
6. Test the menu navigation using the buttons.
7. Add optional modules only after the base system is working correctly.

---

## Recommended Libraries

Depending on the display and implementation, you may need libraries such as:

* `Wire.h`
* `Adafruit_GFX`
* `Adafruit_SSD1306`
* `Adafruit_SH110X`
* `RF24`
  Only required if using the NRF24L01 module.

---

## Roadmap

Possible future improvements:

* Better menu system
* Battery support
* 3D-printable case
* Module selection screen
* Settings menu
* Icons and animations
* Safer testing modes
* Documentation with diagrams
* PlatformIO support
* Example lessons for beginners

---

## Contributing

Contributions are welcome.

You can help by:

* Improving the documentation
* Reporting bugs
* Suggesting new educational features
* Creating safer examples
* Designing a case
* Improving the UI
* Cleaning and optimizing the code

Please keep all contributions aligned with the educational and ethical purpose of the project.

---

## License

This project is open source.
Add your preferred license here, such as:

* MIT License
* GPLv3
* Apache 2.0

Example:

```text
MIT License
Copyright (c) 2026 Exodo Team
```

---

# Exodo Tools — Português

**Exodo Tools** é um projeto open-source educacional focado na criação de uma ferramenta portátil de baixo custo baseada em ESP32, inspirada em dispositivos como o **M5Stick** e o **Flipper Zero**.

O objetivo do projeto é ajudar estudantes, makers e entusiastas de hardware a aprenderem, na prática, conceitos de sistemas embarcados, displays OLED, botões, menus, comunicação I2C e expansão modular.

> Este projeto foi criado apenas para fins **educacionais, éticos e legais**.

---

## Sobre o Projeto

A ideia do Exodo Tools é ser uma plataforma simples, barata e fácil de montar. Ele não busca ser uma cópia comercial de outros dispositivos, mas sim uma base de estudos para quem quer entender como ferramentas embarcadas funcionam.

Com ele, é possível estudar:

* Programação com ESP32
* Interfaces em display OLED
* Menus controlados por botões
* Comunicação I2C
* Organização de código embarcado
* Prototipagem de hardware
* Uso responsável de módulos externos
* Desenvolvimento open-source

O módulo NRF24L01 é opcional e deve ser usado somente em ambientes controlados, autorizados e com finalidade educacional.

---

## Componentes Necessários

| Componente   | Descrição                                   |
| ------------ | ------------------------------------------- |
| ESP32        | DevKit ou placa ESP32 semelhante            |
| Display OLED | Display OLED I2C de 0.92 polegadas          |
| 3 Botões     | Botões de navegação: esquerda, OK e direita |
| Jumpers      | Para as conexões                            |
| Cabo USB     | Para programação e alimentação              |

### Componentes Opcionais

| Componente          | Descrição                                            |
| ------------------- | ---------------------------------------------------- |
| NRF24L01 com antena | Módulo opcional para testes educacionais controlados |
| Protoboard          | Útil para prototipagem                               |
| Case                | Opcional, para deixar o projeto mais organizado      |

---

## Ligações

### Display OLED

| Pino do OLED | Pino do ESP32 |
| ------------ | ------------- |
| VCC          | 3V3           |
| GND          | GND           |
| SDA          | GPIO 21       |
| SCL          | GPIO 22       |

### Botões

Cada botão deve ser ligado entre o GPIO correspondente e o GND.

| Botão          | Pino do ESP32 |
| -------------- | ------------- |
| Botão Esquerdo | GPIO 32 + GND |
| Botão OK       | GPIO 33 + GND |
| Botão Direito  | GPIO 25 + GND |

---

## Uso Educacional e Ético

O Exodo Tools não deve ser usado para atividades maliciosas, invasões, interferência de sinais ou qualquer ação sem autorização.

O projeto é indicado para:

* Trabalhos escolares
* Projetos de faculdade
* Estudos de sistemas embarcados
* Laboratórios maker
* Prototipagem
* Aprendizado de eletrônica e programação

A Exodo Team não apoia qualquer uso ilegal, antiético ou prejudicial deste projeto.

Use com responsabilidade.
