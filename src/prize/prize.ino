#define SKETCH "prize.ino"
#define VERSION "1.0"
#define NODENAME "prize"


/*
   Using Wemos D1 Mini
   Project is a package delivery system.
   A half-round motorized tray collects the item to deliver, and on command, rotates 180°, dropping
   the item in a catch tray, then completes the 360° rotation, collecting the next item.
*/

const int LED_ON = 1;
const int LED_OFF = 0;

const int LOAD_SWITCH = D1;              //Limit pin, stops the motor 1t 180°
const int DUMP_SWITCH = D2;               //Limit pin, stops the motor at 360°
const int MOTOR_PIN = D3;                 //Motor PWM
const int START_PIN = D4;                //Start button
const int BLUE_LED_PIN = D8;              //Status

int maxTorque = 255;
int runTorque = 165;



const long int MINUTES = 60000;           //ms per minute
const long int SECONDS = 1000;            //ms per second
const int MIN_PWM = 200;                  //Anything lower and the motor won't start
int motorPwm = MIN_PWM;                   //PWM value for motor on.


// --------------- button declarations ---------------
volatile bool buttonFlag = false;         //True when start button is pressed
volatile bool stopFlag = false;           //True when stop switch is hit




//--------------- WiFi declarations ---------------
#include "ESP8266WiFi.h"        // Not needed if also using the Arduino OTA Library...
#include <Kaywinnet.h>          // WiFi credentials
char macBuffer[24];             // Holds the last three digits of the MAC, in hex.
char hostName[24];              // Holds nodeName + the last three bytes of the MAC address.





//--------------- MQTT declarations ---------------
#include "Kaywinnet.h"
#include <ESP8266WiFi.h>        // Connect (and reconnect) an ESP8266 to the a WiFi network.
#include <PubSubClient.h>       // connect to a MQTT broker and publish/subscribe messages in topics.
// Declare an object of class WiFiClient
// Declare an object of class PubSubClient, which receives as input of the constructor the previously defined WiFiClient.
WiFiClient xyzzy;
PubSubClient client(xyzzy);

// Make the MQTT topics
// Declare strings for the topics. Topics will be created in setup_mqtt().
char mqttMsg[24];               // Holds the incoming MQTT message
char statusTopic[20];
char cmndTopic[20];

const char *mqttServer = MQTT_SERVER;         // Local broker defined in Kaywinnet.h
const int mqttPort = 1883;



//--------------- ticker ---------------
//for LED status
#include <Ticker.h>
Ticker blueTicker;                       //Ticker object for the WiFi Connecting LED




// --------------- Global stuff ---------------
int eyesVal = 0;
const int EYES_MIN = 5;            //Eye will dim to this value in loop
const int EYES_MAX = 100;          //open() will bring eye back to this level.

const int FAN_MAX = 255;
const int FAN_MIN = 128;
const int FAN_OFF = 0;
