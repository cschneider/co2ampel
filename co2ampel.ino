#include <Wire.h>
#include <Adafruit_NeoPixel.h>              // http://librarymanager/All#Adafruit_NeoPixel
#include <SparkFun_SCD30_Arduino_Library.h> // http://librarymanager/All#SparkFun_SCD30
#include <LiquidCrystal_I2C.h>              // http://librarymanager/All#Liquid  Built in By Adafruit

#define LED_PIN    D7
#define LED_COUNT  10

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

LiquidCrystal_I2C lcd(0x27, 16, 2); 

SCD30 airSensor;

void setup() {
  Serial.begin(115200);
  Serial.println("Fablab Bruchsal CO2 Ampel");
}

void loop() {
}
