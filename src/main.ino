#include <Wire.h>
#include <U8g2lib.h>
#include "timer.h"

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

#define POT_PIN 4  
#define BUTTON_PIN 15  

void setup() {
    Wire.setClock(800000);
    u8g2.begin();
    pinMode(POT_PIN, INPUT);
    pinMode(BUTTON_PIN, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), handleButtonPress, FALLING);
}

void loop() {
    if (!timerRunning) {
        int potValue = analogRead(POT_PIN);
        timerMinutes = map(potValue, 0, 4095, 1, 60);

        u8g2.clearBuffer();
        u8g2.setFont(u8g2_font_ncenB12_tr);
        u8g2.setCursor(30, 20);
        u8g2.print("Set: ");
        u8g2.print(timerMinutes);
        u8g2.print(" min");

        u8g2.sendBuffer();

        startTimer();
    } else {
        checkTimer();
        abortTimer();
    }
}
