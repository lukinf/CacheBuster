//
//  directory.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "directory.hpp"

Directory::Directory(std::string Path) {
  this->path = Path;
  if (DEBUG_INFO == 1)
    std::cout << "Constructor of " << this->path << std::endl;
  this->get_directory_files(this->path);
}

std::string Directory::get_path() {
  return this->path;
}

void Directory::get_directory_files(std::string Path) {
  char hidden;
  for (const auto & entry : std::filesystem::directory_iterator(Path))
  {
    if (entry.is_directory() == true){
      hidden = entry.path().filename().c_str()[0];
      if (hidden != HIDDEN_DOT ){
        this->get_directory_files(entry.path());
      }
    } else {
      hidden = entry.path().filename().c_str()[0];
      if (hidden != HIDDEN_DOT ){
        if (entry.is_regular_file() == true and this->check_file_extension(entry.path()) == true){
          File *file = new File(entry.path());
          file->set_name(entry.path().filename());
          this->files.push_back(file);
        }
      }
    }
  }
}

std::vector<File*>* Directory::get_files(){
  std::vector<File*> *vectorP;
  return vectorP = &this->files;
}

bool Directory::check_file_extension(std::filesystem::path Path){
  if (Path.filename().extension() == ".js"
      or Path.filename().extension() == ".html"
      or Path.filename().extension() == ".css"){
    return true;
  } else {
    return false;
  }
}

Directory::~Directory() {
  for (int i = 0; i < this->files.size(); i++) {
    delete this->files[i];
  }
  if (DEBUG_INFO == 1)
    std::cout << "Destructor of " << this->path << std::endl;
}
