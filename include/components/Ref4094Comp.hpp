/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4094COMP_HPP_
	#define REF4094COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4094Comp : public DefaultComponent {
	public:
		Ref4094Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4094COMP_HPP_ */
