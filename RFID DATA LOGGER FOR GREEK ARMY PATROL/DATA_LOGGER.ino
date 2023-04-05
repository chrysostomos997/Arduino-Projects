#include <SPI.h>
#include <MFRC522.h>
#include <virtuabotixRTC.h>
#include <SD.h>


// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(5, 7, 8);

#define SS_PIN 10
#define RST_PIN 9
#define Led_pin 6
#define Led_pinRED 2

//Instanse of the class for RFID
MFRC522 mfrc522(SS_PIN, RST_PIN);
int buzzerPin = 3;

// //chip select sd
const int chipSelect = 4;

void setup() {
  pinMode(Led_pin, OUTPUT);
  pinMode(Led_pinRED, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  SPI.begin();
  //myRTC.setDS1302Time(30, 36, 12, 2, 28, 3, 2023); // Run it only once 
  mfrc522.PCD_Init();
 
  while (!Serial) {
    ;
  }


  while (!SD.begin(chipSelect)) {
    Serial.println("Initialization failed!");
    delay(1000);
    tone(buzzerPin, 100, 600);
    digitalWrite(Led_pinRED, HIGH);
    delay(1000);
    digitalWrite(Led_pinRED, LOW);
  }
  Serial.println("Initialization done.");
  digitalWrite(Led_pinRED, LOW);
  tone(buzzerPin, 500, 600);
  digitalWrite(Led_pin, HIGH);
  delay(1000);
  digitalWrite(Led_pin, LOW);
}


void loop() {




  myRTC.updateTime();


  if (!mfrc522.PICC_IsNewCardPresent())  // !=(logical not)
  {


    return;
  } else {


    if (mfrc522.PICC_ReadCardSerial()) {

      Serial.print("UID tag :");
      String content = "";
      byte letter;
      for (byte i = 0; i < mfrc522.uid.size; i++)  //  UID
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
      //  || content.substring(1) == "17 E2 45 1B")  We can control any card here with the UID 

      {
        tone(buzzerPin, 3000, 600);
        digitalWrite(Led_pin, HIGH);
        delay(1000);
        digitalWrite(Led_pin, LOW);
        Serial.println("PERIPOLO"); // PERIPOLO==PATROL 
        File dataFile = SD.open("data.txt", FILE_WRITE);
        dataFile.print("PERIPOLO");
        delay(1000);
        dataFile.close();

      } else {



        tone(buzzerPin, 3000, 600);
        digitalWrite(Led_pin, HIGH);
        delay(1000);
        digitalWrite(Led_pin, LOW);
        Serial.println(" EFODOS");  // EFODOS == PATROL FROM ARMY OFFICER 
        File dataFile = SD.open("data.txt", FILE_WRITE);
        dataFile.print("EFODOS");
        dataFile.print("  ");
        dataFile.close();

        delay(1000);
      }

      // WRITE DATA IN SD CARD AND PRINT THEM IN SERIAL MONITOR AS WELL.
      File dataFile = SD.open("data.txt", FILE_WRITE);
      Serial.print("IMEROMINIA :");
      dataFile.print("  ");
      if (myRTC.dayofmonth < 10)  // FOR 5:3 --> 05:03
        Serial.print("0");
      Serial.print(myRTC.dayofmonth);
      if (myRTC.dayofmonth < 10)
        dataFile.print("0");
      dataFile.print(myRTC.dayofmonth);
      // data file
      dataFile.print("/");
      if (myRTC.month < 10)
        dataFile.print("0");
      dataFile.print(myRTC.month);
      dataFile.print("/");
      dataFile.print(myRTC.year);
      dataFile.print("  ");
      if (myRTC.hours < 10)
        dataFile.print("0");
      dataFile.print(myRTC.hours);
      dataFile.print(":");
      if (myRTC.minutes < 10)
        dataFile.print("0");
      dataFile.println(myRTC.minutes);
      // dataFile.print(":");
      // dataFile.println(myRTC.seconds);
      dataFile.close();
      Serial.print("/");
      if (myRTC.month < 10)
        Serial.print("0");
      Serial.print(myRTC.month);
      Serial.print("/");
      Serial.print(myRTC.year);
      Serial.print("  ");
      Serial.print('\n');
      Serial.print("Time: ");
      if (myRTC.hours < 10)
        Serial.print("0");
      Serial.print(myRTC.hours);
      Serial.print(":");
      if (myRTC.minutes < 10)
        Serial.print("0");
      Serial.print(myRTC.minutes);
      // Serial.print(":");
      //  if(myRTC.seconds < 10)
      //  Serial.print("0");
      // Serial.println(myRTC.seconds);
      Serial.print('\n');
    }
  }
}
