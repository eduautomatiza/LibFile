/**
 * @file StringFile.h
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.1
 * @date 2024-03-21
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <Arduino.h>
#include <SemaphoreFile.h>

#include <TransferFile.hpp>

class StringFile : protected TransferRead<String>,
                   protected TransferWrite<String> {
 public:
  explicit StringFile(SemaphoreFile* file);

  bool save(String* str);
  bool load(String* str);
  String toString();

 private:
  SemaphoreFile* _file;

  virtual bool transferWriteData(String* from, File* to) override;
  virtual bool transferReadData(File* from, String* to) override;
};
