/**
 * @file StreamFile.h
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.2
 * @date 2024-03-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#pragma once

#include <Arduino.h>
#include <SemaphoreFile.h>

#include <CopyFile.hpp>

class StreamFile : public CopyFile<Stream> {
 public:
  explicit StreamFile(SemaphoreFile* file);
  bool toFile(Stream* from, File* to) override;
  bool fromFile(File* from, Stream* to) override;
};
