#include <Arduino.h>
#include <FastLED.h>

#define LED_PIN 2 // データ入力ピン
#define NUM_LEDS 256 // マトリクス数
#define BRIGHTNESS 20 // 明るさ
#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

// LEDの色データを保持する配列
CRGB leds[NUM_LEDS];

// (x, y)座標を、一次元配列のインデックスに変換する
uint16_t XY(uint8_t x, uint8_t y) {
    uint16_t index;

    if (y & 0x01) {
        // 奇数行は右から左へ
        uint8_t reverseX = 15 - x;
        index = (y * 16) + reverseX;
    } else {
        index = (y * 16) + x;
    }
    return index;
}

void setup() {
    Serial.begin(115200);
    delay(2000);

    // FastLEDの初期化
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);

    Serial.println("LED Test Started");
}

void loop() {
    FastLED.clear();

    leds[XY(5, 5)] = CRGB::Red;

    leds[XY(10, 15)] = CRGB::Blue;

    FastLED.show();
    delay(1000);
}
