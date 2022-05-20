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

std::string File::get_new_name(){
  return newName;
}

void File::set_new_name(std::string NewName) {
  newName = NewName;
}

std::string File::get_extension(){
  return extension;
}

void File::set_extension(std::string Extension) {
  extension = Extension;
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
  char id[32];
  uuid_generate_random(out);
  uuid_unparse_lower(out, id);
  auto uuidStr = convert_to_string(id, sizeof(id));
  uuidStr.erase(std::remove(uuidStr.begin(), uuidStr.end(), '-'), uuidStr.end());
  return uuidStr;
}

void File::rename(std::string NewName) {
  auto newPath = path;
  newPath = newPath.substr(0, newPath.size()-name.length());
  newPath = newPath + NewName;
  std::filesystem::rename(path, newPath);
}

std::string File::to_string() {
  std::ifstream inFile;
  inFile.open(path);
  std::stringstream strStream;
  strStream << inFile.rdbuf();
  return strStream.str();
}

void File::to_file(std::string File) {
  std::ofstream out(path);
  out << File;
  out.close();
}

std::string File::convert_to_string(char a[32], int size) {
  std::string s;
  for (int i = 0; i < size; i++) {
    s = s + a[i];
  }
  return s;
}

File::~File() {
}
