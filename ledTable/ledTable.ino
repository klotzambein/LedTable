/*
 WiFiEsp example: WebServer

 A simple web server that shows the value of the analog input 
 pins via a web page using an ESP8266 module.
 This sketch will print the IP address of your ESP8266 module (once connected)
 to the Serial monitor. From there, you can open that address in a web browser
 to display the web page.
 The web page will be automatically refreshed each 20 seconds.

 For more details see: http://yaab-arduino.blogspot.com/p/wifiesp.html
*/

//char ssid[] = "ssid";
//char pass[] = "password";
#include "private.h"

void setup()
{
#ifdef DEBUG_ENABLED
#endif
    Serial.begin(115200);
    //Serial.println("writing:");
    Serial1.begin(76800, SERIAL_8N1);
    //Serial1.print("AT+CIOBAUD=9600\r\n");
}

void loop()
{
    stateMachine();
}*/
