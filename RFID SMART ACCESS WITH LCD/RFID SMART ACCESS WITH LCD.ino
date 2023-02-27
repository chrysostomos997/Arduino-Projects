#include <SPI.h>
#include <MFRC522.h>
#include <virtuabotixRTC.h>
#include <LiquidCrystal.h>  // LCD MONITOR
#include <Servo.h>


// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(8, 9, 10);
Servo myservo;
#define SS_PIN 53
#define RST_PIN 5

#define LED_PIN_red 26
#define LED_PIN_green 24

MFRC522 mfrc522(SS_PIN, RST_PIN);
int buzzerPin = 2;
// initialize the library with the numbers of the interface pins *LCD
LiquidCrystal lcd(7, 4, 3, 11, 12, 13);


unsigned long startTime = 0;    // PASSIVE BUZZER FOR NO BLOCKING THE CODE 
unsigned long duration = 200;

void setup() {
  myservo.attach(6); 
  pinMode(LED_PIN_red, OUTPUT);
  pinMode(LED_PIN_green, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  myRTC.setDS1302Time(18, 10, 7, 5, 18, 1, 2023);
  lcd.begin(16, 2);

   pinMode(buzzerPin, OUTPUT);
   
}

void loop() {

   myservo.write(0);
delay(2000);  // wait 1 second



 lcd.setCursor(0, 0);
 lcd.print ("   PLEASE SCAN");
 lcd.setCursor(0, 1);
 lcd.print ("    YOUR CARD ");

  myRTC.updateTime();
 digitalWrite(LED_PIN_red, LOW);
  digitalWrite(LED_PIN_green, LOW);
   
  if (!mfrc522.PICC_IsNewCardPresent())  // !=(logical not)
  {
    return;  //RETURN TO SCAN AGAIN 
  }
  // TAG
  if (!mfrc522.PICC_ReadCardSerial())  // TRY TO READ 
  {

     
    return;  // IF NOT RETURN
  }


  //FOR SERIAL MONITOR 
  Serial.print("UID tag :");
  String content = "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++)  // LOOP (size of the card)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }


  Serial.println();  
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "D0 5D C5 25")
  //  || content.substring(1) == "17 E2 45 1B") //change the UID in card to have access 




     startTime = millis();
while (millis() - startTime <= duration) {
  tone(buzzerPin, 500,600);
  delay(1);
}

  lcd.clear();
    Serial.println("Chrysostomos Intzempeis");  //success
    lcd.print("   WELCOME ");
    lcd.setCursor(0, 1);
     lcd.print(" CHRYSOSTOMOS ");
     digitalWrite(LED_PIN_green, HIGH);

    delay(2000); 

    myservo.write(180);
delay(2000);  // wait 1 second


    lcd.clear(); //wait 3 sec 


  } else {

startTime = millis();
while (millis() - startTime <= duration) {
  tone(buzzerPin, 100, 600);
  delay(1);
}
    lcd.clear();
    Serial.println(" Access denied");  //then fail 
    lcd.print("   WRONG CARD  ");
    lcd.setCursor(0, 1);
    lcd.print("   TRY AGAIN  ");
    digitalWrite(LED_PIN_red, HIGH);
    delay(3000);  //wait  3 sec
     lcd.clear();

  }
 
  // LCD *************************************************************************************
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  // lcd.setCursor(0, 1);

  // print the number of seconds since reset:
  // lcd.print(millis() / 1000);
  //  lcd.print(" ");

  // LCD *************************************************************************************

  // Start printing elements as individuals
 
//   Serial.print("Current Date :");
//   Serial.print(myRTC.dayofmonth);
//   Serial.print("/");
//   Serial.print(myRTC.month);
//   Serial.print("/");
//   Serial.print(myRTC.year);
//   Serial.print("  ");
//   Serial.print('\n');
//   Serial.print("Time: ");
//   Serial.print(myRTC.hours);
//   Serial.print(":");
//   Serial.print(myRTC.minutes);
//   Serial.print(":");
//   Serial.println(myRTC.seconds);
//   Serial.print('\n');

//   // // delay(5000);
//   // //LCD 
  
lcd.print(myRTC.dayofmonth);
lcd.print("/");
lcd.print(myRTC.month);
lcd.print("/");
lcd.print(myRTC.year);
  lcd.setCursor(0, 1);

  
// //LCD TIME
  lcd.print (" ");
  lcd.print(myRTC.hours);
  lcd.print(":");
  lcd.print(myRTC.minutes);
  lcd.print(":");
  lcd.print(myRTC.seconds);
  delay(2000);
  lcd.clear();



}

//     if(myservo.read() == 0)
// {
//   myservo.write(90);
//      delay(1000); // wait 1 second
// }
//   // myservo.write(0); // set the servo to 90 degrees

//   myservo.write(0); // set the servo to 90 degrees
//      delay(1000); // wait 1 second


