/**
 * @file ClientFile.h
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

class ClientFile : public CopyFile<Client> {
 public:
  explicit ClientFile(SemaphoreFile* file);
  bool fromFile(File* from, Client* to) override;
};
