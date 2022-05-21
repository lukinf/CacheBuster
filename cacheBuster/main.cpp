//
//  main.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//	/Users/lukas/Desktop/Projects/www.lukas.fridl.cz/

#include <iostream>
#include "buster.hpp"
#include "directory.hpp"
#include "file.hpp"

int main(int argc, const char * argv[]) {
	std::string path;
	bool firstRun = false;
	std::string firstRunS;
	std::cout << "First run? Y/N:";
	std::cin >> firstRunS;
	std::cout << "Enter absolute path:";
	std::cin >> path;
	if (firstRunS == "Y") {
		firstRun = true;
	} else if (firstRunS == "N") {
		firstRun = false;
	} else {
		return 0;
	}
	Directory directory = Directory(path);
	Buster::test_run(directory.get_files());
	Buster::run(firstRun, directory.get_files());
	std::cout << "Done..." << std::endl;
	return 0;
}
