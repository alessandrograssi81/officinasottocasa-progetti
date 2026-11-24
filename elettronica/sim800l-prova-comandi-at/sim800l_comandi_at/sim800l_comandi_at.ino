/*
  Prova del modulo GSM SIM800L con i comandi AT, dal monitor seriale
  Arduino UNO/Nano + SIM800L

  Quello che si scrive nel monitor seriale dell'IDE Arduino arriva al SIM800L,
  e le risposte del modulo tornano nel monitor seriale. Serve per controllare
  che il modulo sia alimentato bene, che risponda e che si registri sulla rete.

  Guida completa (alimentazione, collegamenti, LED, comandi AT, problemi):
  https://www.officinasottocasa.it/gsm-sim800l/

  officinasottocasa.it
  Copyright (c) 2024–2026 Alessandro Grassi - licenza MIT (vedi LICENSE)
*/

//Includiamo la libreria per la comunicazione seriale tra l'Arduino e il SIM800L
#include "SoftwareSerial.h"

//Definiamo il pin dell'Arduino a cui è collegato il pin TX del Sim800L, in questo caso D5
#define SIM_TX_PIN 5
//Definiamo il pin dell'Arduino a cui è collegato il pin RX del Sim800L, in questo caso D6 (occhio al partitore!)
#define SIM_RX_PIN 6
//Definiamo il pin dell'Arduino a cui è collegato il pin DTR del Sim800L, in questo caso D4 (serve per lo sleep)
#define DTR_PIN 4
//Definiamo una seriale software sui TX e RX del SIM800L
SoftwareSerial serialSIM800(SIM_TX_PIN, SIM_RX_PIN);

void setup() {
  //Inizializziamo la seriale tra Arduino e il PC
  Serial.begin(57600);
  //Inizializziamo la seriale virtuale lato SIM800L
  serialSIM800.begin(57600);
  //DTR a HIGH: serve per mandare il modulo in sleep e risvegliarlo
  pinMode(DTR_PIN, OUTPUT);
  digitalWrite(DTR_PIN, HIGH);
  delay(500);
}

void loop() {
  //Scrivi sulla seriale Arduino-PC quello che leggi dal pin TX del SIM800L
  if (serialSIM800.available()) {
    Serial.write(serialSIM800.read());
  }

  //Scrivi al SIM800L quello che digitiamo sul monitor seriale (i comandi AT)
  if (Serial.available()) {
    serialSIM800.write(Serial.read());
  }
}

// Per mandare il modulo in sleep (con DTR a HIGH)
void sim800sleepmode(){
  serialSIM800.println("AT+CSCLK=2");
}

// Per risvegliarlo: un impulso basso su DTR, poi sleep disattivato
void sim800wakeup(){
  digitalWrite(DTR_PIN, LOW);
  delay(200);
  digitalWrite(DTR_PIN, HIGH);
  serialSIM800.println("AT");
  serialSIM800.println("AT+CSCLK=0");
}
