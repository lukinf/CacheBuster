//
//  file.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "file.hpp"

File::File(std::string Name)
{
	name = Name;
	std::cout << "Constructor of File " << name << std::endl;
	
	uuid_t out;
	char *id = new char[100];
	
	uuid_generate(out);
	uuid_unparse(out, id);
	
	std::cout << id << std::endl;
}

File::~File()
{
	std::cout << "Destructor of File " << name << std::endl;
}
