//
//  file.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "file.hpp"

File::File(std::string Path) {
  path = Path;
}

std::string File::get_name(){
  return name;
}

void File::set_name(std::string Name) {
  name = Name;
}

void File::add_reference(int Reference){
  references = references + 1;
}

int File::get_references(){
  return references;
}

std::string File::get_path(){
  return path;
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

std::unique_ptr<std::string> File::to_string() {
  std::ifstream inFile;
  inFile.open(path);
  std::stringstream strStream;
  strStream << inFile.rdbuf();
  return std::make_unique<std::string>(strStream.str());
}

void File::to_file(const std::string& File) {
  std::ofstream out(path);
  out << File;
  out.close();
}

std::string File::convert_to_string(char a[UUID_LENGTH], int size) {
  std::string s = "";
  for (int i = 0; i < size; i++) {
    s = s + a[i];
  }
  return s;
}

File::~File() {
}
