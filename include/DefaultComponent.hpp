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
	#include "IComponent.hpp"

namespace nts {
	class DefaultComponent : public IComponent {
	public:
		virtual ~DefaultComponent() {};
		virtual Tristate compute(std::size_t pin = 1) = 0;
		void setLink(std::size_t pin, IComponent &other,
				std::size_t otherPin) override;
		void dump() const override;
		static std::unique_ptr<IComponent> createComponent(
			const std::string &type,
			const std::string &value = "",
			const std::string &param = "");
		const std::string &getName() const override;
	protected:
		std::string			_name;
		std::vector<ComponentLink>	_links;
	};
}

#endif /* !DEFAULTCOMPONENT_HPP_ */
