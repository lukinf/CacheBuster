//
//  directory.hpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#ifndef directory_hpp
#define directory_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include "file.hpp"
#include "params.h"

class Directory {
public:
	Directory(std::string Path);
	std::string get_path();
	std::vector<File*>* get_files();
	~Directory();
private:
	std::string path;
	std::vector<File*> files;
protected:
	void get_directory_files(std::string Path);
	bool check_file_extension(std::filesystem::path Path);
};

#endif /* directory_hpp */
