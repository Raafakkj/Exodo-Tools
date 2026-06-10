EXODOTOOLS OLED ESP32 - GUIA DE MODULOS
=======================================

Abra esta pasta src como sketch Arduino.

O arquivo main.Ino fica na raiz e chama:

setupFirmware()
loopFirmware()

A logica fica dentro da subpasta interna src/. Esta pasta interna e
intencional, porque o Arduino compila recursivamente arquivos dentro de uma
subpasta chamada src.

ESTRUTURA
---------

main.Ino
  Entrada do programa.

src/core/Config.h
  Pinos, tamanho do display, endereco I2C e tempos da interface.

src/core/Types.h
  Tipos compartilhados: Screen, Icon, Button, Item e Menu.

src/core/AppState.h / src/core/AppState.cpp
  Estado global do display, botoes, menu ativo, pilha de menus e tela atual.

src/core/Firmware.h / src/core/Firmware.cpp
  setupFirmware() e loopFirmware(). Configure novos pinos aqui quando precisar.

src/navigation/Input.h / src/navigation/Input.cpp
  Leitura dos botoes, debounce, navegacao, Back e abertura de itens do menu.

src/navigation/MenuRegistry.h / src/navigation/MenuRegistry.cpp
  Lista de menus e submenus. Use este arquivo para colocar uma funcao na tela.

src/ui/Ui.h / src/ui/Ui.cpp
  Desenho do OLED, header, cards, loading, paginas e teste de display.

src/actions/HomeActions.h / src/actions/HomeActions.cpp
  Funcao da tela Home.

src/actions/WifiActions.h / src/actions/WifiActions.cpp
  Funcoes da aba WiFi.

src/actions/AppActions.h / src/actions/AppActions.cpp
  Funcoes da aba Apps.

src/actions/SettingsActions.h / src/actions/SettingsActions.cpp
  Funcoes da aba Settings.

COMO ADICIONAR UMA FUNCAO
-------------------------

1. Declare a funcao no header da area certa.

Exemplo em src/actions/AppActions.h:

void relayPulse();

2. Escreva a funcao no .cpp da mesma area.

Exemplo em src/actions/AppActions.cpp:

void relayPulse() {
  loading("RELE", "Pulso", 600);
  digitalWrite(26, HIGH);
  delay(200);
  digitalWrite(26, LOW);
  page("RELE", "Pulso enviado", "OK para voltar");
}

3. Adicione o item em src/navigation/MenuRegistry.cpp.

Exemplo:

{ "Relay", ICON_APPS, relayPulse, nullptr }

4. Se usar pino novo, configure em src/core/Firmware.cpp dentro de
setupFirmware().

Exemplo:

pinMode(26, OUTPUT);

FUNCOES UTEIS
-------------

page("TITULO", "Linha 1", "Linha 2");
  Mostra uma tela de resposta.

loading("TITULO", "Mensagem", 900);
  Mostra uma animacao de carregamento.

WOKWI
-----

A pasta ../wokwi tem a mesma estrutura modular. O arquivo principal do simulador
e wokwi/sketch.ino, e a logica fica em wokwi/src/.
