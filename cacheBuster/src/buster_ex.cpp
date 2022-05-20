//
//  duplicate_file_ex.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 21.05.2022.
//

#include "buster_ex.hpp"

BusterEx::BusterEx(const std::string& msg){
	ErrorMessage = msg;
}

const char* BusterEx::what() const throw()
{
	return ErrorMessage.c_str();
};
