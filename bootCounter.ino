/* Memory Library https://docs.arduino.cc/learn/built-in-libraries/eeprom */
#include <EEPROM.h> 

/* Adafruit LED Backpack Library https://github.com/adafruit/Adafruit_LED_Backpack */
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

int numberAddress = 0; // Address that will store the number
int resetButton = 0; // 0 == LOW
int number = 0;

/* Pins initialization */
int buzzerPin = 3;
int resetButtonPin = 4;

/* https://www.youtube.com/watch?v=NA5MwhuHWLo :) */
void ringtone()
{
    tone(buzzerPin, 1047);
    delay(250);
    noTone(buzzerPin);
    delay(250);

    tone(buzzerPin, 1568);
    delay(250);
    noTone(buzzerPin);
    delay(300);

    tone(buzzerPin, 1760);
    delay(250);
    noTone(buzzerPin);
    delay(100);

    tone(buzzerPin, 1397);
    delay(250);
    noTone(buzzerPin);
}

void setup()
{
#ifndef __AVR_ATtiny85__
    Serial.begin(9600);
#endif

    matrix.begin(0x70);

    while (!Serial)
    {
        ;
    }

    pinMode(buzzerPin, OUTPUT);
    pinMode(resetButtonPin, INPUT_PULLUP);
    
    /* GET number from memory */
    EEPROM.get(numberAddress, number);

    /* PUT number + 1 from memory */
    EEPROM.put(numberAddress, ++number);

    /* Displays line 51's number */
    matrix.print(number);
    matrix.writeDisplay();

    ringtone();
}

void loop()
{
    resetButton = digitalRead(resetButtonPin);

    if (resetButton == 0)
    {
        EEPROM.put(numberAddress, resetButton);
        matrix.print("0000");
        matrix.writeDisplay();
    }
}