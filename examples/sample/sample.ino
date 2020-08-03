#include <WiFiManager.h>
#include <WiFi.h>

#include "config.h"
#include "bocco_api.h"

//BOCCO API ライブラリ
//BOCCO アカウント情報
//APIで登録した情報、API KEYを入力してください
#define BOCCO_EMAIL     "user@example.com"
#define BOCCO_PASSWORD  "strongpassword"
#define BOCCO_API_KEY   "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
//初期設定の為のアクセスポイント名
#define AP_NAME "test"

BoccoAPI boccoAPI(BOCCO_EMAIL, BOCCO_PASSWORD, BOCCO_API_KEY);

//プッシュスイッチ
const int SW = 0;
int valueSW = HIGH;

void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFiManager wifiManager;
  wifiManager.setTimeout(180);
  if(!wifiManager.autoConnect(AP_NAME)) {
    Serial.println("timeout");
    delay(3000);
    //初期設定が成功しない場合 reset して初期設定をリトライする
    ESP.reset();
    delay(5000);
    return;
  }
  //ルーターとの接続に成功
  Serial.println("connected...");
  delay(1000);


  //BOCCO アクセストークンを取得する
  // if(!boccoAPI.createSessions() ){
  //   Serial.println("BOCCO アクセストークン取得に失敗");
  //   return;
  // }
  

  //アクセストークンを設定（上記の）
  //下記を参考にアクセストークンを取得し、xxxxxに代入してください。
  //http://api-docs.bocco.me/get_access_token.html
  boccoAPI.setAccessToken("xxxxx");

  //BOCCO 1番目のルームを取得
  if(!boccoAPI.getFirstRoom()){
      Serial.println("BOCCO ルーム取得に失敗");
      return;
  }

  boccoAPI.postMessageText("BOCCOをみつけたよ");

  //ボタン割り込み設定
  pinMode(SW, INPUT_PULLUP);
  attachInterrupt(SW, clickSw, CHANGE );
}

//ボタン割り込み
void clickSw(){
  Serial.println("clickSw");
  valueSW = digitalRead(SW);
}

void loop() {
  if(valueSW == LOW){
    boccoAPI.postMessageText("BOCCOからの手紙が届いたよ。ボタンを押されたよ！");
  }
  delay(100);
}
