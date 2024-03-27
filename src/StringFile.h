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

#include <CopyFile.hpp>

class StringFile : public CopyFile<String> {
 public:
  explicit StringFile(SemaphoreFile* file);
  String toString();
  bool toFile(String* from, File* to) override;
  bool fromFile(File* from, String* to) override;
};
