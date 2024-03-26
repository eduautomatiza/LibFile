/**
 * @file ClientFile.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.1
 * @date 2024-03-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "ClientFile.h"

ClientFile::ClientFile(SemaphoreFile* file) : _file(file) {}

bool ClientFile::load(Client* str) {
  return transferRead(_file, str);
}

bool ClientFile::transferReadData(File* from, Client* to) {
  bool result = false;
  if (to->write(*from) == from->size()) result = true;
  return result;
}
