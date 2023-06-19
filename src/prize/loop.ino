//=============== loop ===============
void loop() {
  ArduinoOTA.handle();
  //mqttReconnect();          //Make sure we stay connected to the mqtt broker

  //Start rotating, stop at 180° briefly then continue to 360°
  if (startButtonFlag) {
    Serial.println(F("Start button pressed"));
    startButtonFlag = false;
    rotateTo180();
    delay(500);
    rotateTo360();
  }
}
