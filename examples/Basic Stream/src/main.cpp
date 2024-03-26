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
#include <StreamFile.h>
#include <StreamString.h>

#define FILESYSTEM SPIFFS

SemaphoreFile config_file(&FILESYSTEM, "/stream.txt");
StreamFile stream_file(&config_file);

void loop(void) { vTaskDelay(1000); }

void setup(void) {
  Serial.begin(9600);

  FILESYSTEM.begin(true, "/spiffs");

  if (!config_file.exists()) {
    StreamString content;
    content.print("Conteúdo do arquivo stream");
    stream_file.save(&content);
  }

  stream_file.load(&Serial);
}
