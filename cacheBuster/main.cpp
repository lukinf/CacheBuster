//
//  main.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//	/Users/lukas/Desktop/Projects/www.lukas.fridl.cz/;

#include <iostream>
#include "buster.hpp"
#include "directory.hpp"
#include "file.hpp"

int main(int argc, const char * argv[]) {
	std::string path;
	std::cout << "Enter absolute path:";
	std::cin >> path;
	Directory directory = Directory(path);
	Buster::test_run(directory.get_files());
	Buster::run(false, directory.get_files());
	std::cout << "Done..." << std::endl;
	return 0;
}
