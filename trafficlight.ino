//including the LCD lib
#include <LiquidCrystal_I2C.h>

//declaring what LCD pins where we are sending the data
LiquidCrystal_I2C lcd(0x27, 16, 2);

//for traffic light one
int red1=10;
int yellow1=9;
int green1=8;

//for traffic light two
int red2=13;
int yellow2=12;
int green2=11;

int button=7;

void setup() {
  //traffic light one
  pinMode(red1, OUTPUT);
  pinMode(yellow1, OUTPUT);
  pinMode(green1, OUTPUT);

  //traffic light two
  pinMode(red2, OUTPUT);
  pinMode(yellow2, OUTPUT);
  pinMode(green2, OUTPUT);

  //pinMode(button, INPUT);
  //digitalWrite(yellow1, HIGH);
  //digitalWrite(yellow2, HIGH);
}

void loop() {
  //if(digitalRead(button)==HIGH){
    //delay(15);//software debounce
    //if(digitalRead(button)==HIGH){
    changeColour();
    delay(15000);
 //   }
//  }
}
void changeColour(){
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  //turn both the yellow light on
  digitalWrite(green1, LOW);
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("------WAIT------");
  delay(5000);

  //turn  both the yellow light off, and the opposite green and red
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, HIGH);
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, LOW);
  digitalWrite(green2, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("------STOP------");
  delay(10000);

  //both the yellow light on again
  digitalWrite(yellow1, HIGH);
  digitalWrite(yellow2, HIGH);
  digitalWrite(green2, LOW);
  delay(3000);

  //turn off both the yellow light, and opposite green and red
  digitalWrite(green1, HIGH);
  digitalWrite(yellow1, LOW);
  digitalWrite(red1, LOW);
  digitalWrite(yellow2, LOW);
  digitalWrite(red2, HIGH);
  lcd.setCursor(0, 0);
  lcd.print("-------GO-------");
  delay(10000);
}
