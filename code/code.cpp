#include <Servo.h>
Servo panServo;
Servo tiltServo;
const int panPin = 9;
const int tiltPin = 10; 
void setup() {
 Serial.begin(9600);
 panServo.attach(panPin);
 tiltServo.attach(tiltPin);
 delay(3000);
 Serial.println("Enter X and Y values between -100 and 100 (e.g. '25 -30'):");
}
void loop() {
 static String inputString = "";
 while (Serial.available()) {
 char incomingChar = Serial.read();
 if (incomingChar == '\n') {
 inputString.trim(); // Clean input
 // Only process if there's content
 if (inputString.length() > 0) {
 int spaceIndex = inputString.indexOf(' ');
 if (spaceIndex > 0 && spaceIndex < inputString.length() - 1) {
 String xStr = inputString.substring(0, spaceIndex);
 String yStr = inputString.substring(spaceIndex + 1);
 float x = xStr.toFloat();
 float y = yStr.toFloat();
 // Check if values are valid numbers
 if (!isnan(x) && !isnan(y)) {
 // Clamp values
 x = constrain(x, -100, 100);
 y = constrain(y, -100, 100);
 float panAngle = mapFloat(x, -100, 100, 0, 180);
 float tiltAngle = mapFloat(y, -100, 100, 0, 180);
 panServo.write(panAngle);
 tiltServo.write(tiltAngle);
 Serial.print("x: "); Serial.print(x);
 Serial.print(" → Pan: "); Serial.println(panAngle);
 Serial.print("y: "); Serial.print(y);
 Serial.print(" → Tilt: "); Serial.println(tiltAngle);
 Serial.println("---------------------------");
 } else {
 Serial.println("Invalid number format. Try again (e.g. 30 -20).");
 }
 } else {
 Serial.println("Format error. Use: number space number (e.g. 10 -15)");
 }
 }
 inputString = ""; // Reset after each entry
 } else if (incomingChar != '\r') {
 inputString += incomingChar;
 }
 }
}
// Safe floating-point map
float mapFloat(float x, float in_min, float in_max, float out_min, float out_max) {
 return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;