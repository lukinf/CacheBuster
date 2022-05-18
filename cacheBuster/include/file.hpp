//
//  file.hpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#ifndef file_hpp
#define file_hpp

#include <stdio.h>
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <iostream>
#include <sstream>
#include <uuid/uuid.h>

class File {
public:
	File(std::string Path);
	void SetName(std::string Name);
	std::string ToString();
	~File();
protected:
	std::string path;
	std::string name;
	std::string ConvertToString(char* a, int size);
	std::string GenerateUUID();
};

#endif /* file_hpp */
