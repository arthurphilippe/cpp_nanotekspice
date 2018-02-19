/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** simulation
*/

#ifndef SIMULATION_HPP_
	#define SIMULATION_HPP_

	#include <vector>
	#include <sstream>
	#include "DefaultComponent.hpp"

namespace nts {
	class Simulation {
	public:
		Simulation(std::vector<std::unique_ptr<IComponent>> &);
		~Simulation();
		void run();
		void display();
		void loop();
		void printSortedOutput();
		const std::stringstream &getBuffer() const
		{
			return _output;
		}
		static void sigIntHandler(int);
	private:
		static bool sortFunctor(const std::string &a,
					const std::string &b);
		std::vector<std::unique_ptr<IComponent>> &_components;
		std::stringstream _output;
		void computeOutput(std::unique_ptr<IComponent> &comp);
		static bool _intSignalRecieved;
	};
}


#endif /* !SIMULATION_HPP_ */
