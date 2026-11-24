# Prova del SIM800L con i comandi AT

Lo sketch più semplice per controllare un modulo GSM **SIM800L** con **Arduino**: quello che si scrive nel monitor seriale arriva al modulo, e le risposte tornano indietro. Con i comandi `AT`, `AT+CSQ`, `AT+CCID`, `AT+CREG?` e `AT+COPS?` si verifica in pochi minuti se il modulo è alimentato bene, se legge la SIM e se si registra sulla rete.

Guida completa in italiano (alimentazione, pin, collegamenti con Arduino UNO ed ESP32, LED, comandi AT, invio di un SMS, sleep, problemi e soluzioni, 2G in Italia):
**https://www.officinasottocasa.it/gsm-sim800l/**

## Lo sketch

[`sim800l_comandi_at/sim800l_comandi_at.ino`](sim800l_comandi_at/sim800l_comandi_at.ino)

- TX del SIM800L su D5, RX del SIM800L su D6 **con il partitore** (il modulo lavora a 3,3 V), DTR su D4.
- Monitor seriale a **57600 baud**.
- In fondo, le due funzioni per mandare il modulo in sleep e risvegliarlo con il pin DTR.

## Licenza

Codice con licenza [MIT](../../LICENSE): Copyright (c) 2024–2026 Alessandro Grassi.
