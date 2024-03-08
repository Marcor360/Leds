#include <Adafruit_NeoPixel.h>
#include <SoftwareSerial.h>

int numberShowEntry;
int numberShowOut;
int ledPin1 = 10;      // Pin de jugadores de entrada
int ledPin2 = 12;    // Pin de jugadores de salida
int numLeds1 = 126;  // Leds de jugadores de entrada
int numLeds2 = 125;  // Leds de jugadores de salida
const int BUFFER_SIZE = 10;
char buffer[BUFFER_SIZE];
int bufferIndex = 0;

SoftwareSerial mySerial(7, 8);
Adafruit_NeoPixel ledStrip1 = Adafruit_NeoPixel(numLeds1, ledPin1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledStrip2 = Adafruit_NeoPixel(numLeds2, ledPin2, NEO_GRB + NEO_KHZ800);



void setup() {
  ledStrip1.begin();
  ledStrip1.show();
  ledStrip2.begin();
  ledStrip2.show();
  mySerial.begin(9600);
  mySerial.println("Connection Successfully");
}

void loop() {
  displayNumberEntry(numberShowEntry, ledStrip1);
  displayNumberEntry(numberShowOut, ledStrip2);

  while (mySerial.available()) {
    char receivedChar = mySerial.read();

    if (receivedChar == '\n') {
      buffer[bufferIndex] = '\0';  
      processSerialData();
      bufferIndex = 0;  
    } else {
      buffer[bufferIndex] = receivedChar;
      bufferIndex = (bufferIndex + 1) % BUFFER_SIZE;
    }
  }
}

void processSerialData() {
  if (bufferIndex > 0) {
    int value = atoi(buffer);

    if (value >= 1 && value <= 99) {
      turnOffAllLEDs(ledStrip1, numLeds1);
      displayNumberEntry(value, ledStrip1);
    } else if (value >= 101 && value <= 199) {
      turnOffAllLEDs(ledStrip2, numLeds2);
      displayNumberOut(value, ledStrip2);
    }
  }
}

void displayNumberEntry(int numberEntry, Adafruit_NeoPixel &ledStrip1) {

  if (numberEntry >= 1 && numberEntry <= 99) {
    switch (numberEntry) {

      case 1:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(18, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 2:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 3:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 4:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 5:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 6:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 7:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 8:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 9:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 10:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;

      case 11:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(18, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 12:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;

      case 13:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 14:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 15:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 16:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 17:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 18:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 19:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(72, 80, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 20:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 21:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 22:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 23:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 24:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 25:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 26:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 27:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 28:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;

      case 29:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(99, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 89, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 30:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 31:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 32:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 33:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 34:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 35:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 36:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 37:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 38:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 39:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 40:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 41:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 42:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 43:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 44:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 45:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 46:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 47:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 48:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;

      case 49:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 107, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(117, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 50:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;

      case 51:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 52:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 53:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 54:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 55:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 56:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 57:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 58:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 59:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(81, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 60:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 61:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 62:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 63:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 64:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 65:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 66:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 67:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 68:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 69:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 98, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(108, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 70:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 71:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 72:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 73:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 74:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 75:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 76:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 77:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 78:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 79:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(90, 116, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 80:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 81:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 82:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 83:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 84:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 85:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 86:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 87:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 88:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 89:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(63, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
      case 90:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 91:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 92:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(9, 26, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 93:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 94:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 35, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(45, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 95:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 96:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 44, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(54, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 97:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(36, 53, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 8, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 98:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));

        break;
      case 99:
        turnOffAllLEDs(ledStrip1, numLeds1);
        turnOnLEDRange(81, 125, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(63, 71, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(27, 62, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        turnOnLEDRange(0, 17, ledStrip1, numLeds1, ledStrip1.Color(0, 255, 0));
        break;
    }
  }
}

void displayNumberOut(int numberOut, Adafruit_NeoPixel &ledStrip2) {


  if (numberOut >= 101 && numberOut <= 199) {
    switch (numberOut) {

      case 101:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 102:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 103:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 104:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 105:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 106:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 107:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 108:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 109:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 110:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 111:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(89, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 112:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 113:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 114:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 115:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 116:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 117:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 118:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 119:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(44, 52, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 120:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 121:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 122:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;
      case 123:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 124:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 125:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 126:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 127:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 128:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 129:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 25, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(35, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 130:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 131:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 132:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 133:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 134:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 135:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 136:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 137:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 138:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 139:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 140:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 141:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 142:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 143:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 144:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 145:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 146:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 147:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 148:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 149:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 7, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(17, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 150:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;


      case 151:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 152:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 153:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 154:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 155:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 156:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 157:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 158:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 159:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 160:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 161:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 162:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 163:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 164:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 165:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 166:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 167:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 168:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 169:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 16, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(26, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 170:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 171:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 172:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 173:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 174:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 175:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 176:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 177:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 178:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 179:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(8, 34, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 180:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 181:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 182:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 183:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 184:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 185:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 186:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 187:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 188:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 189:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 190:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 191:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 192:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(80, 97, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 70, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 193:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 194:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 106, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(116, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 195:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 196:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 115, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 197:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(71, 79, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(107, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 198:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;

      case 199:
        turnOffAllLEDs(ledStrip2, numLeds2);
        turnOnLEDRange(0, 43, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(53, 61, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(62, 88, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        turnOnLEDRange(98, 124, ledStrip2, numLeds2, ledStrip2.Color(255, 0, 0));
        break;
    }
  }
}

void turnOnLEDRange(int startLED, int endLED, Adafruit_NeoPixel &ledStrip, int numLeds, uint32_t color) {
  if (startLED >= 0 && startLED < numLeds && endLED >= startLED && endLED < numLeds) {
    for (int i = startLED; i <= endLED; i++) {
      ledStrip.setPixelColor(i, color);
    }
    ledStrip.show();
  }
}

void turnOffAllLEDs(Adafruit_NeoPixel &ledStrip, int numLeds) {
  for (int i = 0; i < numLeds; i++) {
    ledStrip.setPixelColor(i, ledStrip.Color(0, 0, 0));
  }
  ledStrip.show();
}