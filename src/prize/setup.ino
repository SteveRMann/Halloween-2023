//=============== setup ===============
void setup() {
  pinMode(LOAD_SWITCH, INPUT_PULLUP);
  pinMode(DUMP_SWITCH, INPUT_PULLUP);
  pinMode (START_PIN, INPUT_PULLUP);
  pinMode(BLUE_LED_PIN, OUTPUT);
  analogWrite(MOTOR_PIN, 0);             //PWM pin, start at zero.


  beginSerial();
  setup_wifi();
  //setup_mqtt();                         //Generate the topics
  client.setServer(mqttServer, mqttPort);
  //mqttConnect();


  Serial.println(F("Rotate once"));
  rotateTo180();
  delay(1000);
  rotateTo360();


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
