#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int x = 0;
int y = 0;
int z = 0;
int sen = 0;

void setup() {
  SerialBT.begin("Gesture_mouse");
  Serial.begin(9600);
  pinMode(27,INPUT);
}

void loop() {
  x = analogRead(35);
  y = analogRead(32);
  z = analogRead(33);
sen = digitalRead(27);

//SerialBT.print(x);SerialBT.print("  ");SerialBT.println(y);

  if (x < 1450) {
    SerialBT.println('2');
  }
  else if (x > 1650) {
    SerialBT.println('5');
  }
  else if (y < 1450) {
    SerialBT.println('4');
  }
  else if (y > 1600) {
    SerialBT.println('6');
  }

  if(sen == HIGH)
  {
    SerialBT.println('1');
  }
  delay(100);
}
