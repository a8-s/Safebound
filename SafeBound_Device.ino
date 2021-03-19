#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


#include <ESP8266WiFiMulti.h>
#include <WiFiClient.h>

const char* ssid = "";
const char* password = "";
int pin_stat=0; 
bool entrance_trigger= false; 
ESP8266WiFiMulti WiFiMulti;
int httpCode=0;

 
 
void setup () {
 
  Serial.begin(9600);
 
  WiFi.begin(ssid, password);  
  
 
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print("Connecting..");

   // pinMode(3, INPUT_PULLUP);
 
  }

  Serial.println("connected");
 
}
 




void Query(int deviceID){
  
  
    if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    if (http.begin(client, "get_url")) 


      Serial.print("[HTTP] GET...\n");
     
      httpCode = http.GET();
    }

    Serial.println(httpCode);  
    //http.end();  
  
  

  }




void EventLogger(){
  
  
    if ((WiFi.status() == WL_CONNECTED)) {

    WiFiClient client;

    HTTPClient http;

    Serial.print("[HTTP] begin...\n");
    (http.begin(client, "post_url")); 
    http.addHeader("Content-Type", "application/json"); 
    httpCode = http.POST("{\"TimeStamp\":\"test_timestamp1\"}");

    Serial.print("[HTTP] POST...\n");
     
     
    

    Serial.println(httpCode);  
    http.end();
  
  

  }
}



void loop() {


  
  if (pin_stat == HIGH){
    
    entrance_trigger=true;
    EventLogger();
    }

   Serial.println(entrance_trigger);
   delay(30000);    //Send a request every 30 seconds 

    
 
  }
 
