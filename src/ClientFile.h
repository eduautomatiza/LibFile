/**
 * @file ClientFile.h
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

class ClientFile : protected TransferRead<Client> {
 public:
  explicit ClientFile(SemaphoreFile* file);

  bool load(Client* content);

 private:
  SemaphoreFile* _file;
  virtual bool transferReadData(File* from, Client* to) override;
};
