/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** ArgsHandler
*/

#include "ArgsHandler.hpp"
#include <memory>
#include <vector>
#include "Parser.hpp"
#include "Error.hpp"

nts::ArgsHandler::ArgsHandler(int ac, char **av,
					componentList &components, int inputNb)
	: _ac(ac), _av(av), _components(components), _inputCount(inputNb)
{
	_applyArguments();
}

void nts::ArgsHandler::_applyArguments()
{
	int i(2);

	if (_ac < i + 1)
		throw FileError("Error : Please provide inputs's value");
	if (_validateArgsName() == true)
		while (_av[i]) {
			_applyArgument(_av[i]);
			++i;
		}
	for (auto i = _vector.begin(); i != _vector.end(); i++) {
		_validateInputNb(*i);
	}

}

bool nts::ArgsHandler::_validateArgsName()
{
	int tokenIdx;
	int i(2);
	std::string tmp;

	while (_av[i]) {
		tmp = _av[i];
		tokenIdx = tmp.find("=");
		if (tokenIdx < 1)
			throw FileError("Error: Invalid Arguments");
		tmp = tmp.substr(0, tokenIdx);
		_vector.push_back(tmp);
		i++;
	}
	for (auto k = _vector.begin(); k != _vector.end(); k += 1) {
		if (count(_vector.begin(), _vector.end(), *k) != 1)
			throw FileError("Error : Check the argument \
there are multiple definitions of an input!");
	}
	return (true);
}

void nts::ArgsHandler::_applyArgument(std::string arg)
{
	std::string chipset;
	std::string value;
	int tokenPlace;

	tokenPlace = arg.find("=");
	chipset = arg.substr(0, tokenPlace);
	value = arg.substr(tokenPlace + 1, arg.length());
	if (value.compare("1") != 0 && value.compare("0") != 0)
		throw FileError("Error: Arguments: invalid input value");
	if (_isComponentInList(chipset)) {
		auto &tmp = _getComponent(chipset);
		if (value == "0")
			tmp->compute(3);
		else
			tmp->compute(2);
	} else {
		throw FileError("Error: Arguments: invalid input name");
	}
}

bool nts::ArgsHandler::_isComponentInList(const std::string &name)
const noexcept
{
	bool found = false;

	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == name)
			found = true;
	}
	return found;
}

std::unique_ptr<nts::IComponent> &nts::ArgsHandler::_getComponent(
	const std::string &name) const noexcept
{
	for (auto i = _components.begin(); i != _components.end(); i++) {
		if ((*i)->getName() == name)
			return *i;
	}
	return *(_components.begin());
}

bool nts::ArgsHandler::_validateInputNb(const std::string &name)
{
	for (auto i = _vector.begin(); i != _vector.end(); i += 1) {
		if (*i == name) {
			if (!_getComponent(name)->getType().compare("input") ||
				!_getComponent(name)->getType().compare("clock")) {
				_inputCount -= 1;
				return true;
			}
		}
	}
	throw FileError("Error: Arguments: input count wasn't met");
}
