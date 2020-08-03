# はじめに
こちらは[Bocco API](http://api-docs.bocco.me/index.html#bocco-api-%E3%81%A8%E3%81%AF)をESP32で利用するためのライブラリとなります。
これまで、ESP8266用しかなかったためESP32でも使えるようにしました。
このライブラリは、[こちらを参考](https://github.com/tfuru/BoccoEsp)に改良しています。

# 事前準備
## 必要なもの 
- [BOCCO](https://store.ux-xu.com/products/bocco)  
- [ESP-WROOM-32D開発ボード](http://akizukidenshi.com/catalog/g/gM-13628/)   
- [BOCCO API](http://api-docs.bocco.me/index.html)  

## ライブラリー 
事前に以下のライブラリを利用しているので Arduino IDE でインストールしておく必要があります。  
- [Arduino core for the ESP32](https://github.com/espressif/arduino-esp32)  
- [WiFiManager](https://github.com/tzapu/WiFiManager)  
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson)  
- [ESPTrueRandom](https://github.com/sivar2311/ESPTrueRandom)  
  こちらはESP8266TrueRandomをESP32に対応するよう修正されたライブラリです。

## 本ライブラリのインストール方法
このリポジトリを zip でダウンロードして Arduino IDE から 指定してインポートをする。  
1. zip ダウンロードする。  
2. Arduino IDEを開く。  
3. スケッチ → ライブラリをインクルード → zip形式のライブラリをインストールを選択する。  
4. 1でダウンロードした zip ファイルを指定する。　　  

# サンプルコードについて 
## アクセストークンの取得
サンプルコードにでてくるアクセストークンの入力部分が、
[こちら](http://api-docs.bocco.me/get_access_token.html)を参考にアクセストークンを取得し、入力してください。

## 実行方法　
Arduino IDE で サンプルを読み込んでビルドして実行する。  
1. Arduino IDEを開く  
2. ファイル → スケッチ例 → BoccoEsp32 → sample を選択  
3. ビルドする

## 動作手順
初回はアクセスポイントモードで起動してWiFi設定が済むと BOCCO API へのアクセスを確認することができます。  
1. APモードで起動しているので、スマートフォンやPCで "test" に接続する  
2. 画面に従って WiFi 設定をする。  
3. リセットがかかり 設定した WiFiに接続される。  
4. 1番目のルームにメッセージが送信され、BOCCO から再生される。    
5. ESP-WROOM-32D開発ボード上のタクトスイッチ を押すと割り込みが発生後にメッセージを送信する。

