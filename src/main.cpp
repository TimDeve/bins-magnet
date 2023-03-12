#include <M5CoreInk.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#include "secrets.h"

const char *networkName = NETWORK_NAME;
const char *networkPswd = NETWORK_PASS;

const char *cert = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDrzCCApegAwIBAgIQCDvgVpBCRrGhdWrJWZHHSjANBgkqhkiG9w0BAQUFADBh
MQswCQYDVQQGEwJVUzEVMBMGA1UEChMMRGlnaUNlcnQgSW5jMRkwFwYDVQQLExB3
d3cuZGlnaWNlcnQuY29tMSAwHgYDVQQDExdEaWdpQ2VydCBHbG9iYWwgUm9vdCBD
QTAeFw0wNjExMTAwMDAwMDBaFw0zMTExMTAwMDAwMDBaMGExCzAJBgNVBAYTAlVT
MRUwEwYDVQQKEwxEaWdpQ2VydCBJbmMxGTAXBgNVBAsTEHd3dy5kaWdpY2VydC5j
b20xIDAeBgNVBAMTF0RpZ2lDZXJ0IEdsb2JhbCBSb290IENBMIIBIjANBgkqhkiG
9w0BAQEFAAOCAQ8AMIIBCgKCAQEA4jvhEXLeqKTTo1eqUKKPC3eQyaKl7hLOllsB
CSDMAZOnTjC3U/dDxGkAV53ijSLdhwZAAIEJzs4bg7/fzTtxRuLWZscFs3YnFo97
nh6Vfe63SKMI2tavegw5BmV/Sl0fvBf4q77uKNd0f3p4mVmFaG5cIzJLv07A6Fpt
43C/dxC//AH2hdmoRBBYMql1GNXRor5H4idq9Joz+EkIYIvUX7Q6hL+hqkpMfT7P
T19sdl6gSzeRntwi5m3OFBqOasv+zbMUZBfHWymeMr/y7vrTC0LUq7dBMtoM1O/4
gdW7jVg/tRvoSSiicNoxBN33shbyTApOB6jtSj1etX+jkMOvJwIDAQABo2MwYTAO
BgNVHQ8BAf8EBAMCAYYwDwYDVR0TAQH/BAUwAwEB/zAdBgNVHQ4EFgQUA95QNVbR
TLtm8KPiGxvDl7I90VUwHwYDVR0jBBgwFoAUA95QNVbRTLtm8KPiGxvDl7I90VUw
DQYJKoZIhvcNAQEFBQADggEBAMucN6pIExIK+t1EnE9SsPTfrgT1eXkIoyQY/Esr
hMAtudXH/vTBH1jLuG2cenTnmCmrEbXjcKChzUyImZOMkXDiqw8cvpOp/2PV5Adg
06O/nVsJ8dWO41P0jmP6P6fbtGbfYmbW0W5BjfIttep3Sp+dWOIrWcBAI+0tKIJF
PnlUkiaY4IBIqDfv8NZ5YBberOgOzW6sRBc4L0na4UU+Krk2U886UAb3LujEV0ls
YSEY1QSteDwsOoBrp+uvFRTp2InBuThs4pFsiv9kuXclVzDAGySj4dzp30d8tbQk
CAUw7C29C79Fv1C5qfPrmAESrciIxpg0X40KPMbp1ZWVbd4=
-----END CERTIFICATE-----
)EOF";

Ink_Sprite InkPageSprite(&M5.M5Ink);

// void setClock()
// {
//   configTime(3 * 3600, 0, "pool.ntp.org", "time.nist.gov");
//   Serial.print("Waiting for NTP time sync: ");
//   time_t now = time(nullptr);
//   while (now < 8 * 3600 * 2)
//   {
//     delay(500);
//     Serial.print(".");
//     now = time(nullptr);
//   }
//   Serial.println("");
//   struct tm timeinfo;
//   gmtime_r(&now, &timeinfo);
//   Serial.print("Current time: ");
//   Serial.print(asctime(&timeinfo));
// }

uint64_t secondToMicroSeconds(int seconds) {
  return seconds * 1000000;
}

void printJson(String input)
{
  StaticJsonDocument<768> doc;

  DeserializationError error = deserializeJson(doc, input);

  if (error)
  {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }
  InkPageSprite.clear();
  InkPageSprite.drawString(0, 0, "Bins collection dates");

  for (JsonObject Results_Refuse_collection_date : doc["Results"]["Refuse_collection_dates"].as<JsonArray>())
  {
    const char *typeOfRefuse = Results_Refuse_collection_date["_"];
    if (strstr(typeOfRefuse, "Recycling")) {
      InkPageSprite.drawString(0, 30, "Recycling");
      const char *Results_Refuse_collection_date_Next_Collection = Results_Refuse_collection_date["Next_Collection"];
      Serial.println(Results_Refuse_collection_date_Next_Collection);
      InkPageSprite.drawString(0, 50, Results_Refuse_collection_date_Next_Collection);
      // const char *Results_Refuse_collection_date_Last_Collection = Results_Refuse_collection_date["Last_Collection"];
      // InkPageSprite.drawString(0, 70, Results_Refuse_collection_date_Last_Collection);
      // Serial.println(Results_Refuse_collection_date_Last_Collection);
    } else if (strstr(typeOfRefuse, "General Waste")){
      InkPageSprite.drawString(0, 100, "Refuse");
      const char *Results_Refuse_collection_date_Next_Collection = Results_Refuse_collection_date["Next_Collection"];
      Serial.println(Results_Refuse_collection_date_Next_Collection);
      InkPageSprite.drawString(0, 120, Results_Refuse_collection_date_Next_Collection);
      // const char *Results_Refuse_collection_date_Last_Collection = Results_Refuse_collection_date["Last_Collection"];
      // InkPageSprite.drawString(0, 140, Results_Refuse_collection_date_Last_Collection);
    }

  }
  M5.M5Ink.clear();
  InkPageSprite.pushSprite();
}

void setup()
{
  M5.begin();
  if (!M5.M5Ink.isInit())
  {
    Serial.printf("Init failed");
  }
  // M5.M5Ink.clear();
  if (InkPageSprite.creatSprite(0, 0, 200, 200, true) != 0)
  {
    Serial.printf("Ink sprite failed");
  }

  WiFi.begin(networkName, networkPswd);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Waiting for wifi...");
    delay(500);
  }

  // setClock();

  Serial.println("Attempting server connection.");
  HTTPClient http;
  http.begin("https://my.haringey.gov.uk/getdata.aspx?RequestType=LocalInfo&ms=mapsources/MyHouse&format=JSON&group=Property%20details|Refuse%20collection%20dates&uid=100021178531", cert);
  http.setReuse(false);
  // http.addHeader("Content-Length", "0");
  Serial.println("Sending GET request.");
  int httpCode = http.GET();
  if (httpCode > 0)
  {
    Serial.println("Server reached and responded to GET request.");
    Serial.println(httpCode);
    if (httpCode == HTTP_CODE_OK)
    {
      Serial.print("Server responded with requested payload: ");
      auto payload = http.getString();
      printJson(payload);
      http.end();
    }
    else
    {
      Serial.println("Server error: Server did not provide the requested payload.");
    }
  }
  else
  {
    Serial.println("Server could not be reached or server did not reply to GET request.");
  }
  http.end();

  Serial.println("Sleeping...");
  M5.shutdown(60 * 60 * 24);
}

void loop() {}
