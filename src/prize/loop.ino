//=============== loop ===============
void loop() {
 //mqttReconnect();          //Make sure we stay connected to the mqtt broker

  if (startButtonFlag) {
    Serial.println(F("Start button pressed"));
    startButtonFlag = false;
    rotateTo360();
  }
}
