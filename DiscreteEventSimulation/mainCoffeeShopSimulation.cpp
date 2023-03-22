#include "Resources.h"
#include "simulation.h"
#include <random>
#include <algorithm>

double randuv(int range_from =0, int range_to=100) {
    std::random_device                  rand_dev;
    std::mt19937                        generator(rand_dev());
    std::uniform_int_distribution<int>    distr(range_from, range_to);
    return distr(generator);
}

Resources* minR ( Resources &a, Resources &b){
	if(a.size()< b.size()) return &a;
	else if(a.size() == b.size()){
		if(a.resourceOccupation()<b.resourceOccupation()) return &a;
		else return &b;
	}
	else return &b;
}

int main(int argc, char const *argv[])
{
	const int duration=180;
	double arrivalP = 0.5, eatMin = 3, eatMax = 15;
	int id = 0;
	Resources server("a"), server1("b"), server2("c");
	Resources* serverR;


	for(int t =0;t<duration;t++){
		if(randuv()/100 <= arrivalP){
			id++ ;
			int serviceT = randuv(eatMin,eatMax);
			sim::post(t, [=,&server,&server1,&serverR,&server2](){
				sim::log() << " Customer "<<id<<" arrives, service time:" << serviceT <<std::endl;
				serverR = minR(server1,server);
				serverR = minR(*serverR,server2);
				serverR->acquire([=, &server, &server1,&server2](){
				sim::log() <<" Customer: "<<id <<" being served by "<< serverR->identity()<<" \n";
				sim::post (serviceT, [=](){ 
				sim::log() << " Customer: "<<id <<" finishes being served by "<< serverR->identity()<<" \n"; serverR->release();});
				});

				
			});
		}
	}
	sim::processAll();
	return 0;
}