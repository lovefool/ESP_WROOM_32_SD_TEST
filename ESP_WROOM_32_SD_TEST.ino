/*
【ESP32】SDカードモジュールでロガーを作る【SPI通信】
https://www.youtube.com/watch?v=SS6xEQ-b7LY

2024.06.22 (COmplete)
*/

#include <SD.h>
#include <SPI.h>

//SDモジュール(ESP-WROOM-32D): CS(5),SCK(18),MOSI(23),MISO(19),VCC(5V),GND(GND)

const int chipSelect = 5;  // CSピンの番号　GPIO5

void setup() {
  Serial.begin(9600);
  
  // SDカードの初期化
  if (!SD.begin(chipSelect)) {
    Serial.println("SDカードの初期化失敗");
    return;
  }
  Serial.println("SDカードの初期化成功");
}

void loop() {
  // ログファイルにデータを追記する例
  File logFile = SD.open("/log.txt", FILE_APPEND);  // ログファイルを開く（追記モード）

  if (logFile) {
    String logData = "Data: " + String(millis());  // ログデータの作成
    logFile.println(logData);  // ログデータをファイルに追記(改行付き)
    logFile.close();  // ファイルを閉じる
    Serial.println("ログを追記しました: " + logData);
  } else {
    Serial.println("ログファイルを開けませんでした");
  }

  delay(1000); //1000ms 1s
}