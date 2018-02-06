/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** 4013
*/

#include "components/Ref4013Comp.hpp"
#include "LogicGates.hpp"

// Warning: default values are only the fruit of supposition.
nts::Ref4013Comp::Ref4013Comp(const std::string &name)
	: _prevClock1(FALSE), _prevClock2(FALSE),
	_qnm11(UNDEFINED), _qnm12(UNDEFINED)
{
	_name.assign(name);
}

nts::Tristate nts::Ref4013Comp::flipFlop(Tristate &prevClock, Tristate &qnm1)
{
	nts::Tristate res;

	if (_currR == FALSE && _currS == FALSE) {
		res = dTypeLatch(prevClock, qnm1);
	}
	else {
		res = rsTypeLatch(qnm1);
	}
	return res;
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

nts::Tristate nts::Ref4013Comp::rsTypeLatch(Tristate &qnm1)
{
	if (_currS == FALSE && _currR == TRUE) {
		qnm1 = FALSE;
	}
	else
		qnm1 = TRUE;
	return qnm1;

}

nts::Tristate nts::Ref4013Comp::compute(std::size_t pin)
{
	Tristate &qnm1 = (pin == 1 || pin == 2) ? _qnm11 : _qnm12;
	if (pin == 1 || pin == 2) {
		_currClk = getLinkByPin(3);
		_currR = getLinkByPin(4);
		_currD = getLinkByPin(5);
		_currS = getLinkByPin(6);
	}
	else if (pin == 12 || pin == 13) {
		_currClk = getLinkByPin(11);
		_currR = getLinkByPin(10);
		_currD = getLinkByPin(9);
		_currS = getLinkByPin(8);
	}
	else
		return UNDEFINED;
	if (_currR == TRUE && _currS == TRUE)
		return TRUE;
	auto res = flipFlop(_currClk, qnm1);
	return (pin == 1 || pin == 13) ? res : LogicGates::NOTGate(res);
}
