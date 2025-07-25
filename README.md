# Vorlage für den W5100S-EVB-Pico

## Content

* Ethernet connection
* MQTT connection
* Flashen OTA (OTE)
* Ansteuerung von "WS2812" - LED's per AdafruitNeoPixel

## Flashen über PlatformIO

Ich empfehle das Terminal zu benutzen, da sonst immer beide Environments, also Standart und OTA, gebaut und geflasht werden.

**Normales Flashen über MicroUSB Kabel:**

```platformio run -t upload -e wiznet_5100s_evb_pico```
```platformio run -t upload -e pico2```

**Flashen über OTA mittels Ethernet:**

Hierfür die richtige IP Adresse in der platformio.ini Datei eintragen! Eine DHCP IP kann über ArduinoIDE oder über Lognachrichten in der Konsole herausgefunden werden.

```platformio run -t upload -e wiznet_5100s_evb_pico_ota```

**Wenn du folgende Fehlernachricht bekommst:**

```No new RPxxxx device found yet, waiting...```

Musst du den Serial Monitor ausschalten und neu flashen. Flashen kann auch fehlschlagen, wenn der Controller extern mit Spannung versorgt wird, aber OTA sollte immer funktionieren.

## MQTT

Adresse des Brokers in config.h angeben, wenn Passwort benötigt wird, muss die init Funktion etwas umgeschrieben werde, siehe PubSubClient Beispiele.

## Ethernet

Jeder Kontroller berechnet sich aus seiner internen ID eine einzigartige mac-Adresse um zu verhindern, dass mehrere Kontroller mit der selben Adresse mit dem Netzwerk verbunden sind.
