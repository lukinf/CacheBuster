//
//  directory.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "directory.hpp"

Directory::Directory(std::string *Path) {
	path = Path;
	std::cout << "Constructor of " << *path << std::endl;
	GetFiles(*path);
}

std::string* Directory::GetPath() {
	return path;
}

void Directory::GetFiles(std::string Path) {
	char hidden;
	for (const auto & entry : std::filesystem::directory_iterator(Path))
	{
		if (entry.is_directory() == true){
			hidden = entry.path().filename().c_str()[0];
			if (hidden != 0x2E ){
				GetFiles(entry.path());
			}
		} else {
			hidden = entry.path().filename().c_str()[0];
			if (hidden != 0x2E ){
				if (entry.is_regular_file() == true and CheckFileExtension(entry.path()) == true){
					File *file = new File(entry.path());
					file->SetName(entry.path().filename());
					files.push_back(file);
				}
			}
		}
	}
}

bool Directory::CheckFileExtension(std::filesystem::path Path){
	if (Path.filename().extension() == ".js" or Path.filename().extension() == ".html" or Path.filename().extension() == ".css"){
		return true;
	} else {
		return false;
	}
}

Directory::~Directory() {
	for (int i = 0; i < files.size(); i++) {
		delete files[i];
	}
	std::cout << "Destructor of " << *path << std::endl;
}
