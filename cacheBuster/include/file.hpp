//
//  file.hpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#ifndef file_hpp
#define file_hpp

#include <stdio.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <uuid/uuid.h>
#include "params.hpp"

class File {
public:
  File(std::string Path);
  std::string get_name();
  void set_name(std::string NewName);
  std::string get_new_name();
  void set_new_name(std::string NewName);
  std::string get_path();
  std::string get_extension();
  void set_extension(std::string Extension);
  void add_reference(int Reference);
  int get_references();
  std::string to_string();
  void to_file(std::string File);
  void rename(std::string NewName);
  std::string generate_uuid();
  ~File();
private:
  std::string path;
  std::string name;
  std::string newName;
  std::string extension;
  int references = 0;
protected:
  std::string convert_to_string(char* a, int size);
};

#endif /* file_hpp */
