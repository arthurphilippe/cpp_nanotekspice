/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** component interface
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

	#include <cstddef>

namespace nts {
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent {
	public:
		virtual ~IComponent() = default;
		virtual nts::Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin, nts::IComponent &other,
					std::size_t otherPin) = 0;
		virtual void dump() const = 0;
	protected:
		std::list<IComponent> _list;
	private:
	};
}


#endif /* !ICOMPONENT_HPP_ */
