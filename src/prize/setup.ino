//=============== setup ===============
void setup() {
  pinMode(SWITCH_180, INPUT_PULLUP);
  pinMode(SWITCH_360, INPUT_PULLUP);
  pinMode (START_PIN, INPUT_PULLUP);
  pinMode(BLUE_LED_PIN, OUTPUT);
  analogWrite(MOTOR_PIN, 0);             //PWM pin, start at zero.


  beginSerial();
  setup_wifi();
  //setup_mqtt();                         //Generate the MQTT topics
  client.setServer(mqttServer, mqttPort);
  //mqttConnect();

  start_OTA();

  attachInterrupt(START_PIN, startButtonHandler, RISING);

  Serial.println(F("Motor running"));
  startTheMotor();
  rotateTo360();
  Serial.println(F("Motor stopped at 360°"));


  /*
    // ========== MOTORTEST ==========
    // Neverending function to find the minimum torque needed
    // to run the motor
    maxTorque = 255;
    while (1) {
      sensorValue = analogRead(sensorPin);
      runTorque = sensorValue;
      Serial.print(F("runTorque= "));
      Serial.println(runTorque);
      startTheMotor();
      delay(1000);
    }
  */



} //End of setup()
