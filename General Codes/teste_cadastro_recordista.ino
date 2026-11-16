
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
#include <string.h>

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Botoes
#define pushR 6
#define pushB 7
#define pushY 8
#define pushG 9

// EEPROM
#define EEPROM_NAME 1

char nomeRecordista[4] = "AAA";

// --------------------------------
// AGUARDAR SOLTAR BOTAO
// --------------------------------

void aguardarSoltar(int botao) {

  while (digitalRead(botao) == HIGH);

  delay(200);
}

// --------------------------------
// CADASTRAR RECORDISTA
// --------------------------------

void cadastrarRecordista() {

  char nome[4] = {'A', 'A', 'A', '\0'};

  int posicao = 0;

  while (posicao < 3) {

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(10, 0);
    display.print("NOVO RECORDISTA");

    display.setCursor(10, 13);
    display.print("Escolha as letras:");

    display.setTextSize(2);
    display.setCursor(35, 32);
    display.print(nome);

    // Indicador da letra selecionada
    display.setTextSize(1);
    display.setCursor(35 + (posicao * 12), 53);
    display.print("^");

    display.display();

    // Proxima letra
    if (digitalRead(pushG) == HIGH) {

      nome[posicao]++;

      if (nome[posicao] > 'Z') {
        nome[posicao] = 'A';
      }

      aguardarSoltar(pushG);
    }

    // Letra anterior
    if (digitalRead(pushR) == HIGH) {

      nome[posicao]--;

      if (nome[posicao] < 'A') {
        nome[posicao] = 'Z';
      }

      aguardarSoltar(pushR);
    }

    // Confirmar letra
    if (digitalRead(pushY) == HIGH) {

      posicao++;

      aguardarSoltar(pushY);
    }
  }

  // Salvar nome
  strcpy(nomeRecordista, nome);

  for (int i = 0; i < 3; i++) {
    EEPROM.update(EEPROM_NAME + i, nomeRecordista[i]);
  }

  // Mostrar resultado
  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(15, 5);
  display.print("CADASTRO CONCLUIDO!");

  display.setTextSize(2);
  display.setCursor(35, 30);
  display.print(nomeRecordista);

  display.display();

  delay(2000);
}

// --------------------------------
// SETUP
// --------------------------------

void setup() {

  pinMode(pushG, INPUT);
  pinMode(pushR, INPUT);
  pinMode(pushY, INPUT);
  pinMode(pushB, INPUT);

  // Inicializar OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.setTextColor(SSD1306_WHITE);

  // Recuperar nome anterior
  for (int i = 0; i < 3; i++) {
    nomeRecordista[i] = EEPROM.read(EEPROM_NAME + i);
  }

  nomeRecordista[3] = '\0';

  // Validar nome
  for (int i = 0; i < 3; i++) {

    if (nomeRecordista[i] < 'A' ||
        nomeRecordista[i] > 'Z') {

      strcpy(nomeRecordista, "AAA");
      break;
    }
  }

  // Tela inicial
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(20, 5);
  display.print("GENIUS");

  display.setTextSize(1);
  display.setCursor(10, 30);
  display.print("Cadastro de recordista");

  display.setCursor(10, 50);
  display.print("Pressione amarelo");

  display.display();

  // Aguarda iniciar cadastro
  while (digitalRead(pushY) == LOW);

  aguardarSoltar(pushY);

  cadastrarRecordista();
}

// --------------------------------
// LOOP
// --------------------------------

void loop() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(15, 10);
  display.print("NOME CADASTRADO:");

  display.setTextSize(2);
  display.setCursor(35, 30);
  display.print(nomeRecordista);

  display.display();
}
