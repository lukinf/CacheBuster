//
//  buster.cpp
//  cacheBuster
//
//  Created by Lukáš Frídl on 18.05.2022.
//

#include "buster.hpp"

void Buster::find_references(std::vector<File> Files){
	for(auto &fileFirstLoop : Files){
		std::string fileStr = fileFirstLoop.to_string();
		for(auto &fileSecLoop : Files){
			auto position = fileStr.find(fileSecLoop.get_name());
			if (position!=std::string::npos)
				fileSecLoop.add_reference(1);
		}
	}
	for(auto &fileResult : Files){
		std::cout << fileResult.get_name() << " - " << fileResult.get_references() << std::endl;
	}
}

void Buster::write_new_references(std::vector<File> Files, bool FirstRun) {
	for(auto &file : Files){
		std::string uuid;
		std::string newNameSub;
		auto name = file.get_name();
		auto ext = file.get_extension();
		if (FirstRun == true) {
			uuid = file.generate_uuid();
			newNameSub = name.substr(0, name.length() - ext.length());
			std::string newName = newNameSub + "_" + uuid + ext;
			file.set_new_name(newName);
		} else {
			int charsToRemove = 28 + ext.length() + 1;
			uuid = file.generate_uuid();
			newNameSub = name.substr(0, name.length() - charsToRemove);
			std::string newName = newNameSub + "_" + uuid + ext;
			file.set_new_name(newName);
		}
	}
	for(auto &fileFirstLoop : Files){
		std::string fileStr = fileFirstLoop.to_string();
		for(auto &fileSecLoop : Files){
			std::string::size_type n = 0;
			while ((n = fileStr.find( fileSecLoop.get_name(), n )) != std::string::npos)
			{
				fileStr.replace(n, fileSecLoop.get_name().size(), fileSecLoop.get_new_name());
				n += fileSecLoop.get_new_name().size();
			}
		}
		fileFirstLoop.to_file(fileStr);
	}
	for(auto &file : Files){
		auto name = file.get_name();
		if (name.substr(0, 5) != "index") {
			file.rename(file.get_new_name());
		}
	}
}
