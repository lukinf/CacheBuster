//
//  main.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include <iostream>
#include "buster.hpp"
#include "directory.hpp"
#include "file.hpp"

int main(int argc, const char * argv[]) {
	std::string path = "/Users/lukas/Desktop/Projects/www.lukas.fridl.cz/";
	Directory directory = Directory(path);
	Buster::test_run(directory.get_files());
	Buster::run(false, directory.get_files());
	return 0;
}
