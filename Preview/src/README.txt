EXODOTOOLS OLED ESP32 - BASIC FIRMWARE GUIDE
============================================

ENGLISH
-------

1. What this firmware does

This project is a simple ESP32 firmware for an SSD1306 OLED display and three
buttons. It provides:

- A main menu.
- Submenus.
- A loading animation.
- Result pages for your functions.
- A display test screen.
- A clean area where you can add your own functions.

The main source file is:

src/main.Ino

2. Hardware pins

OLED:

- VCC -> 3V3
- GND -> GND
- SDA -> GPIO 21
- SCL -> GPIO 22

Buttons:

- LEFT  -> GPIO 32 and GND
- OK    -> GPIO 33 and GND
- RIGHT -> GPIO 25 and GND

The buttons use INPUT_PULLUP. This means the button connects the pin to GND
when pressed.

3. Basic configuration

At the top of src/main.Ino you can change:

constexpr uint8_t H = 64;
constexpr uint8_t OLED = 0x3C;

Use H = 32 if your display is 128x32.
Try OLED = 0x3D if the display does not start.

4. Where to add your own code

Use this section:

// ===== USER FUNCTIONS =====

This is where you edit existing functions or add new ones.

5. Important helper functions

Use page() to show a result screen:

page("TITLE", "Line 1", "Line 2");

Use loading() to show an animated loading screen:

loading("TITLE", "Message", 900);

The last number is the duration in milliseconds.

6. How to edit an existing function

Example:

void appOne() {
  loading("APP 1", "Running", 800);
  page("APP 1", "Replace this", "with your code");
}

Replace the inside with your own code:

void appOne() {
  loading("RELAY", "Turning on", 700);
  digitalWrite(26, HIGH);
  page("RELAY", "Enabled", "GPIO 26");
}

If you use a new pin, configure it in setup():

pinMode(26, OUTPUT);

7. How to add a new function

Step 1: declare it before the MENUS section:

void relayPulse();

Step 2: create it inside USER FUNCTIONS:

void relayPulse() {
  loading("RELAY", "Pulse", 600);
  digitalWrite(26, HIGH);
  delay(200);
  digitalWrite(26, LOW);
  page("RELAY", "Pulse sent", "OK to return");
}

Step 3: add it to a menu:

const Item appItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Action 1", ICON_APPS, appOne, nullptr },
  { "Action 2", ICON_APPS, appTwo, nullptr },
  { "Relay", ICON_APPS, relayPulse, nullptr }
};

8. How menu items work

Each menu item has this format:

{ "Name", ICON_APPS, functionName, submenuName }

Function item:

{ "Status", ICON_SYSTEM, status, nullptr }

Submenu item:

{ "WiFi", ICON_WIFI, nullptr, &wifiMenu }

Use nullptr for the field you are not using.

9. Ethical project note

Keep functions defensive and authorized. Good examples are passive WiFi scans,
channel analysis, board diagnostics, I2C scan, and sensor testing.


ESPANOL
-------

1. Que hace este firmware

Este proyecto es un firmware simple para ESP32 con pantalla OLED SSD1306 y tres
botones. Incluye:

- Menu principal.
- Submenus.
- Animacion de carga.
- Pantallas de resultado para tus funciones.
- Prueba de pantalla.
- Un area limpia para agregar tus propias funciones.

El archivo principal es:

src/main.Ino

2. Pines de hardware

OLED:

- VCC -> 3V3
- GND -> GND
- SDA -> GPIO 21
- SCL -> GPIO 22

Botones:

- LEFT  -> GPIO 32 y GND
- OK    -> GPIO 33 y GND
- RIGHT -> GPIO 25 y GND

Los botones usan INPUT_PULLUP. El boton conecta el pin a GND cuando se presiona.

3. Configuracion basica

En la parte superior de src/main.Ino puedes cambiar:

constexpr uint8_t H = 64;
constexpr uint8_t OLED = 0x3C;

Usa H = 32 si tu pantalla es 128x32.
Prueba OLED = 0x3D si la pantalla no inicia.

4. Donde agregar tu codigo

Usa esta seccion:

// ===== USER FUNCTIONS =====

Aqui puedes editar funciones existentes o agregar nuevas.

5. Funciones auxiliares importantes

Usa page() para mostrar una pantalla de resultado:

page("TITULO", "Linea 1", "Linea 2");

Usa loading() para mostrar una animacion de carga:

loading("TITULO", "Mensaje", 900);

El ultimo numero es el tiempo en milisegundos.

6. Como editar una funcion existente

Ejemplo:

void appOne() {
  loading("APP 1", "Running", 800);
  page("APP 1", "Replace this", "with your code");
}

Cambia el contenido por tu codigo:

void appOne() {
  loading("RELAY", "Turning on", 700);
  digitalWrite(26, HIGH);
  page("RELAY", "Enabled", "GPIO 26");
}

Si usas un pin nuevo, configuralo en setup():

pinMode(26, OUTPUT);

7. Como agregar una funcion nueva

Paso 1: declarala antes de la seccion MENUS:

void relayPulse();

Paso 2: creala dentro de USER FUNCTIONS:

void relayPulse() {
  loading("RELAY", "Pulse", 600);
  digitalWrite(26, HIGH);
  delay(200);
  digitalWrite(26, LOW);
  page("RELAY", "Pulse sent", "OK to return");
}

Paso 3: agregala a un menu:

const Item appItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Action 1", ICON_APPS, appOne, nullptr },
  { "Action 2", ICON_APPS, appTwo, nullptr },
  { "Relay", ICON_APPS, relayPulse, nullptr }
};

8. Como funcionan los items del menu

Cada item tiene este formato:

{ "Nombre", ICON_APPS, nombreFuncion, nombreSubmenu }

Item de funcion:

{ "Status", ICON_SYSTEM, status, nullptr }

Item de submenu:

{ "WiFi", ICON_WIFI, nullptr, &wifiMenu }

Usa nullptr en el campo que no estas usando.

9. Nota de proyecto etico

Manten las funciones defensivas y autorizadas. Buenos ejemplos son escaneo WiFi
pasivo, analisis de canales, diagnostico de la placa, I2C scan y pruebas de
sensores.


PORTUGUES
---------

1. O que este firmware faz

Este projeto e um firmware simples para ESP32 com tela OLED SSD1306 e tres
botoes. Ele inclui:

- Menu principal.
- Submenus.
- Animacao de carregamento.
- Telas de resultado para suas funcoes.
- Teste de display.
- Uma area limpa para adicionar suas proprias funcoes.

O arquivo principal e:

src/main.Ino

2. Pinos do hardware

OLED:

- VCC -> 3V3
- GND -> GND
- SDA -> GPIO 21
- SCL -> GPIO 22

Botoes:

- LEFT  -> GPIO 32 e GND
- OK    -> GPIO 33 e GND
- RIGHT -> GPIO 25 e GND

Os botoes usam INPUT_PULLUP. O botao conecta o pino ao GND quando pressionado.

3. Configuracao basica

No topo de src/main.Ino voce pode alterar:

constexpr uint8_t H = 64;
constexpr uint8_t OLED = 0x3C;

Use H = 32 se sua tela for 128x32.
Teste OLED = 0x3D se a tela nao iniciar.

4. Onde adicionar seu codigo

Use esta secao:

// ===== USER FUNCTIONS =====

Aqui voce pode editar funcoes existentes ou adicionar novas.

5. Funcoes auxiliares importantes

Use page() para mostrar uma tela de resultado:

page("TITULO", "Linha 1", "Linha 2");

Use loading() para mostrar uma animacao de carregamento:

loading("TITULO", "Mensagem", 900);

O ultimo numero e o tempo em milissegundos.

6. Como editar uma funcao existente

Exemplo:

void appOne() {
  loading("APP 1", "Running", 800);
  page("APP 1", "Replace this", "with your code");
}

Troque o conteudo pelo seu codigo:

void appOne() {
  loading("RELAY", "Turning on", 700);
  digitalWrite(26, HIGH);
  page("RELAY", "Enabled", "GPIO 26");
}

Se usar um pino novo, configure no setup():

pinMode(26, OUTPUT);

7. Como adicionar uma funcao nova

Passo 1: declare antes da secao MENUS:

void relayPulse();

Passo 2: crie dentro de USER FUNCTIONS:

void relayPulse() {
  loading("RELAY", "Pulse", 600);
  digitalWrite(26, HIGH);
  delay(200);
  digitalWrite(26, LOW);
  page("RELAY", "Pulse sent", "OK to return");
}

Passo 3: adicione em um menu:

const Item appItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Action 1", ICON_APPS, appOne, nullptr },
  { "Action 2", ICON_APPS, appTwo, nullptr },
  { "Relay", ICON_APPS, relayPulse, nullptr }
};

8. Como os itens do menu funcionam

Cada item tem este formato:

{ "Nome", ICON_APPS, nomeFuncao, nomeSubmenu }

Item de funcao:

{ "Status", ICON_SYSTEM, status, nullptr }

Item de submenu:

{ "WiFi", ICON_WIFI, nullptr, &wifiMenu }

Use nullptr no campo que voce nao estiver usando.

9. Nota de projeto etico

Mantenha as funcoes defensivas e autorizadas. Bons exemplos sao scan WiFi
passivo, analise de canais, diagnostico da placa, I2C scan e testes de sensores.
