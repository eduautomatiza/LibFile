/**
 * @file StreamFile.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.2
 * @date 2024-03-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "StreamFile.h"

StreamFile::StreamFile(SemaphoreFile* file) : CopyFile<Stream>(file) {}

bool StreamFile::toFile(Stream* from, File* to) {
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

bool StreamFile::fromFile(File* from, Stream* to) {
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
