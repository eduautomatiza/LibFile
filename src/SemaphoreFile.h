/**
 * @file SemaphoreFile.h
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief SemaphoreFile class for secure file access in an embedded system,
 * using semaphores to ensure exclusive access during read and write.
 * @version 0.0.2
 * @date 2024-03-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <Arduino.h>
#include <FS.h>
#include <freertos/semphr.h>

/**
 * @brief
 *
 */
class SemaphoreFile {
 public:
  enum operation_t { READ_FILE = 0, WRITE_FILE = 1 };

  SemaphoreFile(FS* fs, const char* path);
  ~SemaphoreFile();

  File* open(operation_t operation);
  void close(void);
  bool exists(void);

 private:
  FS* _fs;
  File _file;
  String _path;
  SemaphoreHandle_t _semaphore;
};
