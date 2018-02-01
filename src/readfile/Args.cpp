//
// EPITECH PROJECT, 2018
// NanoTekSpiiiice
// File description:
// Args Handler
//

#include "Readfile.hpp"
#include "Error.hpp"

void nts::Parser::argsChecker(const char *str)
{
	std::string arg(str);
	std::string chipset;
	std::string value;
	int tokenPlace;
	IComponent *tmp;

	tokenPlace = arg.find("=");
	if (tokenPlace < 1) {
		throw FileError("Error : Check the argument !");
	} else {
		chipset = arg.substr(0, tokenPlace);
		value = arg.substr(tokenPlace + 1, arg.length());
		if (value.compare("1") != 0 && value.compare("0") != 0)
			throw FileError("Error : Check the value !");
		if ((tmp = getComponent(chipset)) != nullptr) {
			if (value.compare("0") == 0)
				tmp->compute(3);
			else
				tmp->compute(2);
		} else {
			throw FileError("Error : Check the input name");
		}
	}
}

bool nts::Parser::argsHandler(int ac, char **av)
{
	int i = 2;

	if (ac < i + 1)
		return false;
	while (av[i] != '\0') {
		argsChecker(av[i]);
		++i;
	}
	return true;
}
