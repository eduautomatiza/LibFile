/**
 * @file CopyFile.hpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.2
 * @date 2024-03-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <Arduino.h>
#include <SemaphoreFile.h>

template <typename T>
class CopyFile {
 public:
  CopyFile(SemaphoreFile* file) : _file(file) {}

  bool copy(T* data, SemaphoreFile::operation_t operation) {
    bool result = false;
    auto file = _file->open(operation);
    if (file) {
      if (operation == SemaphoreFile::WRITE_FILE) {
        result = toFile(data, file);
      } else {
        result = fromFile(file, data);
      }
      _file->close();
    }
    return result;
  }

  bool load(T* to) { return copy(to, SemaphoreFile::READ_FILE); }

  bool save(T* from) { return copy(from, SemaphoreFile::WRITE_FILE); }

  virtual bool fromFile(File* from, T* to) = 0;
  virtual bool toFile(T* from, File* to) = 0;

 private:
  SemaphoreFile* _file;
};
