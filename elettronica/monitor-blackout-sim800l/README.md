# Monitor dei blackout con Arduino e SIM800L

Un dispositivo a batteria che manda un **SMS quando manca la corrente** e un altro **quando torna**, con la durata del blackout. Nel nostro collaudo, dalla spina staccata all'SMS sul telefono passano circa 15 secondi.

Articolo completo, con schema elettrico, distinta dei materiali, spiegazione del codice funzione per funzione e collaudo:
**https://www.officinasottocasa.it/come-monitorare-blackout-della-rete-elettrica-con-arduino-e-un-sim800l/**

## Lo sketch

[`monitor_blackout/monitor_blackout.ino`](monitor_blackout/monitor_blackout.ino) (versione 2). La cartella ha lo stesso nome del file, come vuole l'IDE di Arduino.

- **Scheda**: Arduino Nano (ATmega328P).
- **Librerie** (dal Library Manager dell'IDE Arduino): `RTClib` di Adafruit e `U8g2` di olikraus.
- **Componenti**: modulo GSM SIM800L, fotoaccoppiatore PC817 per "sentire" la rete, RTC DS3231, display OLED SSD1306 128×64 (facoltativo), level shifter 3,3 V / 5 V, batteria LiPo con BMS.

## Prima di caricarlo

1. Scrivere i propri numeri al posto di `+39XXXXXXXXXX` in `NUMERO_ALLARME_1` e `NUMERO_ALLARME_2`.
2. Controllare i pin nella sezione `CONFIGURAZIONE` e le resistenze del partitore della batteria (`R_ALTO`, `R_BASSO`).
3. Se la tensione della batteria letta dallo sketch non coincide con quella del tester, regolare `VREF_INTERNO` (il commento nello sketch spiega come).
4. Alimentare il SIM800L direttamente dalla batteria o da uno step-down, **mai dal pin 5V di Arduino**: assorbe picchi fino a 2 A.

Mandando un SMS con la parola `STATO` al numero della SIM, il dispositivo risponde con lo stato della rete e la tensione della batteria.

## Licenza

Codice con licenza [MIT](../../LICENSE): Copyright (c) 2024–2026 Alessandro Grassi.
