# officinasottocasa – progetti

Sketch Arduino e disegni FreeCAD dei progetti di **[officinasottocasa.it](https://www.officinasottocasa.it)**, il laboratorio "maker lab" dove costruiamo nel tempo libero mobili in legno, oggetti in ferro e piccoli dispositivi elettronici. Ogni cartella ha il suo articolo sul sito, con foto, schemi, spiegazioni ed errori da evitare.

*In English:* Arduino sketches (SIM800L GSM module, power outage SMS alarm) and FreeCAD drawings (Montessori furniture in beech wood) from officinasottocasa.it. Code and comments are in Italian; the articles explain everything step by step.

## Elettronica

| Progetto | Cosa c'è | Articolo |
|---|---|---|
| [Monitor dei blackout con SIM800L](elettronica/monitor-blackout-sim800l/) | Sketch completo (v2): Arduino Nano, SIM800L, PC817, RTC DS3231, display OLED. Manda un SMS quando manca la corrente e quando torna, con la durata | [Allarme blackout fai da te: SMS con Arduino e SIM800L](https://www.officinasottocasa.it/come-monitorare-blackout-della-rete-elettrica-con-arduino-e-un-sim800l/) |
| [Allarme batteria scarica con SIM800L](elettronica/allarme-batteria-scarica-sim800l/) | Sketch: Arduino Nano, SIM800L, display OLED. Manda un SMS quando la batteria da 12 V scende sotto la soglia | [Allarme batteria scarica via SMS con Arduino e SIM800L](https://www.officinasottocasa.it/allarme-gsm-batteria-scarica-mancanza-corrente/) |
| [Prova del SIM800L con i comandi AT](elettronica/sim800l-prova-comandi-at/) | Sketch per parlare con il modulo dal monitor seriale | [SIM800L: guida al modulo GSM con Arduino ed ESP32](https://www.officinasottocasa.it/gsm-sim800l/) |

## Legno

| Progetto | Cosa c'è | Articolo |
|---|---|---|
| [Palestrina montessoriana](legno/palestrina-montessoriana/) | Disegno FreeCAD, misure | [Palestrina montessori in legno di faggio fatta a mano](https://www.officinasottocasa.it/palestrina-montessoriana-in-legno-di-faggio/) |
| [Lettino montessoriano a casetta](legno/lettino-montessoriano-casetta/) | Disegno FreeCAD con la tavola quotata, PDF | [Lettino montessoriano fai da te a casetta](https://www.officinasottocasa.it/lettino-montessoriano-fai-da-te-casetta-faggio/) |

## Licenze

- **Codice** (sketch nella cartella `elettronica/`): [MIT](LICENSE). Si può usare, modificare e condividere liberamente, anche per progetti commerciali, mantenendo la riga «Copyright (c) 2024–2026 Alessandro Grassi».
- **Disegni, PDF e testi** (cartella `legno/` e file README): [CC BY-NC-SA 4.0](legno/LICENSE.md). Si possono modificare e condividere citando la fonte, non per scopi commerciali, con la stessa licenza.
- Il nome "officinasottocasa" e il logo non sono coperti da queste licenze.

## Domande, errori, foto delle vostre versioni

Scriveteci dalla pagina dei [contatti](https://www.officinasottocasa.it/contatti/) del sito, oppure aprite una *issue* qui. Le domande che arrivano diventano risposte nelle domande frequenti degli articoli.
