#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED_PIN 8

MFRC522 mfrc522(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Alamat I2C LCD, ganti 0x27 jika perlu

// Gantilah UID_TAG dan UID_KTP dengan UID sebenarnya dari tag RFID dan KTP Anda
byte UID_TAG[4] = {0xA9, 0x76, 0xFA, 0xA2};   // Gantilah dengan UID Tag RFID Anda (4 byte)
byte UID_KTP[7] = {0x05, 0x80, 0x24, 0x95, 0xA8, 0xD1, 0x0}; // Gantilah dengan UID KTP Anda (7 byte)

// Deklarasi prototype fungsi
bool isSameUID(byte *knownUID, byte knownSize, byte *scannedUID, byte scannedSize);
void blinkLED(int duration);
void solidLED(int duration);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  lcd.begin(16, 2);
  lcd.backlight();
  pinMode(LED_PIN, OUTPUT);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Tempelkan kartu");
  Serial.println("Tempelkan kartu untuk scanning...");
}

void loop() {
  if (!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Membaca UID kartu yang dipindai
  if (isSameUID(UID_TAG, 4, mfrc522.uid.uidByte, mfrc522.uid.size)) {
    Serial.println("Status: Deny");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status: Deny");
    blinkLED(3000);  // Blink LED selama 3 detik
  }
  else if (isSameUID(UID_KTP, 7, mfrc522.uid.uidByte, mfrc522.uid.size)) {
    Serial.println("Status: Allow");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Status: Allow");
    solidLED(3000);  // Nyalakan LED solid selama 3 detik
  } else {
    Serial.println("Kartu tidak dikenal");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kartu Tidak Dikenal");
    delay(3000);
  }

  mfrc522.PICC_HaltA();
}

// Fungsi untuk membandingkan dua UID dengan mempertimbangkan panjangnya
bool isSameUID(byte *knownUID, byte knownSize, byte *scannedUID, byte scannedSize) {
  if (knownSize != scannedSize) {
    return false;
  }
  for (byte i = 0; i < knownSize; i++) {
    if (knownUID[i] != scannedUID[i]) {
      return false;
    }
  }
  return true;
}

// Fungsi untuk LED berkedip
void blinkLED(int duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(250);
  }
}

// Fungsi untuk LED menyala terus
void solidLED(int duration) {
  digitalWrite(LED_PIN, HIGH);
  delay(duration);
  digitalWrite(LED_PIN, LOW);
}
