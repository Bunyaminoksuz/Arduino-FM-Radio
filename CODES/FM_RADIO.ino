// SAĞLAM LCD EKRANLI KOD BU
#include <Wire.h>
#include <TEA5767.h>
#include <Encoder.h>
#include <LiquidCrystal_I2C.h>

// TEA5767 radyo modülü
TEA5767 radio;

// Rotary encoder pinleri
Encoder enc(2, 3);  // Encoder için pin 2 ve pin 3

// LCD ekran (I2C adres 0x27 olabilir)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Başlangıç frekansı
float frequency = 87.50;
long oldPos = -999;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("FM Radyo");
  
  radio.setFrequency(frequency);
  delay(100);
}

void loop() {
  long newPos = enc.read();
  
  if (newPos != oldPos) {
    if (newPos > oldPos) {
      frequency += 0.1;
    } else {
      frequency -= 0.1;
    }

    if (frequency < 87.50) frequency = 87.50;
    if (frequency > 108.00) frequency = 108.00;

    radio.setFrequency(frequency);
    delay(50);  // küçük gecikme

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Frekans:");
    lcd.print(frequency, 2);
    lcd.print("MHz");

    short signalLevel = radio.getSignalLevel();
    lcd.setCursor(0, 1);
    lcd.print("Sinyal: ");
    lcd.print(signalLevel);

    Serial.print("Yeni Frekans: ");
    Serial.print(frequency, 2);
    Serial.println(" MHz");

    Serial.print("Sinyal Seviyesi: ");
    Serial.println(signalLevel);

    oldPos = newPos;
  }

  delay(100);  // LCD güncellemeleri yavaşlatmak paraziti azaltır
}
