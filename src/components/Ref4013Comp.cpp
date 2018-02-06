/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4013
*/

#include "components/Ref4013Comp.hpp"

// Warning: default values are only the fruit of supposition.
nts::Ref4013Comp::Ref4013Comp(const std::string &name)
	: _prevClock1(FALSE), _prevClock2(FALSE),
	_qnm11(UNDEFINED), _qnm12(UNDEFINED)
{
	_name.assign(name);
	_truthTable.push_back({TRUE, FALSE, FALSE, TRUE, FALSE});
	_truthTable.push_back({TRUE, TRUE, FALSE, FALSE, TRUE});
	_truthTable.push_back({FALSE, UNDEFINED, FALSE, FALSE, UNDEFINED});
	_truthTable.push_back({UNDEFINED, UNDEFINED, TRUE, FALSE, TRUE});
	_truthTable.push_back({UNDEFINED, UNDEFINED, FALSE, TRUE, FALSE});
	_truthTable.push_back({UNDEFINED, UNDEFINED, TRUE, TRUE, TRUE});
}

nts::Tristate nts::Ref4013Comp::flipFlop(Tristate &prevClock, Tristate &qnm1)
{
	auto it = _truthTable.begin();

	if (_currR == FALSE && _currS == FALSE) {
		dTypeLatch(prevClock, qnm1);
	}
	else {
		// RS-type latch
	}
}

nts::Tristate nts::Ref4013Comp::dTypeLatch(Tristate &prevClock, Tristate &qnm1)
{
	if (prevClock == FALSE && _currClk == FALSE) {
		return qnm1;
	}
	else if (prevClock == FALSE && _currClk == TRUE) {
		prevClock = TRUE;
		qnm1 = _currD;
	}
	else
		prevClock = FALSE;
	return qnm1;
}

nts::Tristate nts::Ref4013Comp::compute(std::size_t pin)
{
	(void) pin; return TRUE;
}
