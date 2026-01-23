#include <Arduino.h>

const int BLACK_THRESHOLD = 1500;
const int WHITE_THRESHOLD = 3000;
const int SENSOR_PIN = 32;
const int SEC = 1000;

void setup() {
    Serial.begin(115200);
    delay(SEC);
    Serial.println("Hello, World!");
    pinMode(SENSOR_PIN, INPUT);
}

void loop() {
    int val = analogRead(SENSOR_PIN);
    Serial.println(val);

    if (val < BLACK_THRESHOLD) {
        Serial.println("BLACK");
    } else if (val > WHITE_THRESHOLD) {
        Serial.println("WHITE");
    }

    delay(2 * SEC);
}
