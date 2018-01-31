/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4001COMP_HPP_
	#define REF4001COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4001Comp : public DefaultComponent {
	public:
		Ref4001Comp();
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4001COMP_HPP_ */
