#include <DS3231.h>
#include <SD.h> 

File File1;
DS3231  rtc(SDA, SCL);
 
void setup() { 
  Serial.begin(9600);
  Serial.println("Initializing the SD Card...");
 
  if (!SD.begin()) {    
    Serial.println("Initialization Failed!");    
    return;  
    }  
  Serial.println("Initialization Complete.\n");     
  // Set the clock to run-mode  
  rtc.begin();
  rtc.setDOW(MONDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(10, 50, 0);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(19, 11, 2018);   // Day, Month, Year
  SD.remove("TEMPLOG.txt");   
  }
 
void loop() {    
  File1 = SD.open("TEMPLOG.txt", FILE_WRITE);
  Serial.println("File Opened.");    
  if (File1) {
    Serial.print("Real Time Clock  ");
    Serial.print("Time: ");
    Serial.println(rtc.getTimeStr());
    File1.print("Real Time Clock  ");
    File1.print("Time: ");
    File1.println(rtc.getTimeStr());
    delay(3000);
    Serial.print("Date: ");
    Serial.println(rtc.getDateStr());
    File1.print("Date: ");
    File1.println(rtc.getDateStr());
    delay(3000);
    Serial.print("Day: ");
    Serial.print(rtc.getDOWStr());
    Serial.print("           ");
    File1.print("Day: ");
    File1.print(rtc.getDOWStr());
    File1.print("           ");
    delay(3000);
    Serial.print("Temp: ");
    Serial.print(rtc.getTemp());
    Serial.print(" C");
    Serial.print("          ");
    File1.print("Temp: ");
    File1.print(rtc.getTemp());
    File1.print(" C");
    File1.print("          ");
    delay(3000);
    }
  File1.close();    
  Serial.println("File Closed.\n");    
  Serial.println("Safe to disconnect card");    
  delay(10000);    
  Serial.println("Card in use, do not disconnect!!");   
}
 
