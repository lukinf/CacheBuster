//
//  directory.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "directory.hpp"

Directory::Directory(std::string Path) {
  path = Path;
  get_directory_files(path);
}

std::string Directory::get_path() {
  return path;
}

std::vector<File> Directory::get_files(){
  return files;
}

void Directory::get_directory_files(std::string Path) {
  for (const auto &entry : std::filesystem::directory_iterator(Path))
  {
    if (entry.is_directory() == true){
      auto hidden = entry.path().filename().c_str()[0];
      if (hidden != HIDDEN_DOT ){
        get_directory_files(entry.path());
      }
    } else {
      auto hidden = entry.path().filename().c_str()[0];
      if (hidden != HIDDEN_DOT ){
        if (entry.is_regular_file() == true && check_file_extension(entry.path()) == true){
          File file = File(entry.path());
          file.set_name(entry.path().filename());
          file.set_extension(entry.path().filename().extension());
          files.push_back(file);
        }
      }
    }
  }
}

bool Directory::check_file_extension(std::filesystem::path Path){
  switch (resolveOption(Path.filename().extension())) {
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
}
