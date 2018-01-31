/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4071COMP_HPP_
	#define REF4071COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4071Comp : public DefaultComponent {
	public:
		Ref4071Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4071COMP_HPP_ */
