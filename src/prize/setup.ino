//=============== setup ===============
void setup() {
  pinMode(closedSwitch, INPUT_PULLUP);
  pinMode(openSwitch, INPUT_PULLUP);
  pinMode (BUTTON_PIN, INPUT_PULLUP);
  pinMode (LOOP_PIN, INPUT_PULLUP);
  pinMode(BLUE_LED_PIN, OUTPUT);
  analogWrite(MOTOR_PIN, 0);             //PWM pin, start at zero.
  pinMode(EYES_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);

  beginSerial();
  ///setup_wifi();
  //setup_wifiMulti();
  setup_mqtt();                         //Generate the topics
  client.setServer(mqttServer, mqttPort);
  mqttConnect();


  //Lid
  Serial.println(F("Test the lid."));
  loopFlag = false;
  openTheLid();
  delay(1000);
  closeTheLid();

  loopFlag = false;



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
