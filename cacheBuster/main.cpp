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
	std::string path = "/Users/lukas/Desktop/Projects/www.lukas.fridl.cz/www.lukas.fridl.cz/";
	Directory *directory = new Directory(path);
	//directory->get_files()->at(0)->to_file("Test");
	Buster::find_references(directory->get_files());
	delete directory;
	return 0;
}
