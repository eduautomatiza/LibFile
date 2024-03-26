/**
 * @file TransferFile.hpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.1
 * @date 2024-03-26
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <Arduino.h>
#include <SemaphoreFile.h>

template <typename T>
class TransferRead {
 protected:
  bool transferRead(SemaphoreFile* from, T* to) {
    bool result = false;
    auto from_file = from->open(SemaphoreFile::operation_t::READ_FILE);
    if (from_file) {
      result = transferReadData(from_file, to);
      from->close();
    }
    return result;
  }
  virtual bool transferReadData(File* from, T* to) = 0;
};

template <typename T>
class TransferWrite {
 protected:
  bool transferWrite(T* from, SemaphoreFile* to) {
    bool result = false;
    auto to_file = to->open(SemaphoreFile::operation_t::WRITE_FILE);
    if (to_file) {
      result = transferWriteData(from, to_file);
      to->close();
    }
    return result;
  }
  virtual bool transferWriteData(T* from, File* to) = 0;
};
