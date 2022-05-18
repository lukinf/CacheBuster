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
	
	std::string *path = new std::string("/Users/lukas/Desktop/Projects/www.lukas.fridl.cz/js/");
	
	Directory *directory = new Directory(path);
	std::cout << *directory->GetPath() << std::endl;
	
	// *path = "Test";
	// std::cout << *directory->GetPath() << std::endl;
	
	File *file = new File("Test");
	
	delete directory;
	delete file;
	
	return 0;
}
