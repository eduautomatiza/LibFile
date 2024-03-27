/**
 * @file JsonFile.h
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.2
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

#include <CopyFile.hpp>

class JsonFile : public CopyFile<JsonDocument> {
 public:
  explicit JsonFile(SemaphoreFile* file);
  JsonDocument toJsonDocument(void);
  bool toFile(JsonDocument* from, File* to) override;
  bool fromFile(File* from, JsonDocument* to) override;
};

#endif
#endif
