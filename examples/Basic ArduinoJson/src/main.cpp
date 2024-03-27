/**
 * @file main.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.2
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <Arduino.h>
#include <ArduinoJson.h>
#include <JsonFile.h>
#include <SPIFFS.h>
#include <SemaphoreFile.h>

#define FILESYSTEM SPIFFS

SemaphoreFile config_file(&FILESYSTEM, "/config.json");
JsonFile json_file(&config_file);

void loop(void) { vTaskDelay(1000); }

void setup(void) {
  Serial.begin(9600);

  FILESYSTEM.begin(true, "/spiffs");

  if (!config_file.exists()) {
    JsonDocument doc;
    doc["wifi"]["ssid"] = "wifi_ssid";
    doc["wifi"]["pass"] = "wifi_password";

    json_file.save(&doc);
  }

  JsonDocument doc2 = json_file.toJsonDocument();
  serializeJson(doc2, Serial);
}
