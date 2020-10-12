//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h> 
#include <ESP8266WiFi.h>
#include<WiFiClient.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>

// Set these to run example.
#define FIREBASE_HOST "ai-based-gas-leak-detection.firebaseio.com"
#define FIREBASE_AUTH "UJzkGIRrdAiklQqJU7x7J6FHMtX25i2F24AH1gdG"
#define WIFI_SSID "Polash"
#define WIFI_PASSWORD "10004001"
const int gasPin=A0;
void setup() {
  Serial.begin(9600);
  pinMode (gasPin,INPUT);
 
  

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int data[5],load[6];
String Data[5];
void loop() {
  int i=0,j=0;

  for(i=0;i<5;i++)
  {
    data[i]=analogRead(gasPin);
    Data[i]=String(data[i]);
    delay(1000);
  }
  Serial.println(Data[0]);
  Serial.println(Data[1]);
  Serial.println(Data[2]);
  Serial.println(Data[3]);
  Serial.println(Data[4]);

  HTTPClient http;   
 
  String getData, Link;
   
  
 
  //GET Data
  getData = "?data0=" + Data[0] + "&data1=" + Data[1] + "&data2=" + Data[2] +"&data3=" + Data[3] +"&data4=" + Data[4] ;  
  Link = "http://5c454f2b.ngrok.io/cnproj/index.php" + getData; //need to be changed when using  new ngrok session 
  Serial.println(Link);
  
  http.begin(Link);     
  
  int httpCode = http.GET();            
  String payload = http.getString();    //Get the response payload
 
  
  Serial.println(payload);   
  http.end();  

  int severity;
  severity=int(payload[0])-48;  //means 0th data er severity
  Serial.println(severity);

  //sending notifications depends on payload[5] value,if 2 send high,if 1 send mid, if 0 send low(kisu kora lagbe na ashole 0 hoile)




  //sending notification code ends here
 
 
  // uploading datas to the firebase
 String name1,name2;
  for(j=0;j<5;j++)
  {
  String name1 = Firebase.pushInt("PPM", data[j]);
  load[j]=int(payload[j])-48;
  String name2 = Firebase.pushInt("Severity", load[j]);
  }
  
  // handle error
  if (Firebase.failed()) {
      Serial.print("pushing /logs failed:");
      Serial.println(Firebase.error());  
      return;
  }
  Serial.print("pushed: /logs/");
  Serial.println(name1);
  Serial.println(name2);
  delay(1000);
}
