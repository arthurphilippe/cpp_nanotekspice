/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Error
*/

#include "Error.hpp"

FileError::FileError(const std::string &what)
	: _what(what)
{}

const char *FileError::what() const noexcept
{
	std::cerr << _what << std::endl;
	return (_what.c_str());
}


RuntimeError::RuntimeError(const std::string &what)
	: _what(what)
{}

const char *RuntimeError::what() const noexcept
{
	std::cerr << _what << std::endl;
	return (_what.c_str());
}
