#include <Arduino.h>
const byte green_Led = 12;
const byte ir_Led=10;
const byte SENSOR_RED = A1;
int sensor;
int sensor_infra;
uint16_t datos[2];


//Time and cases 
enum led{red, ir};
uint16_t led_on_time=10;
unsigned long time; 
byte state;
String mensaje;


void setup() {
Serial.begin(9600);
  //SetUp PINES
pinMode(SENSOR_RED, INPUT);
  //pinMode(sensor_infra,INPUT);
pinMode(green_Led, OUTPUT);
pinMode(ir_Led,OUTPUT);

time=millis();
state = red; 
}



void loop() {
if (millis() - time>= led_on_time)
{
  time=millis();
  switch (state)
  {
  case red:
    digitalWrite(green_Led,HIGH);
    digitalWrite(ir_Led,LOW);
    delay(100);
    sensor=analogRead(SENSOR_RED);
    state=ir;
    Serial.println(sensor);
    break;

  case ir:
    digitalWrite(green_Led,LOW);
    digitalWrite(ir_Led,HIGH);
    delay(100);
    sensor_infra=analogRead(SENSOR_RED);
    state=red;
    mensaje=sensor;
    mensaje += ",";
    mensaje += sensor_infra;
    Serial.println(mensaje);
    
    break;
  }
}
}
