//
// EPITECH PROJECT, 2018
// NanoTekSpiiiice
// File description:
// Args Handler
//

#include <algorithm>
#include <vector>
#include "Readfile.hpp"
#include "Error.hpp"

bool nts::Parser::rmInputArgs(const std::string &name)
{
	for (auto i = _vector.begin(); i != _vector.end(); i++) {
		if (*i == name) {
			if (getComponent(name)->getType().compare("input") == 0) {
				--_nbrInput;
				return true;
			}
		}
	}
	throw FileError("Error : False Argument");
}

bool nts::Parser::argsNameChecker(char **av)
{
	int tokenPlace;
	int i = 2;
	std::string tmp;

	while (av[i]) {
		tmp = av[i];
		tokenPlace = tmp.find("=");
		if (tokenPlace < 1)
			throw FileError("Error : Check the argument !");
		tmp = tmp.substr(0, tokenPlace);
		_vector.push_back(tmp);
		i++;
	}
	for (auto k = _vector.begin(); k != _vector.end(); k++) {
		if (count(_vector.begin(), _vector.end(), *k) != 1)
			throw FileError("Error : Check the argument \
there are multiple definitions of an input !");
	}
	return (true);
}

void nts::Parser::argsChecker(const char *str)
{
	std::string arg(str);
	std::string chipset;
	std::string value;
	int tokenPlace;

	tokenPlace = arg.find("=");
	chipset = arg.substr(0, tokenPlace);
	value = arg.substr(tokenPlace + 1, arg.length());
	if (value.compare("1") != 0 && value.compare("0") != 0)
		throw FileError("Error : Check the value !");
	if (isComponentInList(chipset)) {
		auto &tmp = getComponent(chipset);
		if (value.compare("0") == 0)
			tmp->compute(3);
		else
			tmp->compute(2);
	} else {
		throw FileError("Error : Check the input name !");
	}
}

bool nts::Parser::argsHandler(int ac, char **av)
{
	int i = 2;

	if (ac < i + 1)
		throw FileError("Error : Please provide inputs's value");
	if (argsNameChecker(av) == true)
		while (av[i]) {
			argsChecker(av[i]);
			++i;
		}
	for (auto i = _vector.begin(); i != _vector.end(); i++) {
		rmInputArgs(*i);
	}
	return true;
}
