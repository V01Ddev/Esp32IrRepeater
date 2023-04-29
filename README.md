# Esp32IrRepeater

## listens and repeats Ir code using an esp32 and some arduino code

---

## pin dictionary:
```
d19 --> receving from button 1 (to start listening (via hold))
d18 --> receving from diod\n
d21 --> receving from button 2 (to trigger IR blast)
d26 --> outputting to IR LED (triggering IR blast)
```

- the Ir library used in this project --> [Arduino-IRremote](https://github.com/Arduino-IRremote/Arduino-IRremote)

## schematic:
[schematics for this project](schematic/)

![ESP32_IR_sch](https://user-images.githubusercontent.com/57007730/188317314-0702bd84-12a0-4374-9dfc-1e52af56db75.png)
