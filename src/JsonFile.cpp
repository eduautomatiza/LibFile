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
#include "JsonFile.h"

JsonFile::JsonFile(SemaphoreFile* file) : _file(file) {}

bool JsonFile::save(JsonDocument* json) { return transferWrite(json, _file); }

bool JsonFile::load(JsonDocument* json) { return transferRead(_file, json); }

JsonDocument JsonFile::toJsonDocument(void) {
  JsonDocument to;
  load(&to);
  return to;
}

bool JsonFile::transferWriteData(JsonDocument* from, File* to) {
  ;
  bool result = false;
  serializeJson(*from, *to);
  result = true;
  return result;
}

bool JsonFile::transferReadData(File* from, JsonDocument* to) {
  bool result = false;
  if (deserializeJson(*to, *from) == DeserializationError::Ok) {
    result = true;
  }
  if (result != true) to->clear();
  return result;
}
