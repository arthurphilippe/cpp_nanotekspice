//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include <fstream>
#include "readfile.hpp"



void nts::readfile::readFile(std::string file)
{
	std::ifstream fd(file.c_str());
	std::string line;

	if (fd.is_open() == false) {
		std::cerr << "Received invalid file in argument" << std::endl;
		throw;
	}
	while (getline(fd, line)) {
	        line = line.substr(0, line.find("#"));
		if (line.size() != 0)
		std::cout << line << std::endl;
	}
}
