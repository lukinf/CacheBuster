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

class Directory
{
public:
	Directory(std::string *Path);
	std::string* GetPath();
	~Directory();
protected:
	std::string *path;
	void GetFiles(std::string Path);
};

#endif /* directory_hpp */
