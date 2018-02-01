//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "Error.hpp"

FileError::FileError(const std::string &what)
	: _what(what)
{}

const char *FileError::what() const noexcept
{
	std::cerr << _what << std::endl;
	return (_what.c_str());
}
