/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** ArgsHandler
*/

#ifndef ARGSHANDLER_HPP_
	#define ARGSHANDLER_HPP_

	#include <vector>
	#include <memory>
	#include "DefaultComponent.hpp"
	#include "IComponent.hpp"


namespace nts {
	class ArgsHandler;
}

class nts::ArgsHandler {
public:
	ArgsHandler(int ac, char **av, componentList &components, int inputNb);
	void _applyArgument(std::string arg);
private:
	int _ac;
	char **_av;
	componentList &_components;
	int _inputCount;
	std::vector<std::string> _vector;
	void _applyArguments();
	bool _validateArgsName();
	bool _isComponentInList(const std::string &name);
	std::unique_ptr<nts::IComponent> &_getComponent(
		const std::string &name);
	bool _validateInputNb(const std::string &name);
};

#endif /* !ARGSHANDLER_HPP_ */
