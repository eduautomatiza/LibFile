/**
 * @file StringFile.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.1
 * @date 2024-03-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "StringFile.h"

StringFile::StringFile(SemaphoreFile* file) : CopyFile<String>(file) {}

String StringFile::toString() {
  String to;
  load(&to);
  return to;
}

bool StringFile::toFile(String* from, File* to) {
  bool result = false;
  if (to->print(*from) == from->length()) {
    result = true;
  }
  return result;
}

bool StringFile::fromFile(File* from, String* to) {
  bool result = false;
  if (to->reserve(from->size() + 1)) {
    uint8_t buffer[128];
    while (true) {
      size_t length = from->read(buffer, sizeof(buffer));
      if (length)
        to->concat(buffer, length);
      else
        break;
    }
    result = true;
  }
  return result;
}
