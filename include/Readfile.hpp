/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Readfile
*/

#ifndef READFILE_HPP_
	#define READFILE_HPP_

#include <vector>
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
		std::vector<std::unique_ptr<IComponent>> &getList();
		void listDump() const;
		void argsChecker(const char *str);
	private:
		void isValid() const;
		void checkLine(std::string line);
		void setRom(const std::string &type, std::string &name);
		void linkSetter(const std::string &, const int &,
				const std::string &, const int &);
		void readFile();
		void parseLine(std::string line, ParseWork a);
		void setChipset(const std::string &, std::string &);
		void setLink(const std::string &, const std::string &);
		bool argsHandler(int ac, char **av);
		bool argsNameChecker(char **av);
		bool isComponentInList(const std::string &name);
		std::unique_ptr<nts::IComponent> &getComponent(
			const std::string &name);
		bool rmInputArgs(const std::string &);
		std::vector<std::unique_ptr<IComponent>> _list;
		std::string _fileName;
		int _ac;
		int _nbrInput;
		std::vector<std::string> _vector;
	};
};

#endif /* READFILE_HPP_ */
