
void beginSerial() {
  Serial.begin(115200);
  delay(1);
  Serial.println();
  Serial.println();
  Serial.print(F("Sketch Name: "));
  Serial.println(F(SKETCH));
  Serial.print(F("Sketch Version: "));
  Serial.println(F(VERSION));
  Serial.println();
  delay(2500);
}

// ---------- Functions unique to this sketch ----------
// ========= Start the motor =========
void startTheMotor() {
  analogWrite(MOTOR_PIN, maxTorque);          //Turn on the motor (max torque) to get it started.
  delay(10);
  //while (!digitalRead(SWITCH_360) || !digitalRead(SWITCH_180)) yield(); //Wait until motor is not on a stop switch.
  analogWrite(MOTOR_PIN, runTorque);          //Slow it down
}



// ---------- Drop the prize ----------
void rotateTo180() {
  startTheMotor();
  while (digitalRead(SWITCH_180)) yield();     //Wait for the limit switch
  analogWrite(MOTOR_PIN, 0);                   //Stop the motor
  Serial.println(F("Stop at 180°"));
}

// ---------- Load the next prize ----------
void rotateTo360() {
  startTheMotor();
  while (digitalRead(SWITCH_360)) yield();     //Wait for the limit switch
  analogWrite(MOTOR_PIN, 0);                   //Stop the motor
  Serial.println(F("Stop at 360°"));
}





// ---------- interrupt handlers ----------

// Start Button Interrupt Handler
IRAM_ATTR void startButtonHandler() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  //Debounce
  if (interrupt_time - last_interrupt_time > 300)
  {
    startButtonFlag = true;
  }
  last_interrupt_time = interrupt_time;
}


/*
// Loop Button Interrupt Handler
IRAM_ATTR void loopButtonHandler() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  //Debounce
  if (interrupt_time - last_interrupt_time > 250)
  {
//    loopFlag = true;
  }
  last_interrupt_time = interrupt_time;
}
*/
