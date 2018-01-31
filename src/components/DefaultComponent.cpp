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

	if (type.compare("4001") == 0) {
		std::cout << "kappa" << std::endl;
		std::unique_ptr<Ref4001Comp> comp(new Ref4001Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4008") == 0) {
		std::unique_ptr<Ref4008Comp> comp(new Ref4008Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4011") == 0) {
		std::unique_ptr<Ref4011Comp> comp(new Ref4011Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4013") == 0) {
		std::unique_ptr<Ref4013Comp> comp(new Ref4013Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4017") == 0) {
		std::unique_ptr<Ref4017Comp> comp(new Ref4017Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4030") == 0) {
		std::unique_ptr<Ref4030Comp> comp(new Ref4030Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4040") == 0) {
		std::unique_ptr<Ref4040Comp> comp(new Ref4040Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4069") == 0) {
		std::unique_ptr<Ref4069Comp> comp(new Ref4069Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4071") == 0) {
		std::unique_ptr<Ref4071Comp> comp(new Ref4071Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4081") == 0) {
		std::unique_ptr<Ref4081Comp> comp(new Ref4081Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4094") == 0) {
		std::unique_ptr<Ref4094Comp> comp(new Ref4094Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4514") == 0) {
		std::unique_ptr<Ref4514Comp> comp(new Ref4514Comp);
		ret = std::move(comp);
	}
	else if (type.compare("4801") == 0) {
		std::unique_ptr<Ref4801Comp> comp(new Ref4801Comp);
		ret = std::move(comp);
	}
	else if (type.compare("2716") == 0) {
		std::unique_ptr<Ref2716Comp> comp(new Ref2716Comp);
		ret = std::move(comp);
	}
	return ret;
}

const std::string &nts::DefaultComponent::getName() const
{
	return _name;
}
