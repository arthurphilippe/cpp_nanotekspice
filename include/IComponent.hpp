/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** component interface
*/

#ifndef ICOMPONENT_HPP_
	#define ICOMPONENT_HPP_

	#include <cstddef>
	#include <string>

namespace nts {
	enum Tristate {
		UNDEFINED = (-true),
		TRUE = true,
		FALSE = false
	};

	class IComponent {
	public:
		virtual ~IComponent() = default;
		virtual Tristate compute(std::size_t pin = 1) = 0;
		virtual void setLink(std::size_t pin, IComponent &other,
					std::size_t otherPin) = 0;
		virtual void dump() const = 0;
		virtual const std::string &getName() const = 0;
	protected:
	private:
	};
}


#endif /* !ICOMPONENT_HPP_ */
