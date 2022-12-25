#define RXp2 16
#define TXp2 17
#include <BleKeyboard.h>

BleKeyboard bleKeyboard;

void setup() {
// put your setup code here, to run once:
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, RXp2, TXp2);
  bleKeyboard.begin();
}
void loop() {
  if(bleKeyboard.isConnected()) {
    String get = Serial1.readString();
    if(get == "Enter") {
      get = "";
      bleKeyboard.press(KEY_RETURN);
      bleKeyboard.releaseAll();
      }
    else if (get == "Backspace"){
      get = "";
      bleKeyboard.write(KEY_BACKSPACE);}
    else if (get == "Space"){
      get = "";
      bleKeyboard.print(" ");}
    else if (get != "")
      bleKeyboard.print(get);
    //if (get != "")
     // Serial.println("got: "+get);
  }
}