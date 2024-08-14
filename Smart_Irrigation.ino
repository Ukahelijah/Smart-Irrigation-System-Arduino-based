/////////////////Smart Water plant Irrigation System///////////////////
////////////////////////////////By////////////////////////////////////
////////////////////////////EJ TEACH TECH////////////////////////////
////Set your affection on things above, not on things on the earth Col.3:15////
#include <LiquidCrystal_I2C.h>

#define sensorPin A0
#define Pump 5

LiquidCrystal_I2C lcd(0x27,16,2);
int sVal;
int threshold =40;
int moisture;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
lcd.init();
lcd.backlight();
pinMode(sensorPin,INPUT);
pinMode(Pump,OUTPUT);
lcd.setCursor(0,0);
lcd.print("Smart Irrigation");
lcd.setCursor(0,1);
lcd.print("     System     ");
delay(2000);
lcd.setCursor(0,0);
lcd.print("       By       ");
lcd.setCursor(0,1);
lcd.print("  EJ TEACH TECH ");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("     System     ");
lcd.setCursor(0,1);
lcd.print("Initializing");
lcd.setCursor(12,1);
lcd.print(".");
delay(2000);
lcd.setCursor(13,1);
lcd.print(".");
delay(2000);
lcd.setCursor(14,1);
lcd.print(".");
delay(2000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Moisture is:");
lcd.setCursor(0,1);
lcd.print("Pump Status:");



}

void loop() {
  // put your main code here, to run repeatedly:
sVal= analogRead(sensorPin);
moisture= (100.00-((sVal/1023.00)*100.00));
lcd.setCursor(12,0);
lcd.print(moisture);
lcd.print("% ");
delay(2000);
lcd.setCursor(12,1);
lcd.print("OFF");
if(moisture<threshold){
  digitalWrite(Pump,HIGH);
  lcd.setCursor(12,1);
lcd.print("ON ");
}
else{
  digitalWrite(Pump,LOW);
  lcd.setCursor(12,1);
lcd.print("OFF");
}

}
