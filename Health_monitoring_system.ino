#define BLYNK_TEMPLATE_ID "TMPLn73IUxxa"
#define BLYNK_DEVICE_NAME "health monitoring system"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
#define APP_DEBUG
#define USE_WROVER_BOARD
#include "BlynkEdgent.h"

#define AOUT_PIN 36
#define temp 34
float vref=3300;
float res=vref/4096;
void readparameters()
{
int value1 = analogRead(AOUT_PIN);
float value2 = analogRead(temp);
value2=(value2/2048.0)*3300;
value2=value2*0.1;


  Serial.print("Heartbeat value: ");
  Serial.println(value1);
  delay(500);
  Serial.print("temperature: ");
  Serial.println(value2);
  delay(500);
 
 
  Blynk.virtualWrite(V0, value1);
  Blynk.virtualWrite(V1, value2);
  delay(1000);
}

void setup()
{
  Serial.begin(9600);
  pinMode(temp,INPUT);
  pinMode(AOUT_PIN,INPUT);
  
  delay(100);

  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  readparameters();
  
}
