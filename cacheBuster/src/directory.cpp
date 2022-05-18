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
	std::cout << "Constructor of " << *path << std::endl;
	GetFiles();
}

std::string* Directory::GetPath()
{
	return path;
}

void Directory::GetFiles()
{
	for (const auto & entry : std::filesystem::directory_iterator(*path))
	{
		std::cout << entry.path() << std::endl;
	}
}

Directory::~Directory()
{
	std::cout << "Destructor of " << *path << std::endl;
}
