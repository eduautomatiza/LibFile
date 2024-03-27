/**
 * @file ClientFile.cpp
 * @author Eduardo Guse (eduautomatiza@yahoo.com.br)
 * @brief
 * @version 0.0.2
 * @date 2024-03-22
 *
 * @copyright Copyright (c) 2024
 *
 */
#include "ClientFile.h"

ClientFile::ClientFile(SemaphoreFile* file) : CopyFile<Client>(file) {}

bool ClientFile::fromFile(File* from, Client* to) {
  bool result = false;
  if (to->write(*from) == from->size()) result = true;
  return result;
}
