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
	using componentList = std::vector<std::unique_ptr<IComponent>>;

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
	};
}

#endif /* !DEFAULTCOMPONENT_HPP_ */
