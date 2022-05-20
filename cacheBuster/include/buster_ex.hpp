//
//  duplicate_file_ex.hpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 21.05.2022.
//

#ifndef buster_ex_hpp
#define buster_ex_hpp

#include <stdio.h>
#include <string>
#include <exception>

class BusterEx : virtual public std::exception
{
public:
	explicit
	BusterEx(const std::string& msg);
	virtual const char* what() const throw();
protected:
	std::string ErrorMessage;
};

#endif /* duplicate_file_ex_hpp */
