#include "simulation.h"




void sim::post (double latency, Event e){ 
	pq.push(make_pair(e, time + latency));
}

double sim::getTime(){return time;}
void sim::processAll (double tmax){
	while(!pq.empty() && time <tmax){
		ETpair ETp = pq.top();
		time = ETp.second;
		pq.pop();
		ETp.first();
	}
}

std::ostream & sim::log(){
	std::cout << time << " ) ";
	return std::cout;
}

double sim::time = 0;
std::priority_queue< sim::ETpair, std::vector<sim::ETpair>, sim:: compareETpair> sim::pq;
