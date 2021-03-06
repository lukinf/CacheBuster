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
#include "params.hpp"

class Directory {
public:
	Directory(const std::string& Path);
	std::string& get_path();
	std::vector<File>& get_files();
	~Directory();
private:
	std::string path;
	std::vector<File> files;
	Extension resolveOption(const std::string& input);
protected:
	void get_directory_files(const std::string& Path);
	bool check_file_extension(const std::filesystem::path& Path);
};

#endif /* directory_hpp */
