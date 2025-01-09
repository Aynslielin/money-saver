int val;
void setup() {
// put your setup code here, to run once:
// Serial.begin(9600);
pinMode(A1, INPUT);
pinMode(12, OUTPUT);//藍色LED
pinMode(13,OUTPUT);//黃色LED
}

void loop() 
{
  val = analogRead(A1);
  // Serial.println(val);
  if(val < 400)           //硬幣未通過時亮藍燈
  {
  digitalWrite(12, HIGH);//藍色亮
  digitalWrite(13, LOW);//黃色暗
  }else                 //硬幣通過時亮黃燈
  {
  digitalWrite(12, LOW);//藍色暗
  digitalWrite(13, HIGH);//黃色亮
  delay(1000);//硬幣通過時延遲5秒
  }
}
