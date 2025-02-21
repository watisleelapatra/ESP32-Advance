#define BLYNK_TEMPLATE_ID "TMPL6ds59DpMN"   //<--- เปลี่ยนบรรทัดนี้ตามหน้า Blynk Console
#define BLYNK_TEMPLATE_NAME "LED Template"  //<--- เปลี่ยนบรรทัดนี้ตามหน้า Blynk Console
#define BLYNK_AUTH_TOKEN "es5qocSbceF9pMAqRuNN_mIhlu4RGtuO" //<--- เปลี่ยนบรรทัดนี้ตามหน้า Blynk Console
#define BLYNK_PRINT Serial
#define LED1 19
#define LED2 23
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "mate9";
char pass[] = "0816621438";
// This function is called every time the Virtual Pin 0 state changes
BLYNK_WRITE(V0){
  int value = param.asInt();
  if(value == 1){
    digitalWrite(LED1, HIGH);
     Serial.println('1');
  }else{
   digitalWrite(LED1, LOW);
    Serial.println('0');
  }
  }
BLYNK_WRITE(V1){
    int value = param.asInt();
  if(value == 1){
    digitalWrite(LED2, HIGH);
     Serial.println('1');
  }else{
   digitalWrite(LED2, LOW);
    Serial.println('0');
  }
  }
void setup(){
  pinMode(LED2, OUTPUT);
  pinMode(LED1, OUTPUT);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
}
void loop(){
  Blynk.run();
}
