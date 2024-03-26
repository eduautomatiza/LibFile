/**
 * @file StreamFile.h
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.1
 * @date 2024-03-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <Arduino.h>
#include <SemaphoreFile.h>

#include <TransferFile.hpp>

class StreamFile : protected TransferRead<Stream>,
                   protected TransferWrite<Stream> {
 public:
  explicit StreamFile(SemaphoreFile* file);

  bool save(Stream* from);
  bool load(Stream* to);

 private:
  SemaphoreFile* _file;

  bool transferWriteData(Stream* from, File* to) override;
  bool transferReadData(File* from, Stream* to) override;
};
