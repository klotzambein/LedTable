#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

ESP8266WebServer server(80);

const int led = 13;

char cmdBuf[4];
byte cmd = 0;
char dataBuf[128];
byte dataBufPos = 0;
bool readingData = false;
unsigned long cmdState = 0;

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

void connectToWifi(const char *ssid, const char *password)
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

void parseCommand()
{
    while (!cmd && Serial.available())
    {
        char c = Serial.read();
        if (c == '?')
        {
            if (memcmp(cmdBuf, 'HNDL'))
                cmd = 1;
            else if (memcmp(cmdBuf, 'WIFI'))
                cmd = 2;
            else if (memcmp(cmdBuf, 'MYIP'))
                cmd = 3;
        }
        else if (c == ';')
        {
            if (memcmp(cmdBuf, 'PING'))
                cmd = 4;
        }
        else if (c == ':')
        {
            if (memcmp(cmdBuf, 'CNTI'))
                cmd = 5;
            else if (memcmp(cmdBuf, 'WIFI'))
                cmd = 6;

            readingData = true;
            dataBufPos = 0;
        }
        cmdBuf[0] = cmdBuf[1];
        cmdBuf[1] = cmdBuf[2];
        cmdBuf[2] = cmdBuf[3];
        cmdBuf[4] = c;
    }
}

void parseData()
{
    while (readingData && Serial.available())
    {
        char c = Serial.read();
        if (c == ';')
        {
            readingData = false;
            return;
        }
        dataBuf[dataBufPos++] = c;
        if (dataBufPos >= 128)
            dataBufPos = 0;
    }
}

void execCommand()
{
    if (cmd && !readingData)
    {
        switch (cmd)
        {
        case 1: //HNDL?
            Serial.println("ER:not implemented;");
            cmd = 0;
            break;
        case 2: //WIFI?
            Serial.print("OK:");
            Serial.write(WiFi.status() == WL_CONNECTED ? '1' : '0');
            Serial.println(";");
            cmd = 0;
            break;
        case 3: //MYIP?
            Serial.print("OK:");
            Serial.println(WiFi.localIP(););
            Serial.println(";");
            cmd = 0;
            break;
        case 4: //PING;
            Serial.println("OK;");
            cmd = 0;
            break;
        case 5: //CNTI:
            Serial.println("ER:not implemented;");
            cmd = 0;
            break;
        case 6: //WIFI:
            if (cmdState == 0)
            {
                int i = 0;
                for (; i < dataBufPos; i++)
                    if (dataBuf[i] == '+')
                    {
                        dataBuf[i++] = 0;
                        break;
                    }
                if (i == dataBufPos || dataBufPos = 128)
                {
                    Serial.println("ER:malformed data;");
                    cmd = 0;
                    return;
                }
                WiFi.mode(WIFI_STA);
                WiFi.begin(ssid, password);
                cmdState = millis();
            }
            else
            {
                if (WiFi.status() == WL_CONNECTED)
                {
                    cmd = 0;
                    cmdState = 0;
                    Serial.println("OK;");
                }
                else if (millis() - cmdState > 10000)
                {
                    Serial.println("ER:timeout;");
                }
            }
            break;
        }
    }
}