//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef ERROR_HPP_
	# define ERROR_HPP_

#include <iostream>
#include <exception>

class FileError : public std::exception {
public:
	const char *what() const noexcept;
	FileError(const std::string &what);
private:
	std::string _what;	
};

#endif /* !ERROR_HPP_ */
