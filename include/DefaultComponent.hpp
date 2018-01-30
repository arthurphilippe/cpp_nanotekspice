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
	#include "IComponent.hpp"

namespace nts {
	class DefaultComponent : public IComponent {
	public:
		void setLink(std::size_t pin, IComponent &other,
					std::size_t otherPin) override;
		void dump() const override;
	protected:
		std::string			_name;
		std::vector<ComponentLink>	_links;
	};
}

#endif /* !DEFAULTCOMPONENT_HPP_ */
