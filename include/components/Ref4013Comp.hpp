/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** comp
*/

#ifndef REF4013COMP_HPP_
	#define REF4013COMP_HPP_

	#include <list>
	#include "DefaultComponent.hpp"

namespace nts {
	class Ref4013Comp : public DefaultComponent {
	public:
		Ref4013Comp(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	private:
		struct TruthStatement {
			Tristate change;
			Tristate d;
			Tristate r;
			Tristate s;
			Tristate q;
		};

		Tristate _previous1;
		Tristate _previous2;
		Tristate _data1;
		Tristate _data2;
		Tristate _currPrev;
		std::list<TruthStatement> _truthTable;
		Tristate flipFlop(Tristate clock, Tristate d,
			Tristate r, Tristate s);
	};
}

#endif /* !REF4013COMP_HPP_ */
