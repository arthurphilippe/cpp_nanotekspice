/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF2716COMP_HPP_
	#define REF2716COMP_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class Ref2716Comp : public DefaultComponent {
	public:
		Ref2716Comp(const std::string &name, const std::string &param);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}

#endif /* !REF2716COMP_HPP_ */
