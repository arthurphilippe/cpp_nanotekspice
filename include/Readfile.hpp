//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#ifndef READFILE_HPP_
	# define READFILE_HPP_

#include <list>
#include <memory>
#include "DefaultComponent.hpp"
#include "IComponent.hpp"

namespace nts {
	class Parser {
	public:
		Parser(char *fileNAme);
		Parser(std::string fileName);
		~Parser() {}
		enum ParseWork {
			CHIPSET,
			LINK
		};
		void parseLine(std::string line, ParseWork a);
		void setChipset(const std::string &, std::string &);
		void setLink(const std::string &, const std::string &);
		void linkSetter(const std::string &, const int &,
				const std::string &, const int &);
		void readFile(const std::string &line);
		void checkLine(std::string line);
		void setROM(const std::string &type, std::string &name);
		std::list<std::unique_ptr<IComponent>> &getList();
	private:
		std::list<std::unique_ptr<IComponent>> _list;
		std::string _fileName;
	};
};

#endif /* READFILE_HPP_ */
