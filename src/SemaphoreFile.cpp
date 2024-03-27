/**
 * @file SemaphoreFile.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief SemaphoreFile class for secure file access in an embedded system,
 * using semaphores to ensure exclusive access during read and write.
 * @version 0.0.2
 * @date 2024-03-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "SemaphoreFile.h"

SemaphoreFile::SemaphoreFile(FS* fs, const char* path)
    : _fs(fs), _semaphore(xSemaphoreCreateBinary()), _path(path) {
  xSemaphoreGive(_semaphore);
}

SemaphoreFile::~SemaphoreFile() {
  if (_file) {
    _file.close();
  }
  vSemaphoreDelete(_semaphore);
}

File* SemaphoreFile::open(operation_t operation) {
  if (xSemaphoreTake(_semaphore, portMAX_DELAY) == pdTRUE) {
    if (_fs) {
      _file =
          _fs->open(_path, operation == operation_t::WRITE_FILE ? "w" : "r");
      if (_file && !_file.isDirectory()) {
        return &_file;
      }
    }
    close();
  }
  return nullptr;
}

void SemaphoreFile::close(void) {
  if (_file) {
    _file.close();
  }
  xSemaphoreGive(_semaphore);
}

bool SemaphoreFile::exists(void) {
  bool result = false;
  if (_fs) {
    File file = _fs->open(_path, "r");
    if (file && !file.isDirectory()) {
      result = true;
    }
    file.close();
  }
  return result;
}
