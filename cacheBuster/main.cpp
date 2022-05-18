//
//  main.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include <iostream>
#include "directory.hpp"

int main(int argc, const char * argv[]) {
	
	std::string * path = new std::string("Test/test");
	
	Directory * directory = new Directory(path);
	directory->GetPath();
	delete directory;
	
	// insert code here...
	std::cout << "Hello, World!\n";
	return 0;
	
}
