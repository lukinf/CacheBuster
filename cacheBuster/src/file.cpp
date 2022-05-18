//
//  file.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "file.hpp"

File::File(std::string Path) {
	path = Path;
}

void File::SetName(std::string Name) {
	name = Name;
	std::cout << "Instance of File " << name << std::endl;
}

std::string File::GenerateUUID() {
	uuid_t out;
	char id[37];
	
	uuid_generate_random(out);
	uuid_unparse_lower(out, id);
	
	int size = sizeof(id);
	std::string uuidStr = ConvertToString(id, size);
	uuidStr.erase(std::remove(uuidStr.begin(), uuidStr.end(), '-'), uuidStr.end());
	
	return uuidStr;
}

std::string File::ToString() {
	std::ifstream inFile;
	inFile.open(name);
	
	std::stringstream strStream;
	strStream << inFile.rdbuf();
	std::string str = strStream.str();
	
	return str;
}

std::string File::ConvertToString(char* a, int size) {
	int i;
	std::string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

File::~File() {
	std::cout << "Destructor of File " << name << std::endl;
}
