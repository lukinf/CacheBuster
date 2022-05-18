//
//  directory.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "directory.hpp"

Directory::Directory(std::string *Path)
{
	path = Path;
	std::cout << "Constructor of " + *path + "\n";
}

std::string* Directory::GetPath()
{
	return path;
}

Directory::~Directory()
{
	std::cout << "Destructor of " + *path + "\n";
}
