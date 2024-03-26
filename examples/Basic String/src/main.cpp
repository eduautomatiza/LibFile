/**
 * @file main.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.1
 * @date 2024-03-18
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <Arduino.h>
#include <SPIFFS.h>
#include <SemaphoreFile.h>
#include <StringFile.h>

#define FILESYSTEM SPIFFS

SemaphoreFile config_file(&FILESYSTEM, "/string.txt");
StringFile string_file(&config_file);

void loop(void) { vTaskDelay(1000); }

void setup(void) {
  Serial.begin(9600);

  FILESYSTEM.begin(true, "/spiffs");

  if (!config_file.exists()) {
    String txt = "Conteúdo do arquivo stream";
    string_file.save(&txt);
  }

  String txt2 = string_file.toString();
  Serial.print(txt2);
}
