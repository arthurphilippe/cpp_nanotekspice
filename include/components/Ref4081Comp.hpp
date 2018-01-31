/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4081COMP_HPP_
	#define REF4081COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4081Comp : public DefaultComponent {
	public:
		Ref4081Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF4081COMP_HPP_ */
