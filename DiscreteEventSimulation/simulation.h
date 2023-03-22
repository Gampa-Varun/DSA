#include <queue>
#include <iostream>
#include <functional>
#include <utility>
#include <vector>

#ifndef SIMULATION_H
#define SIMULATION_H

class sim
{
	typedef std::function<void()> Event;
	typedef std::pair<Event,double> ETpair;
	struct compareETpair{
		bool operator()(ETpair p, ETpair q){ return p.second > q.second;}
	};

	static double time;
	static std::priority_queue< ETpair, std::vector<ETpair>, compareETpair> pq;
public:
	static void post (double latency, Event e);

	static double getTime();
	static void processAll (double tmax=1000);

	static std::ostream & log();
	
};

#endif