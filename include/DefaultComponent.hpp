/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef DEFAULTCOMPONENT_HPP_
	#define DEFAULTCOMPONENT_HPP_

	#include <vector>
	#include "IComponent.hpp"

namespace nts {
	class DefaultComponent : public IComponent {
	public:
		virtual Tristate compute(std::size_t pint = 1) = 0;
		virtual void setLink(std::size_t pin, IComponent &other,
					std::size_t otherPin) override;
		virtual void dump() const override;
	protected:
		std::vector<ComponentLink>	_links;
	};
}

#endif /* !DEFAULTCOMPONENT_HPP_ */
