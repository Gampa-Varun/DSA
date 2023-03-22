#include "simulation.h"
#include <random>


double randuv(int range_from =0, int range_to=100) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>    distr(range_from, range_to);
    return distr(generator);
}

int main(int argc, char const *argv[])
{
	const int nTables = 30;
	const int duration = 180;
	const double arrivalP = 0.1;
	const double eatMin =21, eatMax=40;
	int nOccupied = 0;
	int id = 0;
	int disappointed = 0;
	int emptyTables = nTables;
	int totalCustomer = 0;

	for (int t = 0; t< duration; t++){
		if((randuv(0,1)/100)<=arrivalP){
			id++;
			sim::post(t, [=,&nOccupied,&disappointed, &emptyTables, &totalCustomer](){
				if(nOccupied >=nTables){ sim::log() << " Customer " << id << " disappointed " << std::endl; disappointed++;}
				else {
					nOccupied++;
					totalCustomer++;
					int eatTime = randuv(eatMin,eatMax);
					sim::log()<<" Customer "<< id << " will eat for "<< eatTime << std::endl;
					sim::post(eatTime, [=, &nOccupied](){
						sim::log()<<" Customer "<<id << " finishes "<< std::endl;
						--nOccupied;
						std::cout<< " Number of emptyTables "<< emptyTables - nOccupied << std::endl;
					});
				}
				std::cout<< " Number of emptyTables "<< emptyTables - nOccupied << std::endl;
			});
		}
	}
	sim::processAll();
	std::cout<<"Number of disappointed customers "<< disappointed << std::endl;
	std::cout<<"Number of customers overall "<< totalCustomer << std::endl;

	return 0;
}