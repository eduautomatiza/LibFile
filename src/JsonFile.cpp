/**
 * @file JsonFile.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.1
 * @date 2024-03-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#if defined(__has_include)
#if __has_include(<ArduinoJson.h>)

#include "JsonFile.h"

JsonFile::JsonFile(SemaphoreFile* file) : CopyFile<JsonDocument>(file) {}

JsonDocument JsonFile::toJsonDocument(void) {
  JsonDocument to;
  load(&to);
  return to;
}

bool JsonFile::toFile(JsonDocument* from, File* to) {
  bool result = false;
  serializeJson(*from, *to);
  result = true;
  return result;
}

bool JsonFile::fromFile(File* from, JsonDocument* to) {
  bool result = false;
  if (deserializeJson(*to, *from) == DeserializationError::Ok) {
    result = true;
  } else {
    to->clear();
  }
  return result;
}

#endif
#endif
