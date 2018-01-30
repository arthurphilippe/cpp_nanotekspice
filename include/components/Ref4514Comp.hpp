/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4514COMP_HPP_
	#define REF4514COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4514Comp : public DefaultComponent {
	public:
		Ref4514Comp();
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4514COMP_HPP_ */
