String ssid     = "Simulator Wifi";  // SSID to connect to
String password = ""; // Our virtual wifi has no password 
String host     = "api.thingspeak.com"; // Open Weather Map API
const int httpPort   = 80;
String url     = "/update?api_key=0W0SAYA6T9SNM0LU&field1=";
#include <LiquidCrystal.h>
LiquidCrystal lcd(3, 2, 9, 8, 7, 6);
int dc=A2;
int buzzer = 5;
int pot = 0;
const int TMP36_pin = A3;
int sensor = A1;
int sensorValue = 0;
int ldr = A4;
int ldrv = 0;
  int setupESP8266(void) {
  Serial.begin(115200);   
  Serial.println("AT");   
  delay(10);      
  if (!Serial.find("OK")) return 1;
  Serial.println("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
  delay(10);        // Wait a little for the ESP to respond
  if (!Serial.find("OK")) return 2;
  Serial.println("AT+CIPSTART=\"TCP\",\"" + host + "\"," + httpPort);
  delay(50);       
  if (!Serial.find("OK")) return 3;
  return 0;
}
void anydata(int percent_moisture,int v,int tempC,int sensorValue,int ldrv) {
  // Construct our HTTP call
String httpPacket = "GET " + url + String(percent_moisture) + "&field2=" + String(v) + "&field3=" + String(tempC) + "&field4=" + String(sensorValue) + "&field5=" + String(ldrv) + " HTTP/1.1\r\nHost: " + host + "\r\n\r\n";
  int length = httpPacket.length();
  Serial.print("AT+CIPSEND=");
  Serial.println(length);
  delay(10); // Wait a little for the ESP to respond if (!Serial.find(">")) return -1;
  // Send our http request
  Serial.print(httpPacket);
  delay(10); // Wait a little for the ESP to respond
  if (!Serial.find("SEND OK\r\n")) return;   
}
void setup() 
{
  setupESP8266();
  lcd.begin(16,2);
  pinMode(pot,INPUT);
  pinMode(dc,OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void loop()
{
  pot = analogRead(A5);  
  int percent_moisture = map(pot,0,1023,0,100);
  int v;
  int temp_adc_val;
  float tempC; 
  if(percent_moisture > 60)
  {    
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    analogWrite(dc,0); 
    v = 0;    
  }
  else if(percent_moisture <= 40)
  {
    digitalWrite(buzzer, HIGH);
    delay(1000);
    digitalWrite(buzzer, LOW);
    analogWrite(dc,255); 
    v = 255;   
  }
  else if(percent_moisture > 40 && percent_moisture <= 60 )
  {
  analogWrite(dc,128);
  v = 128; 
  }
  lcd.autoscroll();  
    lcd.setCursor(0,0);
    lcd.print("Moisture % : ");
    lcd.print(percent_moisture);
    delay(800);     
    lcd.print(" Motor Speed: ");
    lcd.print(v);
    delay(800);
    temp_adc_val = analogRead(TMP36_pin);
    tempC = (temp_adc_val * 4.88);
    tempC = (tempC/10);
    tempC = tempC-50;
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(tempC);
    lcd.print(" ");
    delay(800);
    sensorValue = analogRead(sensor);
    lcd.print("CO2 = ");
    lcd.print(analogRead(A0));
    lcd.print(" ");
    delay(800);
    ldrv = analogRead(ldr);
    lcd.print("LI: ");
    lcd.print(ldrv); 
    lcd.print(" ");
    delay(800);
  lcd.clear(); 
  lcd.noAutoscroll(); 
  anydata(percent_moisture, v, tempC, sensorValue, ldrv);  }
