/*
** EPITECH PROJECT, 2017
** nanotekspice
** File description:
** true
*/

#ifndef TRUE_HPP_
	#define TRUE_HPP_

	#include "DefaultComponent.hpp"

namespace nts {
	class True : public DefaultComponent {
	public:
		True(const std::string &name);
		virtual Tristate compute(std::size_t pin = 1) override;
	protected:
	private:
	};
}
#endif /* !TRUE_HPP_ */
