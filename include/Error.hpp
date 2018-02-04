//
// EPITECH PROJECT, 2018
// nanotekspice
// File description:
// errors class headers
//

#ifndef ERROR_HPP_
	# define ERROR_HPP_

#include <iostream>
#include <exception>

class RuntimeError : public std::exception {
public:
	const char *what() const noexcept;
        RuntimeError(const std::string &what);
	const std::string &getError() const {return _what;}
private:
	std::string _what;
};

class FileError : public std::exception {
public:
	const char *what() const noexcept;
	FileError(const std::string &what);
	const std::string &getError() const {return _what;}
private:
	std::string _what;
};

#endif /* !ERROR_HPP_ */
