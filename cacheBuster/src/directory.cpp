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

std::vector<File*>* Directory::get_files(){
  std::vector<File*> *vectorP;
  return vectorP = &this->files;
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
        if (entry.is_regular_file() == true && this->check_file_extension(entry.path()) == true){
          File *file = new File(entry.path());
          file->set_name(entry.path().filename());
          this->files.push_back(file);
        }
      }
    }
  }
}

bool Directory::check_file_extension(std::filesystem::path Path){
  switch (this->resolveOption(Path.filename().extension())) {
    case js:
      return true;
      break;
    case css:
      return true;
      break;
    case html:
      return true;
      break;
    default:
      return false;
      break;
  }
}

Extension Directory::resolveOption(std::string input) {
  if( input == EXT_JS ) return js;
  if( input == EXT_CSS ) return css;
  if( input == EXT_HTML ) return html;
  return invalid;
}

Directory::~Directory() {
  for (int i = 0; i < this->files.size(); i++) {
    delete this->files[i];
  }
  if (DEBUG_INFO == 1)
    std::cout << "Destructor of " << this->path << std::endl;
}
