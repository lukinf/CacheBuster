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
  static void find_references(std::vector<File*>* Files);
  static void write_new_references(std::vector<File*>* Files);
};

#endif /* buster_hpp */
