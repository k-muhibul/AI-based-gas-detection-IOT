 //Arduino code
#include <SoftwareSerial.h>
SoftwareSerial s(5,6);
 
void setup() {
s.begin(9600);
}
 
void loop() {
int data=50;
Serial.println(data);
if(s.available()>0)
{
 s.write(data);
}
}
