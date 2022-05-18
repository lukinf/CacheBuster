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
  void set_name(std::string Name);
  std::string to_string();
  void to_file(std::string File);
  ~File();
private:
  std::string path;
  std::string name;
protected:
  std::string convert_to_string(char* a, int size);
  std::string generate_uuid();
};

#endif /* file_hpp */
