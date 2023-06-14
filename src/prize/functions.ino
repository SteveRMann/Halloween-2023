// ********************** Function to display a string for debugging. **********************
void dbugs(const char *s, const char *v) {
  //Show a string variable. Enter with the string description and the string.
  //Example dbugs("My String= ",myString);
  Serial.print(s);
  Serial.print (F("\""));
  Serial.print(v);
  Serial.println(F("\""));
}


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
  delay(1);
  ///while (!digitalRead(openSwitch) || !digitalRead(openSwitch)) yield(); //Wait until motor is not on a stop switch.
  analogWrite(MOTOR_PIN, runTorque);          //Slow it down
}



// ---------- Drop the prize ----------
void openTheLid() {
  startTheMotor();
  while (digitalRead(openSwitch)) yield();     //Wait for the limit switch
  analogWrite(MOTOR_PIN, 0);                   //Stop the motor
  Serial.println(F("OPEN"));
}

// ---------- Load the next prize ----------
void closeTheLid() {
  startTheMotor();
  while (digitalRead(closedSwitch)) yield();        //Wait for the limit switch
  analogWrite(MOTOR_PIN, 0);                        //Stop the motor
  Serial.println(F("CLOSED"));
}




// ---------- button handlers ----------

// Action Button Interrupt Handler
IRAM_ATTR void actionButtonHandler() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  //Debounce
  if (interrupt_time - last_interrupt_time > 250)
  {
    buttonFlag = true;
  }
  last_interrupt_time = interrupt_time;
}

// Loop Button Interrupt Handler
IRAM_ATTR void loopButtonHandler() {
  static unsigned long last_interrupt_time = 0;
  unsigned long interrupt_time = millis();
  //Debounce
  if (interrupt_time - last_interrupt_time > 250)
  {
    loopFlag = true;
  }
  last_interrupt_time = interrupt_time;
}
