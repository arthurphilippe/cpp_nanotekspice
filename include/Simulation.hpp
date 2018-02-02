/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** simulation
*/

#ifndef SIMULATION_HPP_
	#define SIMULATION_HPP_

	#include <sstream>
	#include "DefaultComponent.hpp"

namespace nts {
	class Simulation {
	public:
		Simulation(std::vector<std::unique_ptr<IComponent>> &);
		~Simulation();
		void run();
		void run(std::vector<std::unique_ptr<IComponent>> &);
		void display() const;
		void loop();
		const std::stringstream &getBuffer() const
		{
			return _output;
		}
	private:
		std::vector<std::unique_ptr<IComponent>> *_components;
		std::stringstream	_output;
		void computeOutput(IComponent *comp);
	};
}


#endif /* !SIMULATION_HPP_ */
