// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings

#define BLYNK_TEMPLATE_ID "TMPL6R5IGlTiS"
#define BLYNK_TEMPLATE_NAME "WORKSHOP"
#define BLYNK_AUTH_TOKEN "7f7fgKYR6GIBxWXcy3BAw10CSWH052nP"
#define LINE_TOKEN "pJdiapCQPEKwZdzjSXtstBlAngzGhP60ty5dPyDiR0K"
#define DHTPIN D4 
#define DHTTYPE    DHT11  
// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial
#define relay D2
#define soil A0

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TridentTD_LineNotify.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

char auth[] = BLYNK_AUTH_TOKEN;
// Your WiFi credentials.
// Set password to "" for open networks.
//char ssid[] = "BTL3_2.4G";
//char pass[] = "BTL0816710296";
char ssid[] = "eva";
char pass[] = "0885776972";
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
int toggle=0;//For Auto Mode on/off
float Soil_auto = 0;
boolean flag = true;
int pinValue1 = 0;
void setup()
{
  // Debug console
  pinMode(relay,OUTPUT);
  pinMode(soil,INPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
    dht.begin();
  Serial.begin(115200); Serial.println();
  Serial.println(LINE.getVersion());
  
  WiFi.begin(ssid, pass);
  Serial.printf("WIFI Connecting to %s\n", ssid);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print("."); delay(400);}
    Serial.printf("\nWiFi Connected\nIP : ");
    Serial.println(WiFi.localIP());
    LINE.setToken(LINE_TOKEN);
 }
  // Setup a function to be called every second
  //timer.setInterval(100L, myTimerEvent);

BLYNK_WRITE(V3)
{
  Soil_auto = param.asInt(); //กำหนดค่าความชื้นในดินจากBlynk
}
 
BLYNK_WRITE(V4)
{
  int pinValue1 = param.asInt(); // assigning incoming value from pin V4 to a variable
  if(pinValue1==1){
  digitalWrite(relay,0);//Pump On
  LINE.notify("PUMP IS NOW RUNNING");
} else {
  digitalWrite(relay,1);//Pump Off
  LINE.notify("PUMP IS NOW STOP!!");
}
}
BLYNK_WRITE(V5)
{
  int pinValue2 = param.asInt(); // assigning incoming value from pin V5 to a variable
  if(pinValue2==1){toggle=1;}
  if(pinValue2==0){
  toggle=0;
  }
}
void loop()
{
  delay(1000);
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  int moisture = analogRead(soil); //Dry=1, wet=0
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature();
  float LevelSoil = (moisture * (100.0 / 1024.0))-100;
  float LevelSoil1 = LevelSoil*(-1);
  Serial.print("soil = ");
  Serial.println(LevelSoil1);
  Blynk.virtualWrite(V0, LevelSoil1);
  if (LevelSoil1 > 80) {
    LINE.notify("Humidity in Soil > 80%!!");
  }
  if (toggle==1){
    if (LevelSoil1 < Soil_auto && LevelSoil1 < 80 || LevelSoil1 < 40 ) {
      digitalWrite(relay,0);
      Blynk.virtualWrite (V4,1);
        while (flag == true) {
          LINE.notify("PUMP NOW RUNNING");
          delay(1000);
          flag = false;
        }
    }else {
      digitalWrite(relay,1);
      Blynk.virtualWrite (V4,0);
        while (flag == false) {
          LINE.notify("PUMP NOW STOP");
          delay(1000);
          flag = true;
        }
    }
  }
}
