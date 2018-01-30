//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#ifndef READFILE_HPP_
	# define READFILE_HPP_

namespace nts::readfile {
	enum ParseWork {
		CHIPSET,
		LINK
	};
	void parseLine(std::string line, ParseWork a);
	void setChipset(std::string, std::string);
	void setLink(std::string, std::string);
	void readFile(const std::string &line);
	void checkLine(std::string line);

}

#endif /* READFILE_HPP_ */
