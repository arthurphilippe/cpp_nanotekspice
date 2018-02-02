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
		Parser(int ac, char **av);
		~Parser() {}
		enum ParseWork {
			CHIPSET,
			LINK
		};
		std::list<std::unique_ptr<IComponent>> &getList();
	private:
				void checkLine(std::string line);
		void setROM(const std::string &type, std::string &name);
		void linkSetter(const std::string &, const int &,
				const std::string &, const int &);
		void readFile();
		void parseLine(std::string line, ParseWork a);
		void setChipset(const std::string &, std::string &);
		void setLink(const std::string &, const std::string &);
		bool argsHandler(int ac, char **av);
		void argsChecker(const char *str);
	        bool argsNameChecker(char **av);
		IComponent *getComponent(const std::string &name);
	        bool rmInputArgs(const std::string &);
		std::list<std::unique_ptr<IComponent>> _list;
		std::string _fileName;
		int _ac;
		int _nbrInput;
		std::vector<std::string> _vector;
	};
};

int parserTester(int ac, char **av);

#endif /* READFILE_HPP_ */
