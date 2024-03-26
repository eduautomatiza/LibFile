/**
 * @file StreamFile.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.1
 * @date 2024-03-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "StreamFile.h"

StreamFile::StreamFile(SemaphoreFile* file) : _file(file) {}

bool StreamFile::save(Stream* str) { return transferWrite(str, _file); }

bool StreamFile::load(Stream* str) { return transferRead(_file, str); }

bool StreamFile::transferWriteData(Stream* from, File* to) {
  bool result = false;
  size_t size = 0;
  uint8_t buffer[128];
  while (true) {
    size_t length = from->readBytes(buffer, sizeof(buffer));
    if (length)
      size += to->write(buffer, length);
    else
      break;
  }
  if (size == to->size()) result = true;
  return result;
}

bool StreamFile::transferReadData(File* from, Stream* to) {
  bool result = false;
  size_t size = 0;
  uint8_t buffer[128];
  while (true) {
    size_t length = from->read(buffer, sizeof(buffer));
    if (length)
      size += to->write(buffer, length);
    else
      break;
  }
  if (size == from->size()) result = true;
  return result;
}
