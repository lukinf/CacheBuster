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
	std::string qa;
	
first_run:
	qa.clear();
	std::cout << "First run? Y/N:";
	std::cin >> qa;
	if (qa == "Y") {
		qa = true;
	} else if (qa == "N") {
		qa = false;
	} else {
		goto first_run;
	}

enter_path:
	std::cout << "Enter absolute path:";
	std::cin >> path;
	if (path.empty() == true){
		goto enter_path;
	}
	
	Directory directory = Directory(path);
	Buster::test_run(directory.get_files());
	std::cout << std::endl;
	
write_changes:
	qa.clear();
	std::cout << "Test run done, write changes? Y/N:";
	std::cin >> qa;
	if (qa == "Y") {
		Buster::run(firstRun, directory.get_files());
	} else if (qa == "N") {
		std::cout << "No changes has been written..." << std::endl;
	} else {
		goto write_changes;
	}
	
	std::cout << "Buster run done..." << std::endl;
	return 0;
}
