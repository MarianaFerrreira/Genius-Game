// Mudanças feitas: adição de registro de nome do recordista

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>
#include <string.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// LEDs
#define ledG 2
#define ledY 3
#define ledB 4
#define ledR 5

// Botoes
#define pushR 6
#define pushB 7
#define pushY 8
#define pushG 9

// Buzzer
#define buz 10

// EEPROM
#define EEPROM_RECORD 0
#define EEPROM_NAME 1

byte sequencia[90];

int rodada = 0;
int recorde = 0;
bool gameOver = false;

// Nome do recordista
char nomeRecordista[4] = "AAA";

// Ordem: Verde, Vermelho, Amarelo, Azul
int leds[4] = {ledG, ledR, ledY, ledB};
int tons[4] = {392, 440, 554, 659};

void tocarMelodia(const int notas[], const int dur[],
                  int quantidade, bool piscarLeds) {

  for (int i = 0; i < quantidade; i++) {

    tone(buz, notas[i]);

    if (piscarLeds) {
      for (int j = 0; j < 4; j++) {
        digitalWrite(leds[j], HIGH);
      }
    }

    delay(dur[i]);

    noTone(buz);

    for (int j = 0; j < 4; j++) {
      digitalWrite(leds[j], LOW);
    }

    delay(150);
  }
}

void toqueGameOver() {

  int notas[] = {659, 554, 440, 349};
  int dur[] = {250, 300, 350, 650};

  tocarMelodia(notas, dur, 4, true);
}

void toqueNovoRecorde() {

  int notas[] = {523, 659, 784, 1047};
  int dur[] = {200, 200, 200, 500};

  tocarMelodia(notas, dur, 4, true);
}

void toqueVitoria() {

  int notas[] = {523, 659, 784, 1047, 1318, 1568};
  int dur[] = {180, 180, 180, 250, 250, 700};

  tocarMelodia(notas, dur, 6, true);
}

void aguardarSoltar(int botao) {

  while (digitalRead(botao) == HIGH);

  delay(200);
}

void cadastrarRecordista() {

  char nome[4] = {'A', 'A', 'A', '\0'};
  int posicao = 0;

  while (posicao < 3) {

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(10, 5);
    display.print("NOVO RECORDISTA");

    display.setCursor(10, 22);
    display.print("Escolha as letras:");

    display.setTextSize(2);
    display.setCursor(40, 38);
    display.print(nome);

    display.setTextSize(1);
    display.setCursor(40 + (posicao * 12), 55);
    display.print("^");

    display.display();

    // Avancar letra - Verde
    if (digitalRead(pushG) == HIGH) {

      nome[posicao]++;

      if (nome[posicao] > 'Z') {
        nome[posicao] = 'A';
      }

      aguardarSoltar(pushG);
    }

    // Retroceder letra - Vermelho
    else if (digitalRead(pushR) == HIGH) {

      nome[posicao]--;

      if (nome[posicao] < 'A') {
        nome[posicao] = 'Z';
      }

      aguardarSoltar(pushR);
    }

    // Confirmar letra - Amarelo
    else if (digitalRead(pushY) == HIGH) {

      aguardarSoltar(pushY);

      posicao++;
    }
  }

  nome[3] = '\0';

  strcpy(nomeRecordista, nome);

  // Salva o nome na EEPROM
  for (int i = 0; i < 3; i++) {
    EEPROM.update(EEPROM_NAME + i, nomeRecordista[i]);
  }

  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(20, 15);
  display.print("NOME");

  display.setCursor(20, 38);
  display.print("SALVO!");

  display.display();

  delay(2000);
}

bool atualizarRecordista(int pontuacao) {

  if (pontuacao > recorde) {

    recorde = pontuacao;

    EEPROM.update(EEPROM_RECORD, recorde);

    return true;
  }

  return false;
}

void mostrarRecordista() {

  display.clearDisplay();

  display.setTextSize(1);
  display.setCursor(30, 5);
  display.print("RECORDISTA");

  display.setTextSize(2);
  display.setCursor(40, 20);
  display.print(nomeRecordista);

  display.setTextSize(1);
  display.setCursor(25, 45);
  display.print("Recorde: ");
  display.print(recorde);

  display.display();
}

void mostrarSequencia() {

  for (int i = 0; i < rodada; i++) {

    digitalWrite(leds[sequencia[i]], HIGH);

    tone(buz, tons[sequencia[i]]);

    delay(600);

    digitalWrite(leds[sequencia[i]], LOW);

    noTone(buz);

    delay(250);
  }
}


bool jogadorAcertou() {

  for (int i = 0; i < rodada; i++) {

    int resposta = -1;

    while (resposta == -1) {

      if (digitalRead(pushG) == HIGH) resposta = 0;
      if (digitalRead(pushR) == HIGH) resposta = 1;
      if (digitalRead(pushY) == HIGH) resposta = 2;
      if (digitalRead(pushB) == HIGH) resposta = 3;
    }

    digitalWrite(leds[resposta], HIGH);

    tone(buz, tons[resposta]);

    delay(300);

    digitalWrite(leds[resposta], LOW);

    noTone(buz);

    // Aguarda soltar todos os botoes
    while (
      digitalRead(pushG) == HIGH ||
      digitalRead(pushR) == HIGH ||
      digitalRead(pushY) == HIGH ||
      digitalRead(pushB) == HIGH
    );

    if (resposta != sequencia[i]) {
      return false;
    }
  }

  return true;
}

void setup() {

  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledB, OUTPUT);

  pinMode(pushG, INPUT);
  pinMode(pushR, INPUT);
  pinMode(pushY, INPUT);
  pinMode(pushB, INPUT);

  pinMode(buz, OUTPUT);

  // Inicializa OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }

  display.setTextColor(SSD1306_WHITE);

  // Recupera recorde
  recorde = EEPROM.read(EEPROM_RECORD);

  if (recorde > 90) {
    recorde = 0;
    EEPROM.update(EEPROM_RECORD, recorde);
  }

  // Recupera nome do recordista
  for (int i = 0; i < 3; i++) {
    nomeRecordista[i] = EEPROM.read(EEPROM_NAME + i);
  }

  nomeRecordista[3] = '\0';

  // Verifica se o nome recuperado e valido
  for (int i = 0; i < 3; i++) {

    if (nomeRecordista[i] < 'A' ||
        nomeRecordista[i] > 'Z') {

      strcpy(nomeRecordista, "AAA");

      for (int j = 0; j < 3; j++) {
        EEPROM.update(EEPROM_NAME + j, nomeRecordista[j]);
      }

      break;
    }
  }

  randomSeed(millis());

  // Tela inicial
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(25, 0);
  display.print("GENIUS");

  display.setTextSize(1);
  display.setCursor(0, 25);
  display.print("Recordista: ");
  display.print(nomeRecordista);

  display.setCursor(0, 38);
  display.print("Recorde: ");
  display.print(recorde);

  display.setCursor(0, 53);
  display.print("Pressione Verde");

  display.display();

  // Aguarda pressionar verde
  while (digitalRead(pushG) == LOW);

  // Aguarda soltar verde
  while (digitalRead(pushG) == HIGH);

  delay(300);
}

void loop() {

  rodada = 0;
  gameOver = false;

  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(0, 20);
  display.print("Iniciando");

  display.display();

  delay(1000);

  while (!gameOver) {

    sequencia[rodada] = random(4);
    rodada++;

    // Mostra pontuacao e nivel
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(0, 0);

    display.print("P:");
    display.print(rodada - 1);

    display.print(" R:");
    display.print(recorde);

    display.setCursor(0, 25);
    display.print("Nivel ");
    display.print(rodada);

    display.display();

    delay(1000);

    // Reproduz sequencia
    mostrarSequencia();

    // Mostra vez do jogador
    display.clearDisplay();

    display.setTextSize(2);
    display.setCursor(0, 0);

    display.print("P:");
    display.print(rodada - 1);

    display.print(" R:");
    display.print(recorde);

    display.setCursor(0, 25);
    display.print("Sua vez!");

    display.display();

    // Verifica se o jogador errou
    if (!jogadorAcertou()) {

      int pontuacao = rodada - 1;
      bool novoRecorde = atualizarRecordista(pontuacao);

      gameOver = true;

      display.clearDisplay();

      display.setTextSize(2);
      display.setCursor(5, 10);
      display.print("GAME OVER");

      display.setTextSize(1);
      display.setCursor(25, 45);
      display.print("P:");
      display.print(pontuacao);

      display.print(" R:");
      display.print(recorde);

      display.display();

      toqueGameOver();

      delay(2000);

      // Verifica o recorde
      if (novoRecorde) {

        display.clearDisplay();

        display.setTextSize(2);
        display.setCursor(5, 5);
        display.print("Parabens!");

        display.setTextSize(1);
        display.setCursor(5, 30);
        display.print("NOVO RECORDE!");

        display.setCursor(5, 45);
        display.print("Pontuacao: ");
        display.print(pontuacao);

        display.display();

        delay(2000);

        // Cadastra o nome do recordista
        cadastrarRecordista();

        // Toca o som de novo recorde
        toqueNovoRecorde();
      }

      // Mostra o resultado final
      delay(2000);

      mostrarRecordista();

      delay(2000);

      // Aguarda nova partida
      display.clearDisplay();

      display.setTextSize(1);
      display.setCursor(15, 25);
      display.print("Pressione Verde");

      display.display();

      while (digitalRead(pushG) == LOW);
      while (digitalRead(pushG) == HIGH);

      delay(300);
    }

    // Vitória na fase 90
    if (rodada == 90 && !gameOver) {

      // Verifica se a fase 90 tambem estabeleceu um novo recorde
      bool novoRecorde = atualizarRecordista(90);

      display.clearDisplay();

      display.setTextSize(2);
      display.setCursor(5, 10);
      display.print("PARABENS!");

      display.setTextSize(1);
      display.setCursor(40, 45);
      display.print("Fase 90");

      display.display();

      delay(1000);

      // Se for novo recorde, cadastra o nome
      if (novoRecorde) {

        display.clearDisplay();

        display.setTextSize(1);
        display.setCursor(5, 15);
        display.print("NOVO RECORDISTA!");

        display.setCursor(5, 35);
        display.print("Fase 90 concluida!");

        display.display();

        delay(2000);

        cadastrarRecordista();

        toqueNovoRecorde();
      }

      // Toca a melodia especial de vitoria
      toqueVitoria();

      mostrarRecordista();

      while (true);
    }

    delay(800);
  }
}
