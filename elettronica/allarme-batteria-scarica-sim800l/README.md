# Allarme batteria scarica via SMS con Arduino e SIM800L

Un piccolo dispositivo che misura in continuo la tensione di una batteria da 12 V e, quando scende **sotto i 12 V**, sveglia il modulo GSM SIM800L e manda un **SMS di allarme**. È nato dopo aver trovato la batteria della moto, ferma in garage, scesa a 6,8 V.

Articolo completo, con schema, circuito stampato e spiegazione del codice:
**https://www.officinasottocasa.it/allarme-gsm-batteria-scarica-mancanza-corrente/**

## Lo sketch

[`monitor_batteria_moto/monitor_batteria_moto.ino`](monitor_batteria_moto/monitor_batteria_moto.ino)

- **Scheda**: Arduino Nano.
- **Libreria** (dal Library Manager dell'IDE Arduino): `U8g2` di olikraus, per il display OLED SSD1306.
- **Pin**: partitore della batteria su A0 (R1 = 100 kΩ, R2 = 10 kΩ), DTR del SIM800L su D5, TX del SIM800L su D6, RX del SIM800L su D7.

## Da sapere prima di usarlo

Lo sketch è **ricostruito dal PDF pubblicato con l'articolo** (il file originale non c'è più) ed è identico al codice che l'articolo mostra e spiega. Non l'abbiamo ricaricato su una scheda in questa forma. Rileggendolo abbiamo notato quattro cose:

1. **Manca `pinMode(DTR_PIN, OUTPUT)`** nel `setup()`: senza, `digitalWrite(DTR_PIN, HIGH)` accende solo la resistenza di pull-up interna invece di portare il pin a 5 V, e lo sleep e il risveglio del SIM800L possono non funzionare. Lo sketch di prova della [guida al SIM800L](../sim800l-prova-comandi-at/) lo imposta.
2. **`sendsmsalarm()` manda i comandi senza pause**: il SIM800L di solito ha bisogno di qualche centinaio di millisecondi tra `AT+CMGS` e il testo del messaggio (nel [monitor dei blackout](../monitor-blackout-sim800l/) c'è un `delay(500)`).
3. **Numero e testo dell'SMS sono segnaposto**: in `sendsmsalarm()` vanno scritti il proprio numero al posto di `+39xxxxxxxxxx` e il testo al posto di `testo del messaggio`.
4. **Il display mostra solo "Initializing..." all'avvio**, poi resta vuoto: nessuna funzione ci scrive la tensione.

Se lo provate e lo correggete, raccontatecelo dalla pagina dei [contatti](https://www.officinasottocasa.it/contatti/) o con una *issue*: le correzioni provate finiscono nell'articolo.

## Licenza

Codice con licenza [MIT](../../LICENSE): Copyright (c) 2024–2026 Alessandro Grassi.
