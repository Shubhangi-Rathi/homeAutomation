// Author: Shubhangi Rathi
//Aim: Home Automation using Blynk and Google Assistant
/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial
#define LED0 4        //D2 pin
#define PUMP 5        //D1 pin
#define FAN 12        //D6 pin
#define DELAY 1000

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
//Or you will also find it in the mail recieved from Blynk on creation of the project
char auth[] = "AuthorisationToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "NetwokName";
char pass[] = "Password";

//all the hardware variables
Servo myservo;

//This function will be called when button set to virtualPin V0 is tapped.
BLYNK_WRITE(V0)
 {
  Serial.println(param.asInt());
   if(param.asInt()==1)           //param.asInt() returns value of button after tapping. OFF-0 and ON-1
    {
       digitalWrite(LED0, HIGH);
    }
    else
    {
       digitalWrite(LED0, LOW);
    }
 }

 //This function will be called when button set to virtualPin V1 is tapped.
 BLYNK_WRITE(V1)
 {
  int val = param.asInt();      //val = value of button after tapping. OFF-0 and ON-1
  Serial.print("Val");
  Serial.println(val);
   if(val==1)
    {
       myservo.write(90);
    }
    else
    {
       myservo.write(0);
    }
 }

//This function will be called when button set to virtualPin V2 is tapped.
 BLYNK_WRITE(V2)
 {
  int val = param.asInt();
   if(val==1)
    {
       digitalWrite(PUMP, HIGH);
    }
    else
    {
       digitalWrite(PUMP, LOW);
    }
 }

 //This function will be called when button set to virtualPin V3 is tapped.
 BLYNK_WRITE(V3)
 {
  int val = param.asInt();
   if(val==1)
    {
       digitalWrite(FAN, HIGH);
    }
    else
    {
       digitalWrite(FAN, LOW);
    }
 }

 
void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  
  pinMode(LED0, OUTPUT);
  pinMode(PUMP, OUTPUT);
  pinMode(FAN, OUTPUT);
  digitalWrite(LED0, LOW);
  digitalWrite(PUMP, LOW);
  digitalWrite(FAN, LOW);
  myservo.attach(2);          //attach servo to D4 pin
  myservo.write(0);           //Set the initialising angle
}

void loop()
{
  Blynk.run();               //Set connection to Blynk app and manages all functions thereafter.
}
