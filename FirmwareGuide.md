# ExodoTools OLED ESP32 — Basic Firmware Guide

<p align="center">
  <strong>Basic firmware documentation for the ExodoTools ESP32 OLED interface.</strong>
</p>

<p align="center">
  <a href="#english">
    <img src="https://img.shields.io/badge/Language-English-blue?style=for-the-badge" alt="English">
  </a>
  <a href="#espanol">
    <img src="https://img.shields.io/badge/Idioma-Español-red?style=for-the-badge" alt="Español">
  </a>
  <a href="#portugues">
    <img src="https://img.shields.io/badge/Idioma-Português%20🇧🇷%20🇵🇹-green?style=for-the-badge" alt="Português">
  </a>
</p>

---

<a id="english"></a>

# 🇺🇸 English

## 1. What This Firmware Does

This project is a simple ESP32 firmware for an **SSD1306 OLED display** and three navigation buttons.

It provides:

* A main menu
* Submenus
* A loading animation
* Result pages for your functions
* A display test screen
* A clean area where you can add your own functions

The main source file is:

```text
src/main.ino
```

---

## 2. Hardware Pins

### OLED Display

| OLED Pin | ESP32 Pin |
| -------- | --------- |
| VCC      | 3V3       |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

### Buttons

| Button | ESP32 Pin     |
| ------ | ------------- |
| LEFT   | GPIO 32 + GND |
| OK     | GPIO 33 + GND |
| RIGHT  | GPIO 25 + GND |

The buttons use `INPUT_PULLUP`.

This means the button connects the GPIO pin to `GND` when pressed.

---

## 3. Basic Configuration

At the top of `src/main.ino`, you can change:

```cpp
constexpr uint8_t H = 64;
constexpr uint8_t OLED = 0x3C;
```

Use:

```cpp
constexpr uint8_t H = 32;
```

if your display is `128x32`.

Try:

```cpp
constexpr uint8_t OLED = 0x3D;
```

if the display does not start.

---

## 4. Where to Add Your Own Code

Use this section:

```cpp
// ===== USER FUNCTIONS =====
```

This is where you can edit existing functions or add new ones.

---

## 5. Important Helper Functions

Use `page()` to show a result screen:

```cpp
page("TITLE", "Line 1", "Line 2");
```

Use `loading()` to show an animated loading screen:

```cpp
loading("TITLE", "Message", 900);
```

The last number is the duration in milliseconds.

---

## 6. How to Edit an Existing Function

Example:

```cpp
void appOne() {
  loading("APP 1", "Running", 800);
  page("APP 1", "Replace this", "with your code");
}
```

Replace the inside with your own code:

```cpp
void appOne() {
  loading("RELAY", "Turning on", 700);
  digitalWrite(26, HIGH);
  page("RELAY", "Enabled", "GPIO 26");
}
```

If you use a new pin, configure it in `setup()`:

```cpp
pinMode(26, OUTPUT);
```

---

## 7. How to Add a New Function

### Step 1: Declare the Function

Declare it before the `MENUS` section:

```cpp
void relayPulse();
```

### Step 2: Create the Function

Create it inside the `USER FUNCTIONS` section:

```cpp
void relayPulse() {
  loading("RELAY", "Pulse", 600);
  digitalWrite(26, HIGH);
  delay(200);
  digitalWrite(26, LOW);
  page("RELAY", "Pulse sent", "OK to return");
}
```

### Step 3: Add It to a Menu

Add the function to a menu item:

```cpp
const Item appItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Action 1", ICON_APPS, appOne, nullptr },
  { "Action 2", ICON_APPS, appTwo, nullptr },
  { "Relay", ICON_APPS, relayPulse, nullptr }
};
```

---

## 8. How Menu Items Work

Each menu item follows this format:

```cpp
{ "Name", ICON_APPS, functionName, submenuName }
```

Function item:

```cpp
{ "Status", ICON_SYSTEM, status, nullptr }
```

Submenu item:

```cpp
{ "WiFi", ICON_WIFI, nullptr, &wifiMenu }
```

Use `nullptr` for the field you are not using.

---

## 9. Ethical Project Note

Keep all functions defensive, educational, and authorized.

Good examples include:

* Passive WiFi scans
* Channel analysis
* Board diagnostics
* I2C scanning
* Sensor testing
* Display testing
* Button testing

Do not use this firmware to build or run malicious tools, unauthorized access features, signal interference functions, or anything that violates local laws.

---

<a id="espanol"></a>

# 🇪🇸 Español

## 1. Qué Hace Este Firmware

Este proyecto es un firmware simple para ESP32 con una **pantalla OLED SSD1306** y tres botones de navegación.

Incluye:

* Un menú principal
* Submenús
* Una animación de carga
* Pantallas de resultado para tus funciones
* Una pantalla de prueba del display
* Un área limpia donde puedes agregar tus propias funciones

El archivo principal es:

```text
src/main.ino
```

---

## 2. Pines de Hardware

### Pantalla OLED

| Pin OLED | Pin ESP32 |
| -------- | --------- |
| VCC      | 3V3       |
| GND      | GND       |
| SDA      | GPIO 21   |
| SCL      | GPIO 22   |

### Botones

| Botón | Pin ESP32     |
| ----- | ------------- |
| LEFT  | GPIO 32 + GND |
| OK    | GPIO 33 + GND |
| RIGHT | GPIO 25 + GND |

Los botones usan `INPUT_PULLUP`.

Esto significa que el botón conecta el pin GPIO a `GND` cuando se presiona.

---

## 3. Configuración Básica

En la parte superior de `src/main.ino`, puedes cambiar:

```cpp
constexpr uint8_t H = 64;
constexpr uint8_t OLED = 0x3C;
```

Usa:

```cpp
constexpr uint8_t H = 32;
```

si tu pantalla es `128x32`.

Prueba:

```cpp
constexpr uint8_t OLED = 0x3D;
```

si la pantalla no inicia.

---

## 4. Dónde Agregar Tu Propio Código

Usa esta sección:

```cpp
// ===== USER FUNCTIONS =====
```

Aquí puedes editar funciones existentes o agregar nuevas.

---

## 5. Funciones Auxiliares Importantes

Usa `page()` para mostrar una pantalla de resultado:

```cpp
page("TÍTULO", "Línea 1", "Línea 2");
```

Usa `loading()` para mostrar una animación de carga:

```cpp
loading("TÍTULO", "Mensaje", 900);
```

El último número es la duración en milisegundos.

---

## 6. Cómo Editar una Función Existente

Ejemplo:

```cpp
void appOne() {
  loading("APP 1", "Running", 800);
  page("APP 1", "Replace this", "with your code");
}
```

Reemplaza el contenido con tu propio código:

```cpp
void appOne() {
  loading("RELAY", "Turning on", 700);
  digitalWrite(26, HIGH);
  page("RELAY", "Enabled", "GPIO 26");
}
```

Si usas un pin nuevo, configúralo en `setup()`:

```cpp
pinMode(26, OUTPUT);
```

---

## 7. Cómo Agregar una Nueva Función

### Paso 1: Declara la Función

Declárala antes de la sección `MENUS`:

```cpp
void relayPulse();
```

### Paso 2: Crea la Función

Créala dentro de la sección `USER FUNCTIONS`:

```cpp
void relayPulse() {
  loading("RELAY", "Pulse", 600);
  digitalWrite(26, HIGH);
  delay(200);
  digitalWrite(26, LOW);
  page("RELAY", "Pulse sent", "OK to return");
}
```

### Paso 3: Agrégala a un Menú

Agrega la función a un ítem del menú:

```cpp
const Item appItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Action 1", ICON_APPS, appOne, nullptr },
  { "Action 2", ICON_APPS, appTwo, nullptr },
  { "Relay", ICON_APPS, relayPulse, nullptr }
};
```

---

## 8. Cómo Funcionan los Ítems del Menú

Cada ítem del menú sigue este formato:

```cpp
{ "Nombre", ICON_APPS, nombreFuncion, nombreSubmenu }
```

Ítem de función:

```cpp
{ "Status", ICON_SYSTEM, status, nullptr }
```

Ítem de submenú:

```cpp
{ "WiFi", ICON_WIFI, nullptr, &wifiMenu }
```

Usa `nullptr` en el campo que no estés utilizando.

---

## 9. Nota de Proyecto Ético

Mantén todas las funciones defensivas, educativas y autorizadas.

Buenos ejemplos incluyen:

* Escaneos WiFi pasivos
* Análisis de canales
* Diagnóstico de la placa
* Escaneo I2C
* Pruebas de sensores
* Pruebas de display
* Pruebas de botones

No uses este firmware para construir o ejecutar herramientas maliciosas, funciones de acceso no autorizado, interferencia de señales o cualquier cosa que viole las leyes locales.

---

<a id="portugues"></a>

# 🇧🇷 🇵🇹 Português

## 1. O Que Este Firmware Faz

Este projeto é um firmware simples para ESP32 com uma **tela OLED SSD1306** e três botões de navegação.

Ele inclui:

* Um menu principal
* Submenus
* Uma animação de carregamento
* Telas de resultado para suas funções
* Uma tela de teste do display
* Uma área limpa onde você pode adicionar suas próprias funções

O arquivo principal é:

```text
src/main.ino
```

---

## 2. Pinos do Hardware

### Display OLED

| Pino do OLED | Pino do ESP32 |
| ------------ | ------------- |
| VCC          | 3V3           |
| GND          | GND           |
| SDA          | GPIO 21       |
| SCL          | GPIO 22       |

### Botões

| Botão | Pino do ESP32 |
| ----- | ------------- |
| LEFT  | GPIO 32 + GND |
| OK    | GPIO 33 + GND |
| RIGHT | GPIO 25 + GND |

Os botões usam `INPUT_PULLUP`.

Isso significa que o botão conecta o pino GPIO ao `GND` quando é pressionado.

---

## 3. Configuração Básica

No topo de `src/main.ino`, você pode alterar:

```cpp
constexpr uint8_t H = 64;
constexpr uint8_t OLED = 0x3C;
```

Use:

```cpp
constexpr uint8_t H = 32;
```

se sua tela for `128x32`.

Teste:

```cpp
constexpr uint8_t OLED = 0x3D;
```

se o display não iniciar.

---

## 4. Onde Adicionar Seu Próprio Código

Use esta seção:

```cpp
// ===== USER FUNCTIONS =====
```

Aqui você pode editar funções existentes ou adicionar novas.

---

## 5. Funções Auxiliares Importantes

Use `page()` para mostrar uma tela de resultado:

```cpp
page("TÍTULO", "Linha 1", "Linha 2");
```

Use `loading()` para mostrar uma animação de carregamento:

```cpp
loading("TÍTULO", "Mensagem", 900);
```

O último número é a duração em milissegundos.

---

## 6. Como Editar Uma Função Existente

Exemplo:

```cpp
void appOne() {
  loading("APP 1", "Running", 800);
  page("APP 1", "Replace this", "with your code");
}
```

Troque o conteúdo pelo seu próprio código:

```cpp
void appOne() {
  loading("RELAY", "Turning on", 700);
  digitalWrite(26, HIGH);
  page("RELAY", "Enabled", "GPIO 26");
}
```

Se você usar um pino novo, configure-o no `setup()`:

```cpp
pinMode(26, OUTPUT);
```

---

## 7. Como Adicionar Uma Nova Função

### Passo 1: Declare a Função

Declare antes da seção `MENUS`:

```cpp
void relayPulse();
```

### Passo 2: Crie a Função

Crie dentro da seção `USER FUNCTIONS`:

```cpp
void relayPulse() {
  loading("RELAY", "Pulse", 600);
  digitalWrite(26, HIGH);
  delay(200);
  digitalWrite(26, LOW);
  page("RELAY", "Pulse sent", "OK to return");
}
```

### Passo 3: Adicione a Um Menu

Adicione a função a um item do menu:

```cpp
const Item appItems[] = {
  { "Back", ICON_BACK, back, nullptr },
  { "Action 1", ICON_APPS, appOne, nullptr },
  { "Action 2", ICON_APPS, appTwo, nullptr },
  { "Relay", ICON_APPS, relayPulse, nullptr }
};
```

---

## 8. Como os Itens do Menu Funcionam

Cada item do menu segue este formato:

```cpp
{ "Nome", ICON_APPS, nomeFuncao, nomeSubmenu }
```

Item de função:

```cpp
{ "Status", ICON_SYSTEM, status, nullptr }
```

Item de submenu:

```cpp
{ "WiFi", ICON_WIFI, nullptr, &wifiMenu }
```

Use `nullptr` no campo que você não estiver utilizando.

---

## 9. Nota de Projeto Ético

Mantenha todas as funções defensivas, educacionais e autorizadas.

Bons exemplos incluem:

* Scans WiFi passivos
* Análise de canais
* Diagnóstico da placa
* Scan I2C
* Testes de sensores
* Testes do display
* Testes dos botões

Não use este firmware para criar ou executar ferramentas maliciosas, funções de acesso não autorizado, interferência de sinais ou qualquer coisa que viole as leis locais.
