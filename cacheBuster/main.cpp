//
//  main.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include <iostream>
#include "directory.hpp"
#include "file.hpp"

int main(int argc, const char * argv[]) {
	
	std::string path = "/Users/lukas/Desktop/Projects/www.lukas.fridl.cz/www.lukas.fridl.cz/";
	
	Directory *directory = new Directory(path);
	std::vector<File*> *files = directory->get_files();
	delete directory;
	
	return 0;
}
