//
//  buster.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "buster.hpp"

void Buster::find_references(std::vector<File> Files){
  for(auto &fileFirstLoop : Files){
    std::string fileStr = fileFirstLoop.get_content();
    for(auto &fileSecLoop : Files){
      auto position = fileStr.find(fileSecLoop.get_name());
      if (position!=std::string::npos)
        fileSecLoop.add_reference(1);
    }
  }
  for(auto &fileResult : Files){
    std::cout << fileResult.get_name() << " - " << fileResult.get_references() << " Ref" << std::endl;
  }
}

void Buster::write_new_references(bool FirstRun, std::vector<File> Files) {
  first_run = FirstRun;
  files = Files;
  generate_new_names();
  change_references();
  rename_files();
}

void Buster::generate_new_names() {
  std::string uuid;
  std::string newNameSub;
  for(auto &file : files){
    auto name = file.get_name();
    auto ext = file.get_extension();
    if (first_run == true) {
      uuid = file.get_new_UUID();
      newNameSub = name.substr(0, name.length() - ext.length());
      std::string newName = newNameSub + "_" + uuid + ext;
      file.set_new_name(newName);
    } else {
      int charsToRemove = 28 + (int)ext.length() + 1;
      uuid = file.get_new_UUID();
      newNameSub = name.substr(0, name.length() - charsToRemove);
      std::string newName = newNameSub + "_" + uuid + ext;
      file.set_new_name(newName);
    }
  }
}

void Buster::change_references() {
  for(auto &fileFirstLoop : files){
    std::string fileStr = fileFirstLoop.get_content();
    for(auto &fileSecLoop : files){
      std::string::size_type n = 0;
      while ((n = fileStr.find( fileSecLoop.get_name(), n )) != std::string::npos)
      {
        fileStr.replace(n, fileSecLoop.get_name().size(), fileSecLoop.get_new_name());
        n += fileSecLoop.get_new_name().size();
      }
    }
    fileFirstLoop.set_content(fileStr);
  }
}

void Buster::rename_files() {
  for(auto &file : files){
    auto name = file.get_name();
    if (name.substr(0, 5) != "index") {
      file.rename(file.get_new_name());
    }
  }
}
