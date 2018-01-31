#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80);

const int led = 13;

void handleRoot()
{
    digitalWrite(led, 1);
    server.send(200, "text/plain", "hello from esp8266!");
    digitalWrite(led, 0);
}

void handleNotFound()
{
    digitalWrite(led, 1);
    String message = "File Not Found\n\n";
    message += "URI: ";
    message += server.uri();
    message += "\nMethod: ";
    message += (server.method() == HTTP_GET) ? "GET" : "POST";
    message += "\nArguments: ";
    message += server.args();
    message += "\n";
    for (uint8_t i = 0; i < server.args(); i++)
    {
        message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
    }
    server.send(404, "text/plain", message);
    digitalWrite(led, 0);
}

void setup(void)
{
    pinMode(led, OUTPUT);
    digitalWrite(led, 0);
    Serial.begin(115200);
}

bool serverStarted = 0;
void loop(void)
{
    if (serverStarted)
        server.handleClient();
    else
        tryReadCredentials();
}

void tryReadCredentials()
{
    char inData[100];
    int inDataPos = 0;
    while (true)
    {
        if (Serial.available() > 0)
        {

            char rec = Serial.read();
            inData[inDataPos] = rec;

            if (rec == '\n')
            {
                char ssid[100];
                char pw[100];
                int i = 0;
                while (i < inDataPos)
                {
                    if (inData[i] == '+')
                        break;
                    ssid[i] = inData[i];
                    i++;
                }
                int j = 0;
                ssid[i++] = 0;
                while (i < inDataPos)
                {
                    pw[j] = inData[i];
                    i++;
                    j++;
                }
                pw[j] = 0;
                connectToWifi(ssid, pw);
                settupServer();
                break;
            }
            if (++inDataPos >= 100)
                inDataPos = 0;
        }
    }
}

void settupServer()
{
    if (MDNS.begin("esp8266"))
        Serial.println("MDNS responder started");
    else
        Serial.println("Could not start MDNS responder");

    server.on("/", handleRoot);

    server.on("/inline", []() {
        server.send(200, "text/plain", "this works as well");
    });

    server.onNotFound(handleNotFound);

    server.begin();
    Serial.println("HTTP server started");
    serverStarted = true;
}

void connectToWifi(char *ssid, char *password)
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.println("");

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}