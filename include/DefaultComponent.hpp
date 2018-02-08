/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef DEFAULTCOMPONENT_HPP_
	#define DEFAULTCOMPONENT_HPP_

	#include <vector>
	#include <string>
	#include <memory>
	#include <unordered_map>
	#include <functional>
	#include "IComponent.hpp"

namespace nts {
	class DefaultComponent : public IComponent {
	public:
		virtual ~DefaultComponent() {};
		void setLink(std::size_t pin, IComponent &other,
				std::size_t otherPin) override;
		void dump() const override;
		static std::unique_ptr<IComponent> createComponent(
			const std::string &type,
			const std::string &value = "",
			const std::string &param = "");
		const std::string &getName() const override;
		const std::string &getType() const override;
		nts::Tristate getLinkByPin(size_t pin) override;
		virtual bool isValid() const override;
	protected:
		std::string			_name;
		std::string			_type;
		std::vector<ComponentLink>	_links;
	private:
		static std::unordered_map<std::string,
			std::function<std::unique_ptr<IComponent>(
				const std::string &)>> _genesisMap;
		static void populateGenesisMap();
		static std::unique_ptr<IComponent> create2716(
			const std::string &name,
			const std::string &value);
		static std::unique_ptr<IComponent> create4001(
			const std::string &name);
		static std::unique_ptr<IComponent> create4008(
			const std::string &name);
		static std::unique_ptr<IComponent> create4011(
			const std::string &name);
		static std::unique_ptr<IComponent> create4013(
			const std::string &name);
		static std::unique_ptr<IComponent> create4017(
			const std::string &name);
		static std::unique_ptr<IComponent> create4030(
			const std::string &name);
		static std::unique_ptr<IComponent> create4040(
			const std::string &name);
		static std::unique_ptr<IComponent> create4069(
			const std::string &name);
		static std::unique_ptr<IComponent> create4071(
			const std::string &name);
		static std::unique_ptr<IComponent> create4081(
			const std::string &name);
		static std::unique_ptr<IComponent> create4094(
			const std::string &name);
		static std::unique_ptr<IComponent> create4514(
			const std::string &name);
		static std::unique_ptr<IComponent> create4801(
			const std::string &name);
		static std::unique_ptr<IComponent> createTrue(
			const std::string &name);
		static std::unique_ptr<IComponent> createFalse(
			const std::string &name);
		static std::unique_ptr<IComponent> createInput(
			const std::string &name);
		static std::unique_ptr<IComponent> createOutput(
			const std::string &name);
		static std::unique_ptr<IComponent> createClock(
			const std::string &name);

	};
}

#endif /* !DEFAULTCOMPONENT_HPP_ */
