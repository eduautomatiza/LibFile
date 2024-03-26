/**
 * @file JsonFile.h
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.1
 * @date 2024-03-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#if defined(__has_include)
#if __has_include(<ArduinoJson.h>)

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SemaphoreFile.h>

#include <TransferFile.hpp>

class JsonFile : protected TransferRead<JsonDocument>,
                 protected TransferWrite<JsonDocument> {
 public:
  explicit JsonFile(SemaphoreFile* file);

  bool save(JsonDocument* json);
  bool load(JsonDocument* json);
  JsonDocument toJsonDocument(void);

 private:
  SemaphoreFile* _file;

  virtual bool transferWriteData(JsonDocument* from, File* to) override;
  virtual bool transferReadData(File* from, JsonDocument* to) override;
};

#endif
#endif
