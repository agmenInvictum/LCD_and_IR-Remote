#include <IRremote.h>
#include <stdlib.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/*
 * Vent an 5V extern anschliessen
 * Button 
 */

const int volDown = 16580863;
const int playPause = 16613503;
const int volUp = 16597183;
const int setupp = 16589023;
const int prev = 16621663;
const int stopMode = 16605343;
const int chDown = 16584943;
const int enterSave = 16617583;
const int chUp = 16601263;
const int zeroTenPlus = 16593103;
const int next = 16625743;
const int returnn = 16609423;
const int one = 16582903;
const int two = 16615543;
const int three = 16599223;
const int four = 16591063;
const int five = 16623703;
const int six = 16607383;
const int seven = 16586983;
const int eight = 16619623;
const int nine = 16603303;
const int zero = 4294967295;


const int VENT_PIN = 6;
int ventSpeed = 125;
int key_value = 0;
const int LCDPort = 12;
const int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;
bool ventStatus = false;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
  lcd.begin(16, 2);
  lcd.print("Started! We");
  lcd.setCursor(0, 1);
  lcd.print("have big dix");
  delay(3000);
  lcd.clear();
  pinMode(VENT_PIN, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)){
    irrecv.resume();
    
    if (results.value == zero) {
      delay(100);
      results.value = key_value;
    }

    switch (results.value) {
      case volDown:
        if (ventSpeed < 256 && ventSpeed > 75) {
          ventSpeed = ventSpeed - 25;
          analogWrite(VENT_PIN, ventSpeed);
          lcd.clear();
          delay(10);
          lcd.print(ventSpeed);
          Serial.println(ventSpeed);
        }
        break;

      case playPause:
        if (ventStatus == false) {
          analogWrite(VENT_PIN, ventSpeed);
          ventStatus = true;
        } else {
          analogWrite(VENT_PIN, 0);
          ventStatus = false;
        }
        break;

      case volUp:
        if (ventSpeed < 230 && ventSpeed > 0) {
          ventSpeed = ventSpeed + 25;
          analogWrite(VENT_PIN, ventSpeed);
          lcd.clear();
          delay(10);
          lcd.print(ventSpeed);
          Serial.println(ventSpeed);
        }
        break;

      case setupp:
        break;

      case prev:
        break;

      case stopMode:
        break;

      case chDown:
        break;

      case enterSave:
        break;

      case chUp:
        break;

      case zeroTenPlus:
        break;

      case next:
        break;

      case returnn:
        break;

      case one:
        lcd.clear();
        delay(100);
        lcd.print("EINS!");
        break;

      case two:
        lcd.clear();
        delay(100);
        lcd.print("ZWEI!");
        break;

      case three:
        lcd.clear();
        delay(100);
        lcd.print("DREI!");
        break;

      case four:
        lcd.clear();
        delay(100);
        lcd.print("VIER!");
        break;

      case five:
        lcd.clear();
        delay(100);
        lcd.print("FÜNF!");
        break;

      case six:
        lcd.clear();
        delay(100);
        lcd.print("SECHS!");
        break;

      case seven:
        lcd.clear();
        delay(100);
        lcd.print("SIEBEN!");
        break;

      case eight:
        lcd.clear();
        delay(100);
        lcd.print("ACHT!");
        break;

      case nine:
        lcd.clear();
        delay(100);
        lcd.print("NEUN!");
        break;
    }
     
    key_value = results.value;
    irrecv.resume();
  }
}
