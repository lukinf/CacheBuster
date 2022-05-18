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
#include <uuid/uuid.h>

class File
{
public:
	File(std::string Name);
	~File();
protected:
	std::string name;
};

#endif /* file_hpp */
