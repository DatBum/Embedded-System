#include "DHT.h"

#define LED_PIN 13
 
#define CMD_SEND_BEGIN  "AT+CIPSEND=0"
#define CMD_SEND_END    "AT+CIPCLOSE=0"
 
#define PROTOCOL_HTTP     80
#define PROTOCOL_HTTPS    443
#define PROTOCOL_FTP      21
#define PROTOCOL_CURRENT  PROTOCOL_HTTP
 
#define CHAR_CR     0x0D
#define CHAR_LF     0x0A
 
#define STRING_EMPTY  ""
 
#define DELAY_SEED  1000
#define DELAY_1X    (1*DELAY_SEED)
#define DELAY_2X    (2*DELAY_SEED)
#define DELAY_3X    (3*DELAY_SEED)
#define DELAY_4X    (4*DELAY_SEED)
#define DELAY_5X    (5*DELAY_SEED)
 
bool hasRequest = false;
const int DHTPIN = 2;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);
 
void setup()
{
  delay(DELAY_5X);
  Serial.begin(115200);
  dht.begin();
  
  pinMode(LED_PIN, OUTPUT); 
  digitalWrite(LED_PIN, LOW);
  
  initESP8266();
}
 
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  while(Serial.available())
  {   
    bufferingRequest(Serial.read());
  }
  
  if(hasRequest == true) 
  {
    String htmlResponse = "<!doctype html>"
    "<html>"
      "<head>"
        "<title>ESP8266 DEMO</title>"
      "</head>"
      "<body>"
        "<h1>ESP8266 DEMO</h1>"
        "<h2>Temperature: </h2>"
        "<p>" + String(t) + "&#8451" + "</p>"
        "<h2>Humidity: </h2>"
        "<p>" + String(h) + "%" + "</p>"
        "<form action='' method='GET'>"
          "<input type='radio' name='LED' name='TURN' value='TURN_ON' /> LED ON<br/>"
          "<input type='radio' name='LED' name='TURN' value='TURN_OFF' /> LED OFF<br/>"
          "<input type='submit' value='Submit' />"
        "</form>"
      "</body>"
     "</html>";
    
    String beginSendCmd = String(CMD_SEND_BEGIN) + "," + htmlResponse.length();
    deliverMessage(beginSendCmd, DELAY_1X);
    deliverMessage(htmlResponse, DELAY_1X);
    deliverMessage(CMD_SEND_END, DELAY_1X);
    hasRequest = false;
  }
}
 
void initESP8266()
{
  deliverMessage("AT+RST", DELAY_2X);
  deliverMessage("AT+CWMODE=2", DELAY_3X);
  deliverMessage("AT+CWSAP=\"DATDEPTRAI\",\"123456789\",1,4", DELAY_3X);
  deliverMessage("AT+CIFSR", DELAY_1X);
  deliverMessage("AT+CIPMUX=1", DELAY_1X); // để cho phép các kết nối TCP
  deliverMessage(String("AT+CIPSERVER=1,") + PROTOCOL_CURRENT, DELAY_1X);  //để tạo 1 TCP server
}
 
void bufferingRequest(char c)
{
  static String bufferData = STRING_EMPTY;
 
  switch (c)
  {
    case CHAR_CR:
      break;
    case CHAR_LF:
    {
      Procedure(bufferData);
      bufferData = STRING_EMPTY;
    }
      break;
    default:
      bufferData += c;
  }
} 
 
void Procedure(const String& command)
{ 
  hasRequest = command.startsWith("+IPD,");
  
  if(command.indexOf("TURN_OFF") != -1)
  { 
    digitalWrite(LED_PIN, LOW);
  }
  else if(command.indexOf("TURN_ON") != -1)
  { 
    digitalWrite(LED_PIN, HIGH);
  }
}
 
void deliverMessage(const String& msg, int dt)
{
  Serial.println(msg);
  delay(dt);

}
