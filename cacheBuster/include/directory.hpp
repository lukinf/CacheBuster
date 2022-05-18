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

class Directory {
public:
	Directory(std::string *Path);
	std::string* GetPath();
	~Directory();
protected:
	std::string *path;
	std::vector<File*> files;
	void GetFiles(std::string Path);
	bool CheckFileExtension(std::filesystem::path Path);
};

#endif /* directory_hpp */
