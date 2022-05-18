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
	GetFiles(*path);
}

std::string* Directory::GetPath()
{
	return path;
}

void Directory::GetFiles(std::string Path)
{
	for (const auto & entry : std::filesystem::directory_iterator(Path))
	{
		if (entry.is_directory() == true){
			std::cout << "Directory - " << entry.path() << std::endl;
			GetFiles(entry.path());
		} else {
			std::cout << "File - " << entry.path() << std::endl;
		}
	}
}

Directory::~Directory()
{
	std::cout << "Destructor of " << *path << std::endl;
}
