#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// Replace with your Wi-Fi credentials
const char* ssid = "SSID";
const char* password = "PASSWORD";

const char* swpcApiUrl = "https://services.swpc.noaa.gov/json/planetary_k_index_1m.json";

const int ledPin = 2; // GPIO pin for the built-in LED
const int kIndexThreshold = 5; // Minimum K-index for Aurora Borealis visibility (you can adjust this value)

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  WiFi.begin(ssid, password);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected!");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(swpcApiUrl);
    int httpCode = http.GET();

    if (httpCode > 0) {
      String payload = http.getString();
      DynamicJsonDocument doc(1024);
      deserializeJson(doc, payload);

      float kIndex = doc[0]["kp"];

      Serial.print("K-index: ");
      Serial.println(kIndex);

      if (kIndex >= kIndexThreshold) {
        Serial.println("Aurora Borealis detected, LED will blink.");
        for (int i = 0; i < 5; i++) {
          digitalWrite(ledPin, HIGH);
          delay(500);
          digitalWrite(ledPin, LOW);
          delay(500);
        }
      } else {
        digitalWrite(ledPin, LOW);
        Serial.println("No Aurora Borealis detected, LED is OFF.");
      }
    } else {
      Serial.println("Error: Unable to fetch K-index data.");
    }
    http.end();
  } else {
    Serial.println("Error: Disconnected from Wi-Fi.");
  }

  delay(900000); // Check for Aurora Borealis every 15 min (900000 ms)
}
