2 wire code: 
float temperature;
const int fan_control_pin = 3;
void setup() {
pinMode(fan_control_pin, OUTPUT);
digitalWrite(fan_control_pin, LOW);
}
void loop() {
temperature = float(analogRead(A0)) * 500.0 / 1024.0;
if (temperature > 100.0) digitalWrite(fan_control_pin, HIGH);
else digitalWrite(fan_control_pin, LOW);
delay(1000);
}
3 wire fan:
int count = 0;
unsigned long start_time;
int rpm;
void setup() {
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(2), counter, RISING);
}
void loop() {
start_time = millis();
count = 0;
while((millis() - start_time) < 1000){
}
rpm = count * 60 / 2;
Serial.print(rpm);
Serial.println(" rpm");
}
void counter() {
count++;
}
4 wire fan:
float temperature;
const int fan_control_pin = 3;
int count = 0;
unsigned long start_time;
int rpm;
void setup() {
pinMode(fan_control_pin, OUTPUT);
analogWrite(fan_control_pin, 0);
Serial.begin(9600);
attachInterrupt(digitalPinToInterrupt(2), counter, RISING);
}
void loop() {
temperature = float(analogRead(A0)) * 500.0 / 1024.0;
if (temperature < 100.0) analogWrite(fan_control_pin, 0);
if ((temperature >= 100.0) && (temperature < 120.0)) analogWrite(fan_control_pin, 126);
if (temperature >= 120.0) analogWrite(fan_control_pin, 255);
start_time = millis();
count = 0;
while((millis() - start_time) < 1000){
}
rpm = count * 60 / 2;
Serial.print("The temperature is ");
Serial.print(temperature);
Serial.print((char)176);
Serial.println("F");
Serial.print("The fan speed is ");
Serial.print(rpm);
Serial.println(" rpm");
}
void counter() {
count++;
}