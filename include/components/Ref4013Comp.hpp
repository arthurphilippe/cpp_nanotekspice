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

		Tristate _prevClock1;
		Tristate _prevClock2;

		Tristate _qnm11;
		Tristate _qnm12;

		std::list<TruthStatement> _truthTable;

		Tristate _currClk;
		Tristate _currD;
		Tristate _currR;
		Tristate _currS;

		Tristate _q;
		Tristate flipFlop(Tristate &prevClock, Tristate &qnm1);
		Tristate dTypeLatch(Tristate &prevClock, Tristate &qnm1);
		Tristate rsTypeLatch(Tristate &qnm1);
	};
}

#endif /* !REF4013COMP_HPP_ */
