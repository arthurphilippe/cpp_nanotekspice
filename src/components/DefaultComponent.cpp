/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** default
*/

#include <iostream>
#include "DefaultComponent.hpp"
#include "components/Ref2716Comp.hpp"
#include "components/Ref4001Comp.hpp"
#include "components/Ref4008Comp.hpp"
#include "components/Ref4011Comp.hpp"
#include "components/Ref4013Comp.hpp"
#include "components/Ref4017Comp.hpp"
#include "components/Ref4030Comp.hpp"
#include "components/Ref4040Comp.hpp"
#include "components/Ref4069Comp.hpp"
#include "components/Ref4071Comp.hpp"
#include "components/Ref4081Comp.hpp"
#include "components/Ref4094Comp.hpp"
#include "components/Ref4514Comp.hpp"
#include "components/Ref4801Comp.hpp"


void nts::DefaultComponent::dump() const
{
	std::cout << "dump is not yet implemented" << std::endl;
}

void nts::DefaultComponent::setLink(std::size_t pin, IComponent &other,
					std::size_t otherPin)
{
	ComponentLink	newLink = {other, otherPin, pin};

	_links.push_back(newLink);
}

std::unique_ptr<nts::IComponent> nts::DefaultComponent::createComponent(
	const std::string &type, const std::string &value)
{
	std::unique_ptr<nts::IComponent> ret;

	if (type == "4001")
		[&ret] () {
			std::unique_ptr<Ref4001Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4008")
		[&ret] () {
			std::unique_ptr<Ref4008Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4011")
		[&ret] () {
			std::unique_ptr<Ref4011Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4013")
		[&ret] () {
			std::unique_ptr<Ref4013Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4017")
		[&ret] () {
			std::unique_ptr<Ref4017Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4030")
		[&ret] () {
			std::unique_ptr<Ref4030Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4040")
		[&ret] () {
			std::unique_ptr<Ref4040Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4069")
		[&ret] () {
			std::unique_ptr<Ref4069Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4071")
		[&ret] () {
			std::unique_ptr<Ref4071Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4081")
		[&ret] () {
			std::unique_ptr<Ref4081Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4094")
		[&ret] () {
			std::unique_ptr<Ref4094Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4514")
		[&ret] () {
			std::unique_ptr<Ref4514Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "4801")
		[&ret] () {
			std::unique_ptr<Ref4801Comp> comp;
			ret = std::move(comp);
		};
	else if (type == "2716")
		[&ret] () {
			std::unique_ptr<Ref2716Comp> comp;
			ret = std::move(comp);
		};
	return ret;
}

const std::string &nts::DefaultComponent::getName() const
{
	return _name;
}
