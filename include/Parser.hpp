/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** Readfile
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

	#include <vector>
	#include <memory>
	#include "DefaultComponent.hpp"
	#include "IComponent.hpp"
	#include "Circuit.hpp"

namespace nts {
	class Parser;
}

class nts::Parser {
public:
	Parser(const std::string &circuitName, Circuit &circuit);
	~Parser() {}
	void populateList();
	int getInputCount() const noexcept
	{
		return _inputCount;
	}
private:
	// TODO: rename those two
	enum Mode {
		CHIPSET,
		LINK
	};
	const std::string &_circuitName;
	componentList &_components;
	Circuit &_circuit;
	int _inputCount;
	Mode _currMode;
	void _updateMode(const std::string &line);
	bool _isModeTitleLine(const std::string &line);
	void _parseLine(const std::string &line);
	void _setChipset(const std::string &type, const std::string &name);
	void _parseLink(const std::string &a, const std::string &b);
	void _setLink(const std::string &a, const int &a_value,
			const std::string &b, const int &b_value);
	std::unique_ptr<nts::IComponent> &_getComponent(
		const std::string &name);
	void _setRom(const std::string &type, std::string name);
};

#endif /* PARSER_HPP_ */
