//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Readfile.hpp"

nts::Parser::Parser(char **fileName)
	: _fileName(fileName[1])
{
	readFile();
}

nts::Parser::Parser(std::string fileName)
	: _fileName(fileName)
{}

std::list<std::unique_ptr<nts::IComponent>> &nts::Parser::getList()
{
	return _list;
}
