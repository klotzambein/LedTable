#include "wifi.h"

#include "WiFiEsp.h"

bool wifi_available = false;
bool wifi_connected = false;
IPAddress wifi_ip;

WiFiEspServer server(80);

void wifiConnect(char *ssid, char *pass);
void disconnect();

void wifi_init(char *ssid, char *pass)
{
    Serial1.begin(115200);
    // initialize ESP module
    WiFi.init(&Serial1);

    // check for the presence of the shield
    if (WiFi.status() == WL_NO_SHIELD)
    {
        LOG("WiFi not available.")
        return;
    }
    wifi_available = true;

    wifiConnect(ssid, pass);
}

void wifiConnect(char *ssid, char *pass)
{
    if (!wifi_available)
        return;
    if (wifi_connected)
        disconnect();

    // attempt to connect to WiFi network
    for (int i = 0;; i++)
    {
        if (i >= 3)
            return;

        LOG("Attempting to connect to WPA SSID: ")
        LOG(ssid)
        if (i != 0)
        {
            LOG("Try: ")
            LOG(i + 1)
        }
        // Connect to WPA/WPA2 network
        if (WiFi.begin(ssid, pass) == WL_CONNECTED)
            break;
    }

    wifi_ip = WiFi.localIP();

    wifi_connected = true;

    server.begin();
}

void disconnect()
{
    WiFi.disconnect();

    wifi_connected = false;
}