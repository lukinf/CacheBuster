//
//  buster.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "buster.hpp"

void Buster::find_references(std::vector<File*>* Files){
	for(auto fileFirstLoop : *Files){
		std::string fileStr = fileFirstLoop->to_string();
		for(auto fileSecLoop : *Files){
			std::size_t found = fileStr.find(fileSecLoop->get_name());
			if (found!=std::string::npos)
				fileSecLoop->add_reference(1);
		}
	}
	
	for(auto fileResult : *Files){
		std::cout << fileResult->get_name() << " - " << fileResult->get_references() << std::endl;
	}
}

void Buster::write_new_references(std::vector<File*>* Files){
	
}
