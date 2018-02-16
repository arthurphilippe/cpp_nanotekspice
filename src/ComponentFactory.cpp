/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** ComponentFactory
*/

#include "ComponentFactory.hpp"
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
#include "components/Input.hpp"
#include "components/Output.hpp"
#include "components/False.hpp"
#include "components/True.hpp"
#include "components/Clock.hpp"
#include "Error.hpp"

std::unordered_map<std::string, std::function<std::unique_ptr<nts::IComponent>(
	const std::string &)>> nts::ComponentFactory::_genesisMap;

void nts::ComponentFactory::populateGenesisMap()
{
	_genesisMap["4001"] = nts::ComponentFactory::create4001;
	_genesisMap["4008"] = nts::ComponentFactory::create4008;
	_genesisMap["4011"] = nts::ComponentFactory::create4011;
	_genesisMap["4013"] = nts::ComponentFactory::create4013;
	_genesisMap["4017"] = nts::ComponentFactory::create4017;
	_genesisMap["4030"] = nts::ComponentFactory::create4030;
	_genesisMap["4040"] = nts::ComponentFactory::create4040;
	_genesisMap["4069"] = nts::ComponentFactory::create4069;
	_genesisMap["4071"] = nts::ComponentFactory::create4071;
	_genesisMap["4081"] = nts::ComponentFactory::create4081;
	_genesisMap["4094"] = nts::ComponentFactory::create4094;
	_genesisMap["4514"] = nts::ComponentFactory::create4514;
	_genesisMap["4801"] = nts::ComponentFactory::create4801;
	_genesisMap["input"] = nts::ComponentFactory::createInput;
	_genesisMap["output"] = nts::ComponentFactory::createOutput;
	_genesisMap["clock"] = nts::ComponentFactory::createClock;
	_genesisMap["true"] = nts::ComponentFactory::createTrue;
	_genesisMap["false"] = nts::ComponentFactory::createFalse;
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createComponent(
		const std::string &type,
		const std::string &name,
		const std::string &param)
{
	std::unique_ptr<nts::IComponent> ret;

	if (_genesisMap.size() == 0)
		populateGenesisMap();
	auto it = _genesisMap.find(type);
	if (type.compare("2716") == 0) {
		std::unique_ptr<Ref2716Comp> comp(new Ref2716Comp(name, param));
		ret = std::move(comp);
	} else if (it != _genesisMap.end()) {
		ret = _genesisMap[type](name);
	} else {
		throw FileError("Error : Specified type in the configuration \
file does not exist.");
	}
	return ret;
}


std::unique_ptr<nts::IComponent> nts::ComponentFactory::create2716(
	const std::string &name,
	const std::string &value)
{
	std::unique_ptr<Ref2716Comp> comp(new Ref2716Comp(name, value));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4001(
	const std::string &name)
{
	std::unique_ptr<Ref4001Comp> comp(new Ref4001Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4008(
	const std::string &name)
{
	std::unique_ptr<Ref4008Comp> comp(new Ref4008Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4011(
	const std::string &name)
{
	std::unique_ptr<Ref4011Comp> comp(new Ref4011Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4013(
	const std::string &name)
{
	std::unique_ptr<Ref4013Comp> comp(new Ref4013Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4017(
	const std::string &name)
{
	std::unique_ptr<Ref4017Comp> comp(new Ref4017Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4030(
	const std::string &name)
{
	std::unique_ptr<Ref4030Comp> comp(new Ref4030Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4040(
	const std::string &name)
{
	std::unique_ptr<Ref4040Comp> comp(new Ref4040Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4069(
	const std::string &name)
{
	std::unique_ptr<Ref4069Comp> comp(new Ref4069Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4071(
	const std::string &name)
{
	std::unique_ptr<Ref4071Comp> comp(new Ref4071Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4081(
	const std::string &name)
{
	std::unique_ptr<Ref4081Comp> comp(new Ref4081Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4094(
	const std::string &name)
{
	std::unique_ptr<Ref4094Comp> comp(new Ref4094Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4514(
	const std::string &name)
{
	std::unique_ptr<Ref4514Comp> comp(new Ref4514Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::create4801(
	const std::string &name)
{
	std::unique_ptr<Ref4801Comp> comp(new Ref4801Comp(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createTrue(
	const std::string &name)
{
	std::unique_ptr<True> comp(new True(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createFalse(
	const std::string &name)
{
	std::unique_ptr<False> comp(new False(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createInput(
	const std::string &name)
{
	std::unique_ptr<Input> comp(new Input(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createOutput(
	const std::string &name)
{
	std::unique_ptr<Output> comp(new Output(name));
	return (comp);
}

std::unique_ptr<nts::IComponent> nts::ComponentFactory::createClock(
	const std::string &name)
{
	std::unique_ptr<Clock> comp(new Clock(name));
	return (comp);
}
