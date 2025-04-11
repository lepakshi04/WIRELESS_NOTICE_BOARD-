#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

// LCD setup (RS=13, EN=12, D4=11, D5=10, D6=9, D7=8)
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define BUZZER_PIN 3

void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("Voice Control"); lcd.setCursor(0, 1);lcd.print("Notice Board"); 
    delay(2000);
    lcd.clear();
    pinMode(BUZZER_PIN, OUTPUT);digitalWrite(BUZZER_PIN, HIGH);delay(500);digitalWrite(BUZZER_PIN, LOW);
}

void loop() {
    if (Serial.available()) {
        String command = Serial.readStringUntil('\n');
        command.trim();
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Command:");
        lcd.setCursor(0, 1);
        lcd.print(command);
        Serial.println("Received: " + command);
        digitalWrite(BUZZER_PIN, HIGH);
        delay(2000);
        digitalWrite(BUZZER_PIN, LOW);
    }
}
