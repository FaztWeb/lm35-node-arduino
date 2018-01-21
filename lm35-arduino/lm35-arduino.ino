#define TEMP_SENSOR 0
#define LED_RED 12
#define LED_GREEN 13

void setup() {
  Serial.begin(9600);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
}

int signalVoltage, celsiusTemp;

void loop() {
  // analog Signal 0 to 1023
  signalVoltage = analogRead(TEMP_SENSOR);
  
   // Convert to celsius Temperature
  celsiusTemp = (5 * signalVoltage * 100) / 1024;

  // Print in the serial Monitor
  Serial.println(celsiusTemp);
  
  // Turn On/Off the LED If is greather than 22°C
  if(celsiusTemp > 22) {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);    
  } else {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
  }
  
  delay(500); // we read signal every 500ms
}
