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

std::string File::get_name(){
  return this->name;
}

void File::set_name(std::string Name) {
  this->name = Name;
  if (DEBUG_INFO == 1)
    std::cout << "Instance of File " << name << std::endl;
}

void File::add_reference(int Reference){
  this->references = this->references + 1;
}

int File::get_references(){
  return this->references;
}

std::string File::get_path(){
  return this->path;
}

std::string File::generate_uuid() {
  uuid_t out;
  char id[UUID_LENGTH];
  uuid_generate_random(out);
  uuid_unparse_lower(out, id);
  std::string uuidStr = convert_to_string(id, sizeof(id));
  uuidStr.erase(std::remove(uuidStr.begin(), uuidStr.end(), '-'), uuidStr.end());
  return uuidStr;
}

std::string File::to_string() {
  std::ifstream inFile;
  inFile.open(this->path);
  std::stringstream strStream;
  strStream << inFile.rdbuf();
  std::string str = strStream.str();
  return str;
}

void File::to_file(std::string File) {
  std::ofstream out(this->path);
  out << File;
  out.close();
}

std::string File::convert_to_string(char* a, int size) {
  std::string s = "";
  for (int i = 0; i < size; i++) {
    s = s + a[i];
  }
  return s;
}

File::~File() {
  if (DEBUG_INFO == 1)
    std::cout << "Destructor of File " << this->name << std::endl;
}
