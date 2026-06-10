# Exodo Tools

<p align="center">
  <img width="680" height="240" alt="standard" src="https://github.com/user-attachments/assets/12cc1216-af11-4c02-826c-d80c36a8d175" />
</p>

<p align="center">
  <strong>An open-source ethical and educational hacking tool made by Brazilian students 🇧🇷</strong>
</p>

<p align="center">
  <a href="#english">
    <img src="https://img.shields.io/badge/Language-English-blue?style=for-the-badge" alt="English">
  </a>
  <a href="#portugues">
    <img src="https://img.shields.io/badge/Idioma-Português%20🇧🇷%20🇵🇹-green?style=for-the-badge" alt="Português">
  </a>
  <a href="#espanol">
    <img src="https://img.shields.io/badge/Idioma-Español-red?style=for-the-badge" alt="Español">
  </a>
</p>

---

<a id="english"></a>

# 🇺🇸 English

**Exodo Tools** is an open-source educational project focused on building a low-cost, portable, ESP32-based toolkit inspired by devices like the **M5Stick** and the **Flipper Zero**.

The goal of this project is to create an accessible learning platform for students, makers, and hardware enthusiasts who want to study embedded systems, menus, displays, buttons, communication modules, cybersecurity concepts, and basic hardware interaction in a practical and affordable way.

> This project is designed for **educational, ethical, and legal purposes only**.

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
* Cybersecurity learning concepts
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
* Focused on ethical hacking education

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

<p align="center">
  <img width="639" height="650" alt="Exodo Tools simulation without NRF24L01" src="https://github.com/user-attachments/assets/a3f95183-5d00-44e5-83c2-91ec566e9b41" />
</p>

---

## Educational Purpose

Exodo Tools is meant to help beginners understand how embedded devices are built. It is not intended to be a commercial security device or a tool for unauthorized access, interference, or malicious activity.

This project can be used in:

* School projects
* College assignments
* Maker labs
* Embedded systems classes
* Cybersecurity learning labs
* Personal learning
* Hardware prototyping
* Ethical technology research

---

## Ethical Use Policy

This project must only be used in legal, safe, and authorized environments.

You are responsible for following the laws and regulations of your country regarding radio communication, wireless testing, embedded devices, cybersecurity testing, and electronic experimentation.

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

`RF24` is only required if you are using the NRF24L01 module.

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

<a id="portugues"></a>

# 🇧🇷 🇵🇹 Português — Brasil / Portugal

**Exodo Tools** é um projeto open-source educacional focado na criação de uma ferramenta portátil de baixo custo baseada em ESP32, inspirada em dispositivos como o **M5Stick** e o **Flipper Zero**.

O objetivo deste projeto é criar uma plataforma de aprendizado acessível para estudantes, makers e entusiastas de hardware que desejam estudar sistemas embarcados, menus, displays, botões, módulos de comunicação, conceitos de cibersegurança e interação básica com hardware de forma prática e acessível.

> Este projeto foi desenvolvido apenas para fins **educacionais, éticos e legais**.

---

## Sobre o Projeto

O Exodo Tools foi criado como uma alternativa simples e acessível para aprender como pequenas ferramentas portáteis de hardware funcionam. Em vez de focar em componentes caros ou montagens complexas, o projeto utiliza módulos fáceis de encontrar, como um ESP32, um pequeno display OLED e três botões de navegação.

O projeto pode ser usado para estudar:

* Desenvolvimento com ESP32
* Interfaces com display OLED
* Sistemas de menu baseados em botões
* Comunicação I2C
* Design básico de interface embarcada
* Expansão modular de hardware
* Conceitos de aprendizado em cibersegurança
* Experimentação segura e ética com radiofrequência
* Desenvolvimento open-source de hardware/software

O módulo NRF24L01 é opcional e deve ser usado apenas em ambientes controlados, legais e educacionais.

---

## Funcionalidades

* Interface simples baseada em menu
* Suporte a display OLED
* Navegação com três botões
* Sistema baseado em ESP32
* Design de hardware de baixo custo
* Suporte opcional ao módulo NRF24L01
* Estrutura amigável para iniciantes
* Open-source e fácil de modificar
* Projetado para experimentos educacionais
* Focado em educação sobre hacking ético

---

## Requisitos de Hardware

### Componentes Necessários

| Componente   | Descrição                             |
| ------------ | ------------------------------------- |
| ESP32        | DevKit ou placa ESP32 semelhante      |
| Display OLED | Display OLED I2C de 0.92 polegadas    |
| 3 Botões     | Navegação para esquerda, OK e direita |
| Jumpers      | Para as conexões                      |
| Cabo USB     | Para programação e alimentação        |

### Componentes Opcionais

| Componente          | Descrição                                                     |
| ------------------- | ------------------------------------------------------------- |
| NRF24L01 com antena | Módulo de rádio opcional para testes educacionais controlados |
| Protoboard          | Útil para prototipagem                                        |
| Case/Gabinete       | Opcional, para deixar o dispositivo portátil mais organizado  |

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

Cada botão deve ser conectado entre o GPIO selecionado e o GND.

| Botão          | Pino do ESP32 |
| -------------- | ------------- |
| Botão Esquerdo | GPIO 32 + GND |
| Botão OK       | GPIO 33 + GND |
| Botão Direito  | GPIO 25 + GND |

---

## Simulação Sem NRF24L01

O projeto pode ser testado sem o módulo NRF24L01. Isso é útil para desenvolver o sistema de menu, testar o display OLED e validar a navegação por botões antes de adicionar módulos extras.

<p align="center">
  <img width="639" height="650" alt="Simulação do Exodo Tools sem NRF24L01" src="https://github.com/user-attachments/assets/a3f95183-5d00-44e5-83c2-91ec566e9b41" />
</p>

---

## Propósito Educacional

O Exodo Tools foi criado para ajudar iniciantes a entenderem como dispositivos embarcados são construídos. Ele não tem a intenção de ser um dispositivo comercial de segurança, nem uma ferramenta para acesso não autorizado, interferência ou atividades maliciosas.

Este projeto pode ser usado em:

* Projetos escolares
* Trabalhos de faculdade
* Laboratórios maker
* Aulas de sistemas embarcados
* Laboratórios de aprendizado em cibersegurança
* Aprendizado pessoal
* Prototipagem de hardware
* Pesquisa ética em tecnologia

---

## Política de Uso Ético

Este projeto deve ser usado apenas em ambientes legais, seguros e autorizados.

Você é responsável por seguir as leis e regulamentações do seu país sobre comunicação por rádio, testes sem fio, dispositivos embarcados, testes de cibersegurança e experimentação eletrônica.

A Exodo Team **não** apoia:

* Acesso não autorizado a dispositivos ou redes
* Interferência ou bloqueio de sinais
* Ataques contra sistemas sem fio
* Uso malicioso de módulos de rádio
* Qualquer atividade que viole leis locais ou padrões éticos

Ao usar este projeto, você concorda em utilizá-lo apenas para fins educacionais, éticos e legais.

---

## Primeiros Passos

1. Conecte o display OLED ao ESP32 usando os pinos I2C.
2. Conecte os três botões aos GPIOs configurados e ao GND.
3. Abra o projeto na Arduino IDE ou no PlatformIO.
4. Instale as bibliotecas necessárias.
5. Envie o código para o ESP32.
6. Teste a navegação do menu usando os botões.
7. Adicione módulos opcionais apenas depois que o sistema base estiver funcionando corretamente.

---

## Bibliotecas Recomendadas

Dependendo do display e da implementação, você pode precisar de bibliotecas como:

* `Wire.h`
* `Adafruit_GFX`
* `Adafruit_SSD1306`
* `Adafruit_SH110X`
* `RF24`

A biblioteca `RF24` só é necessária se você for usar o módulo NRF24L01.

---

## Roadmap

Possíveis melhorias futuras:

* Sistema de menu melhorado
* Suporte a bateria
* Case imprimível em 3D
* Tela de seleção de módulos
* Menu de configurações
* Ícones e animações
* Modos de teste mais seguros
* Documentação com diagramas
* Suporte ao PlatformIO
* Exemplos de aulas para iniciantes

---

## Contribuindo

Contribuições são bem-vindas.

Você pode ajudar:

* Melhorando a documentação
* Reportando bugs
* Sugerindo novos recursos educacionais
* Criando exemplos mais seguros
* Projetando uma case
* Melhorando a interface
* Limpando e otimizando o código

Por favor, mantenha todas as contribuições alinhadas ao propósito educacional e ético do projeto.

---

## Licença

Este projeto é open-source.

Adicione aqui a licença de sua preferência, como:

* MIT License
* GPLv3
* Apache 2.0

Exemplo:

```text
MIT License
Copyright (c) 2026 Exodo Team
```

---

<a id="espanol"></a>

# 🇪🇸 Español

**Exodo Tools** es un proyecto educativo open-source enfocado en la creación de una herramienta portátil de bajo costo basada en ESP32, inspirada en dispositivos como el **M5Stick** y el **Flipper Zero**.

El objetivo de este proyecto es crear una plataforma de aprendizaje accesible para estudiantes, makers y entusiastas del hardware que quieran estudiar sistemas embebidos, menús, pantallas, botones, módulos de comunicación, conceptos de ciberseguridad e interacción básica con hardware de una forma práctica y económica.

> Este proyecto está diseñado únicamente para fines **educativos, éticos y legales**.

---

## Sobre el Proyecto

Exodo Tools fue creado como una alternativa simple y accesible para aprender cómo funcionan pequeñas herramientas portátiles de hardware. En lugar de centrarse en componentes costosos o montajes complejos, el proyecto utiliza módulos fáciles de encontrar, como un ESP32, una pequeña pantalla OLED y tres botones de navegación.

El proyecto se puede usar para estudiar:

* Desarrollo con ESP32
* Interfaces con pantalla OLED
* Sistemas de menú basados en botones
* Comunicación I2C
* Diseño básico de interfaces embebidas
* Expansión modular de hardware
* Conceptos de aprendizaje en ciberseguridad
* Experimentación segura y ética con radiofrecuencia
* Desarrollo open-source de hardware/software

El módulo NRF24L01 es opcional y solo debe utilizarse en entornos controlados, legales y educativos.

---

## Características

* Interfaz simple basada en menú
* Soporte para pantalla OLED
* Navegación con tres botones
* Sistema basado en ESP32
* Diseño de hardware de bajo costo
* Soporte opcional para el módulo NRF24L01
* Estructura amigable para principiantes
* Open-source y fácil de modificar
* Diseñado para experimentos educativos
* Enfocado en la educación sobre hacking ético

---

## Requisitos de Hardware

### Componentes Necesarios

| Componente    | Descripción                        |
| ------------- | ---------------------------------- |
| ESP32         | DevKit o placa ESP32 similar       |
| Pantalla OLED | Pantalla OLED I2C de 0.92 pulgadas |
| 3 Botones     | Navegación izquierda, OK y derecha |
| Cables Jumper | Para las conexiones                |
| Cable USB     | Para programación y alimentación   |

### Componentes Opcionales

| Componente          | Descripción                                                  |
| ------------------- | ------------------------------------------------------------ |
| NRF24L01 con antena | Módulo de radio opcional para pruebas educativas controladas |
| Protoboard          | Útil para prototipado                                        |
| Carcasa/Gabinete    | Opcional, para un dispositivo portátil más organizado        |

---

## Conexiones

### Pantalla OLED

| Pin OLED | Pin ESP32 |
| -------- | --------- |
| VCC      | 3V3       |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

### Botones

Cada botón debe conectarse entre el pin GPIO seleccionado y GND.

| Botón           | Pin ESP32     |
| --------------- | ------------- |
| Botón Izquierdo | GPIO 32 + GND |
| Botón OK        | GPIO 33 + GND |
| Botón Derecho   | GPIO 25 + GND |

---

## Simulación Sin NRF24L01

El proyecto se puede probar sin el módulo NRF24L01. Esto es útil para desarrollar el sistema de menú, probar la pantalla OLED y validar la navegación con botones antes de añadir módulos adicionales.

<p align="center">
  <img width="639" height="650" alt="Simulación de Exodo Tools sin NRF24L01" src="https://github.com/user-attachments/assets/a3f95183-5d00-44e5-83c2-91ec566e9b41" />
</p>

---

## Propósito Educativo

Exodo Tools está pensado para ayudar a principiantes a entender cómo se construyen los dispositivos embebidos. No está destinado a ser un dispositivo comercial de seguridad ni una herramienta para acceso no autorizado, interferencia o actividades maliciosas.

Este proyecto se puede usar en:

* Proyectos escolares
* Trabajos universitarios
* Laboratorios maker
* Clases de sistemas embebidos
* Laboratorios de aprendizaje en ciberseguridad
* Aprendizaje personal
* Prototipado de hardware
* Investigación ética en tecnología

---

## Política de Uso Ético

Este proyecto debe utilizarse únicamente en entornos legales, seguros y autorizados.

Tú eres responsable de seguir las leyes y regulaciones de tu país sobre comunicación por radio, pruebas inalámbricas, dispositivos embebidos, pruebas de ciberseguridad y experimentación electrónica.

El equipo Exodo **no** apoya:

* Acceso no autorizado a dispositivos o redes
* Interferencia o bloqueo de señales
* Ataques contra sistemas inalámbricos
* Uso malicioso de módulos de radio
* Cualquier actividad que viole leyes locales o estándares éticos

Al usar este proyecto, aceptas utilizarlo únicamente con fines educativos, éticos y legales.

---

## Primeros Pasos

1. Conecta la pantalla OLED al ESP32 usando los pines I2C.
2. Conecta los tres botones a los pines GPIO configurados y a GND.
3. Abre el proyecto en Arduino IDE o PlatformIO.
4. Instala las bibliotecas necesarias.
5. Sube el código al ESP32.
6. Prueba la navegación del menú usando los botones.
7. Añade módulos opcionales solo después de que el sistema base funcione correctamente.

---

## Bibliotecas Recomendadas

Dependiendo de la pantalla y de la implementación, puedes necesitar bibliotecas como:

* `Wire.h`
* `Adafruit_GFX`
* `Adafruit_SSD1306`
* `Adafruit_SH110X`
* `RF24`

La biblioteca `RF24` solo es necesaria si vas a usar el módulo NRF24L01.

---

## Roadmap

Posibles mejoras futuras:

* Mejor sistema de menú
* Soporte para batería
* Carcasa imprimible en 3D
* Pantalla de selección de módulos
* Menú de configuración
* Iconos y animaciones
* Modos de prueba más seguros
* Documentación con diagramas
* Soporte para PlatformIO
* Ejemplos de lecciones para principiantes

---

## Contribuir

Las contribuciones son bienvenidas.

Puedes ayudar:

* Mejorando la documentación
* Reportando errores
* Sugiriendo nuevas funciones educativas
* Creando ejemplos más seguros
* Diseñando una carcasa
* Mejorando la interfaz
* Limpiando y optimizando el código

Por favor, mantén todas las contribuciones alineadas con el propósito educativo y ético del proyecto.

---

## Licencia

Este proyecto es open-source.

Añade aquí la licencia que prefieras, como:

* MIT License
* GPLv3
* Apache 2.0

Ejemplo:

```text
MIT License
Copyright (c) 2026 Exodo Team
```
