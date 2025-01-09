#include "HX711.h"
#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 165;
const int colorB = 0;

// 接線設定
const int DT_PIN_FT = 2;
const int SCK_PIN_FT = 3;

const int DT_PIN_T = 4;
const int SCK_PIN_T = 5;

const int DT_PIN_F = 6;
const int SCK_PIN_F = 7;

const int DT_PIN_O = 8;
const int SCK_PIN_O = 9;

const int scale_factor_FT = -1013; //比例參數，從校正程式中取得(50$:90,10$:179,5$:153,1$20)
const int scale_factor_T = -1013;//-1050
const int scale_factor_F = -1013;//-1090
const int scale_factor_O = -1013;

HX711 scale1;
HX711 scale2;
HX711 scale3;
HX711 scale4;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setRGB(colorR , colorG , colorB);


  //////////50$/////////////
  Serial.println("Initializing the scale");

  scale1.begin(DT_PIN_FT, SCK_PIN_FT);

  Serial.println("Before setting up the scale:"); 
  
  Serial.println(scale1.get_units(5), 0);	//未設定比例參數前的數值

  scale1.set_scale(scale_factor_FT);       // 設定比例參數
  scale1.tare();				        // 歸零

  Serial.println("After setting up the scale:"); 

  Serial.println(scale1.get_units(5), 0);  //設定比例參數後的數值

  Serial.println("Readings:");  //在這個訊息之前都不要放東西在電子稱上
  //////////50$/////////////


  //////////10$/////////////
  Serial.println("Initializing the scale");

  scale2.begin(DT_PIN_T, SCK_PIN_T);

  Serial.println("Before setting up the scale:"); 
  
  Serial.println(scale2.get_units(5), 0);	//未設定比例參數前的數值

  scale2.set_scale(scale_factor_T);       // 設定比例參數
  scale2.tare();				        // 歸零

  Serial.println("After setting up the scale:"); 

  Serial.println(scale2.get_units(5), 0);  //設定比例參數後的數值

  Serial.println("Readings:");  //在這個訊息之前都不要放東西在電子稱上
  //////////50$/////////////

  //////////5$/////////////
  Serial.println("Initializing the scale");

  scale3.begin(DT_PIN_F, SCK_PIN_F);

  Serial.println("Before setting up the scale:"); 
  
  Serial.println(scale3.get_units(5), 0);	//未設定比例參數前的數值

  scale3.set_scale(scale_factor_F);       // 設定比例參數
  scale3.tare();				        // 歸零

  Serial.println("After setting up the scale:"); 

  Serial.println(scale3.get_units(5), 0);  //設定比例參數後的數值

  Serial.println("Readings:");  //在這個訊息之前都不要放東西在電子稱上
  //////////5$/////////////
  
  //////////1$/////////////
  Serial.println("Initializing the scale");

  scale4.begin(DT_PIN_O, SCK_PIN_O);

  Serial.println("Before setting up the scale:"); 
  
  Serial.println(scale4.get_units(5), 0);	//未設定比例參數前的數值

  scale4.set_scale(scale_factor_O);       // 設定比例參數
  scale4.tare();				        // 歸零

  Serial.println("After setting up the scale:"); 

  Serial.println(scale4.get_units(5), 0);  //設定比例參數後的數值

  Serial.println("Readings:");  //在這個訊息之前都不要放東西在電子稱上
  //////////10$/////////////
}

void loop() {
  Serial.print("50$Weight");
  Serial.println(scale1.get_units(10), 1); 
  Serial.print("50$Weight");
  Serial.println(scale1.get_units(10), 1); 

  scale1.power_down();			        // 進入睡眠模式
  delay(1000);
  scale1.power_up();               // 結束睡眠模式

  Serial.print("10$Weight");
  Serial.println(scale2.get_units(10), 1); 
  Serial.print("10$Weight");
  Serial.println(scale2.get_units(10), 1);

  scale2.power_down();			        // 進入睡眠模式
  delay(1000);
  scale2.power_up();               // 結束睡眠模式

  Serial.print("5$Weight");
  Serial.println(scale3.get_units(10), 1); 
  Serial.print("5$Weight");
  Serial.println(scale3.get_units(10), 1);

  scale3.power_down();			        // 進入睡眠模式
  delay(1000);
  scale3.power_up();               // 結束睡眠模式

  Serial.print("1$Weight");
  Serial.println(scale4.get_units(10), 1); 
  Serial.print("1$Weight");
  Serial.println(scale4.get_units(10), 1);

  scale4.power_down();			        // 進入睡眠模式
  delay(1000);
  scale4.power_up();               // 結束睡眠模式

  int a = scale1.get_units(10)/9.8;
  int b = scale2.get_units(10)/7.3;
  int c = scale3.get_units(10)/3.9;
  int d = scale4.get_units(10)/3.6;
  int Total = 50 * a + 10 * b + 5 * c + 1 * d;
  // Serial.println(a);
  lcd.clear();//清除LCD
  lcd.setCursor(0,0);
  lcd.print("50=");
  lcd.print(a);
  lcd.print(",");
  lcd.print("5=");
  lcd.print(c);

  lcd.setCursor(0,1);
  lcd.print("10=");//在顯示器上顯示輸入的轉動值
  lcd.print(b);
  lcd.print(",");
  lcd.print("1=");
  lcd.print(d);

  lcd.setCursor(10,0);
  lcd.print("T=");
  lcd.print(Total);

  delay(1000);    //延遲1s}


}