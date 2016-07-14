/*
 * Grove Temperature Sensor
 * reference: http://www.seeedstudio.com/wiki/Grove_-_Starter_Kit_Plus
*/

int a; // raw output of A0
int B = 3975; // B value of thermistor
float celcius; // temperature value accuracy: (+/-)1.5*C
float resistance; // resistance of thermistor

void setup() {
  Serial.begin(9600); // initialize serial
}

void loop() {
  // Grove temperature sensor uses a thermistor to determine 
  // the ambient temperature with detection range between -40 to 125 degree
  // Celcius (accuracy: [+/-] 1.5*C). To get temperature value, read raw 
  // output of A0 pin and calculate temperature value based on built-in 
  // function (Steinhart-Hart equation) given. 
  a = analogRead(0); 

  resistance = (float)(1023 - a) * 10000 / a;
  celcius = 1 / (log(resistance/10000)/B + 1/298.15) - 273.15;

  delay(1000); 
  Serial.println(celcius); 
}
