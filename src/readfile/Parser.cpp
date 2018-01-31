//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Readfile.hpp"

nts::Parser::Parser(char *fileName)
{
}

nts::Parser::Parser(std::string fileName)
{
}

std::list<std::unique_ptr<nts::IComponent>> &nts::Parser::getList()
{
	return _list;
}
