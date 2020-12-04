#include <Wire.h>
#include <Adafruit_NeoPixel.h>              // http://librarymanager/All#Adafruit_NeoPixel
#include <SparkFun_SCD30_Arduino_Library.h> // http://librarymanager/All#SparkFun_SCD30
#include <LiquidCrystal_I2C.h>              // http://librarymanager/All#LiquidCrystal_I2C

#define LED_PIN    D7
#define LED_COUNT  64

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
uint32_t red = strip.Color(255, 0, 0);
uint32_t yellow = strip.Color(255, 150, 0);
uint32_t green = strip.Color( 0, 255, 0);

LiquidCrystal_I2C lcd(0x27, 16, 2); 

SCD30 airSensor;

void setup() {
  Serial.begin(115200);
  Serial.println("Fablab Bruchsal CO2 Ampel");
  Wire.begin();
  lcd.init();
  lcd.backlight();
  Serial.println("Fablab Bruchsal CO2 Ampel");

  if (airSensor.begin() == false) {
    Serial.println("SCD30 Sensor nicht gefunden...");
    while (1);
  }
  
  strip.begin();
  strip.show();
  strip.setBrightness(50);
}

void loop() {
  if (airSensor.dataAvailable())
  {
    uint16_t co2 = airSensor.getCO2();
    float temp = airSensor.getTemperature();
    float hum = airSensor.getHumidity();
    printSerial(co2, temp, hum);
    printLCD(co2, temp, hum);
    printLEDStrip(co2);
  }
  delay(500);

}

void printSerial(uint16_t co2, float temp, float hum) {
  Serial.print("co2(ppm):");
  Serial.print(co2);
  Serial.print(" temp(C):");
  Serial.print(temp, 1);
  Serial.print(" humidity(%):");
  Serial.print(hum, 1);
  Serial.println();
}

void printLCD(uint16_t co2, float temp, float hum) {
  lcd.init();
  lcd.setCursor(0, 0);
  lcd.print("co2 ");
  lcd.print(co2);
  lcd.print("ppm");
  lcd.setCursor(0, 1);
  lcd.print("t ");
  lcd.print(temp,1);
  lcd.print("C");
  lcd.print(" h ");
  lcd.print(hum,1);
  lcd.print("%");
}

void printLEDStrip(uint16_t co2) {
    uint32_t color;
    if (co2>1000) {
      color = red;
    } else if (co2>800) {
      color = yellow;
    } else {
      color = green;
    }
    uint16_t mappedCO2 = map(co2, 300, 2000, 0, 64);
    strip.clear();
    strip.fill(color, 0, mappedCO2);
    strip.show();
}
