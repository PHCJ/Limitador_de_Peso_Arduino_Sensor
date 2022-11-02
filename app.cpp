#include <LiquidCrystal.h>

const int RS = 13;
const int ENBL = 12;
const int DB4 = 7;
const int DB5 = 6;
const int DB6 = 5;
const int DB7 = 4;
const int SENSORFRC = A0;
const int led = 11;
const int bzzr = 8;

int sensor = 0;
int sConvert = 0;

LiquidCrystal lcd (RS,ENBL,DB4,DB5,DB6,DB7);

void setup()
{
  pinMode(SENSORFRC, INPUT);
  pinMode(led, OUTPUT);
  pinMode(bzzr, OUTPUT);
  lcd.begin(16,2);
  Serial.begin(9600);  
}

void loop()
{
  sensor = analogRead(SENSORFRC);
  sConvert = map(sensor, 0,914,0,500);
  noTone(bzzr);
  if(sConvert >= 300){
  	digitalWrite(led, HIGH);
    tone(bzzr,1600);
  } else{
    digitalWrite(led, LOW); 
  }
  Serial.println(sConvert);
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("PESO:");
  lcd.setCursor(9,0);
  lcd.print(sConvert);
  lcd.write(B10110010);
  lcd.write("KG");
  delay(100);
}