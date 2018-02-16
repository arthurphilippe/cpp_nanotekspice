/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** simulation
*/

#ifndef SIMULATION_HPP_
	#define SIMULATION_HPP_

	#include <list>
	#include <sstream>
	#include "DefaultComponent.hpp"

namespace nts {
	class Simulation {
	public:
		Simulation(std::list<std::unique_ptr<IComponent>> &);
		~Simulation();
		void run();
		void run(std::list<std::unique_ptr<IComponent>> &);
		void display();
		void loop();
		void printSortedOutput();
		const std::stringstream &getBuffer() const
		{
			return _output;
		}
	private:
		static bool sortFunctor(const std::string &a,
					const std::string &b);
		std::list<std::unique_ptr<IComponent>> *_components;
		std::stringstream _output;
		void computeOutput(std::unique_ptr<IComponent> &comp);
	};
}


#endif /* !SIMULATION_HPP_ */
