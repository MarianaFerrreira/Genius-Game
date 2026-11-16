// Mudança feita: adição de registro de valor de recorde

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <EEPROM.h>

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// LEDs
#define ledG 2
#define ledY 3
#define ledB 4
#define ledR 5

// Botões
#define pushR 6
#define pushB 7
#define pushY 8
#define pushG 9

// Buzzer
#define buz 10

// Até a fase 90
byte sequencia[90];

int rodada = 0;
int recorde = 0;
bool gameOver = false;

int leds[4] = {ledG, ledR, ledY, ledB};
int tons[4] = {392, 440, 554, 659};

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

  // Recupera o recorde salvo
  recorde = EEPROM.read(0);

  if (recorde > 90) {
    recorde = 0;
    EEPROM.update(0, recorde);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(25, 10);
  display.print("GENIUS");

  display.setTextSize(1);
  display.setCursor(15, 45);
  display.print("Pressione Verde");
  display.display();

  // Aguarda pressionar o verde
  while (digitalRead(pushG) == LOW);

  // Aguarda soltar o botão
  while (digitalRead(pushG) == HIGH);

  randomSeed(millis());

  delay(300);
}

void loop() {

  // REMOVIDO: segunda espera pelo botão verde

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

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("P:");
    display.print(rodada - 1);

    display.print(" R:");
    display.print(recorde);

    display.setTextSize(2);
    display.setCursor(0, 25);
    display.print("Nivel ");
    display.print(rodada);

    display.display();

    delay(1000);

    mostrarSequencia();

    display.clearDisplay();

    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print("P:");
    display.print(rodada - 1);

    display.print(" R:");
    display.print(recorde);

    display.setTextSize(2);
    display.setCursor(0, 25);
    display.print("Sua vez!");

    display.display();

    if (!jogadorAcertou()) {

      if ((rodada - 1) > recorde) {
        recorde = rodada - 1;
        EEPROM.update(0, recorde);
      }

      gameOver = true;

      display.clearDisplay();

      display.setTextSize(2);
      display.setCursor(5, 10);
      display.print("GAME OVER");

      display.setTextSize(1);
      display.setCursor(25, 45);
      display.print("P:");
      display.print(rodada - 1);

      display.print(" R:");
      display.print(recorde);

      display.display();

      for (int i = 0; i < 3; i++) {

        tone(buz, 150);

        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
        digitalWrite(ledB, HIGH);

        delay(300);

        noTone(buz);

        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
        digitalWrite(ledB, LOW);

        delay(300);
      }

      delay(4000);

      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(15, 25);
      display.print("Pressione Verde");
      display.display();

      // Aguarda pressionar o verde
      while (digitalRead(pushG) == LOW);

      // Aguarda soltar o verde
      while (digitalRead(pushG) == HIGH);

      delay(300);
    }

    if (rodada == 90 && !gameOver) {

      if (rodada > recorde) {
        recorde = rodada;
        EEPROM.update(0, recorde);
      }

      display.clearDisplay();
      display.setTextSize(2);
      display.setCursor(5, 10);
      display.print("PARABENS!");

      display.setTextSize(1);
      display.setCursor(40, 45);
      display.print("Fase 90");
      display.display();

      int notas[] = {523, 659, 784, 1047};
      int dur[] = {200, 200, 200, 500};

      for (int i = 0; i < 4; i++) {

        tone(buz, notas[i]);

        digitalWrite(ledG, HIGH);
        digitalWrite(ledR, HIGH);
        digitalWrite(ledY, HIGH);
        digitalWrite(ledB, HIGH);

        delay(dur[i]);

        noTone(buz);

        digitalWrite(ledG, LOW);
        digitalWrite(ledR, LOW);
        digitalWrite(ledY, LOW);
        digitalWrite(ledB, LOW);

        delay(150);
      }

      while (true);
    }

    delay(800);
  }
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
