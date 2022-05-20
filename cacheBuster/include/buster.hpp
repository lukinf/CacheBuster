//
//  buster.hpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#ifndef buster_hpp
#define buster_hpp

#include <stdio.h>
#include <vector>
#include "file.hpp"

class Buster {
public:
  static void test_run(const std::vector<File>& Files);
  static void run(const bool& FirstRun,const std::vector<File>& Files);
private:
  inline static bool first_run;
  inline static std::vector<File> files;
  static void generate_new_names();
  static void change_references();
  static void rename_files();
};

#endif /* buster_hpp */
