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

namespace nts {
	class Parser;
	constexpr auto ERR_LINKS("Error in the file links");
	constexpr auto ERR_LINKS_CHIPSET("Error: One chipset isn't linked \
to an pin");
	constexpr auto ERR_SYNTAX("Error: File syntaxt is incorrect");
	constexpr auto ERR_UKN_COMP("Error: linking an unknown component");
	constexpr auto ERR_DUP_DEF("Error: multiple def. of a component");
	constexpr auto ERR_LIST("Error: invalid chipset in list");
	constexpr auto ERR_CMP_ARG("Error: only the 2716 chipset can have \
a value");
	constexpr auto ERR_FILE("Error: cannot open file");
	constexpr auto ERR_SECTION("Error: invaliD section name");

	constexpr auto LINKS_SECT(".links:");
	constexpr auto CHIP_SECT(".chipsets:");
	constexpr auto ROM_COMP("2716");
	constexpr auto TYPE_INPUT("input");
	constexpr auto TYPE_CLOCK("clock");
}

class nts::Parser {
public:
	Parser(const std::string &circuitName, componentList &components);
	~Parser() {}
	void populateList();
	int getInputCount() const noexcept
	{
		return _inputCount;
	}
private:
	enum Mode {
		CHIPSET,
		LINK
	};
	const std::string &_circuitName;
	componentList &_components;
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
	bool _isComponentInList(const std::string &name);
	void _setRom(const std::string &type, std::string name);
};

#endif /* PARSER_HPP_ */
