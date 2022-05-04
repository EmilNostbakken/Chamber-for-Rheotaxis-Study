#include <LiquidCrystal_I2C.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into pin 3 on the Arduino
#define ONE_WIRE_BUS 3

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int buttonPin1 = 4; // Starts pump flow
const int buttonPin2 = 6; // Stops pump flow
// Establish pins for motor driver
const int motor1pin1 = 2;
// Establish pin used for user to control pump speed
const int analogInPin = A0;
// Establish output pin of user's pump speed input
const int analogOutPin = 5;
// Initialize values from user input
int sensorValue;
int outputValue;
int voltpercent;
// Initialize button states
int buttonState1 = 0;
int buttonState2 = 0;
int lastButtonState1 = 0;
int lastButtonState2 = 0;

void setup() {

  //Start up the library
  sensors.begin();
  sensors.requestTemperatures(); //Send the command to get temperature readings

  pinMode(motor1pin1, OUTPUT);
  pinMode(analogOutPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  sensorValue = 0;
  outputValue = 0;
  voltpercent = 0;

  //Initializing lcd
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0, 0);
  lcd.print("Off");
  lcd.setCursor(6, 0);
  lcd.print(sensors.getTempCByIndex(0));
  lcd.setCursor(11, 0);
  lcd.print("C");
}

void loop() {
  sensorValue = analogRead(analogInPin); // Reads voltage from output of potentiometer
  outputValue = map(sensorValue, 0, 1023, 0, 255); // Maps range of potentiometer to range of possible motor speeds
  voltpercent = map(outputValue, 0, 255, 0, 100); // Maps range of speeds to a percentage value to be printed for user feedback
  //Controlling speed (0 = off and 255 = max speed):
  analogWrite(analogOutPin, outputValue); //ENA pin

  // Read the states of all the buttons
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  // Update the speed percent value displayed
  lcd.setCursor(6, 1);
  if (voltpercent == 100) {
    lcd.print(voltpercent);
    lcd.print("%");
  }
  else if (voltpercent < 100 && voltpercent >= 10) {
    lcd.print(" ");
    lcd.print(voltpercent);
    lcd.print("%");
  }
  else if (voltpercent < 10) {
    lcd.print("  ");
    lcd.print(voltpercent);
    lcd.print("%");
  }

  // The next if statements determine if each button has been pressed
  // button1: Sets motor1pin1 to high which starts pump flow
  if (buttonState1 != lastButtonState1) {
    if (buttonState1 == HIGH) {
      digitalWrite(motor1pin1, HIGH);
      // Displays pump state "On"
      lcd.setCursor(0, 0);
      lcd.print("On ");
    }
  }
  // button2: Sets motor1pin1 to low which turns pump off
  if (buttonState2 != lastButtonState2) {
    if (buttonState2 == HIGH) {
      digitalWrite(motor1pin1, LOW);
      // Displays pump state "Off"
      lcd.setCursor(0, 0);
      lcd.print("Off");
      sensors.requestTemperatures();
      lcd.setCursor(6, 0);
      lcd.print(sensors.getTempCByIndex(0));
      lcd.setCursor(11, 0);
      lcd.print("C");
    }
  }
  // Update button states
  lastButtonState1 = buttonState1;
  lastButtonState2 = buttonState2;

}
