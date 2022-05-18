//
//  file.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "file.hpp"

File::File(std::string Path) {
  this->path = Path;
}

void File::set_name(std::string Name) {
  this->name = Name;
  std::cout << "Instance of File " << name << std::endl;
}

std::string File::generate_uuid() {
  uuid_t out;
  char id[37];
  uuid_generate_random(out);
  uuid_unparse_lower(out, id);
  std::string uuidStr = convert_to_string(id, sizeof(id));
  uuidStr.erase(std::remove(uuidStr.begin(), uuidStr.end(), '-'), uuidStr.end());
  return uuidStr;
}

std::string File::to_string() {
  std::ifstream inFile;
  inFile.open(this->name);
  std::stringstream strStream;
  strStream << inFile.rdbuf();
  std::string str = strStream.str();
  return str;
}

std::string File::convert_to_string(char* a, int size) {
  std::string s = "";
  for (int i = 0; i < size; i++) {
    s = s + a[i];
  }
  return s;
}

File::~File() {
  std::cout << "Destructor of File " << this->name << std::endl;
}
