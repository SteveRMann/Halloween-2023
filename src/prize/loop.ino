//=============== loop ===============
void loop() {
 //mqttReconnect();          //Make sure we stay connected to the mqtt broker

  if (buttonFlag) {
    Serial.println(F("Action button pressed"));
    buttonFlag = false;
  }
}
