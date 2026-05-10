/************************************************************
   IoT BASED SMART WEATHER MONITORING SYSTEM
   ESP8266 + DHT11 + Rain Sensor + LDR + I2C LCD + Blynk
************************************************************/

//================ BLYNK =================
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Weather Monitoring"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

//================ LIBRARIES =================
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

//================ WIFI =================
char ssid[] = "its_rohit";
char pass[] = "0909090909";

//================ PINS =================
#define DHTPIN D4
#define DHTTYPE DHT11

#define RAINPIN D5
#define LDRPIN A0

//================ OBJECTS =================
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

BlynkTimer timer;

//================================================
// SEND SENSOR DATA
//================================================
void sendSensor()
{
  // Read Sensors
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int rain = digitalRead(RAINPIN);
  int lightVal = analogRead(LDRPIN);

  // Rain Status
  String rainMsg;

  if (rain == LOW)
  {
    rainMsg = "RAINING";
  }
  else
  {
    rainMsg = "CLEAR";
  }

  //================================================
  // SERIAL MONITOR
  //================================================
  Serial.println("===== WEATHER DATA =====");

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.print("Rain Status: ");
  Serial.println(rainMsg);

  Serial.print("Light Value: ");
  Serial.println(lightVal);

  Serial.println("========================");

  //================================================
  // LCD DISPLAY
  //================================================
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("T:");
  lcd.print(temperature);
  lcd.print("C ");

  lcd.print("H:");
  lcd.print(humidity);

  lcd.setCursor(0, 1);
  lcd.print(rainMsg);

  lcd.print(" L:");
  lcd.print(lightVal);

  //================================================
  // BLYNK OUTPUT
  //================================================
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V2, rainMsg);
  Blynk.virtualWrite(V3, lightVal);
}

//================================================
// SETUP
//================================================
void setup()
{
  Serial.begin(9600);

  // Rain Sensor
  pinMode(RAINPIN, INPUT);

  // LCD START
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("SMART WEATHER");

  lcd.setCursor(0, 1);
  lcd.print("MONITORING");

  delay(3000);
  lcd.clear();

  // DHT START
  dht.begin();

  //================================================
  // WIFI + BLYNK
  //================================================
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  //================================================
  // TIMER
  //================================================
  timer.setInterval(2000L, sendSensor);
}

//================================================
// LOOP
//================================================
void loop()
{
  Blynk.run();
  timer.run();
}void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
