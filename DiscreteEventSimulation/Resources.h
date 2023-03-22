#include "simulation.h"
#include <string>

class Resources
{
	typedef std::function<void()> Event;
	std::queue<Event> q;
	bool inUse;
	std::string name;
	int k;
	int counter;
public:
	Resources(std::string s);
	Resources(const Resources &rhs);
	int size();
	std::queue<Event> currentQueue () const;
	bool resourceCheck () const;
	bool reserve ();
	void acquire (Event e);
	std::string identity() const;
	Resources& operator=(const Resources &rhs);

	int resourceOccupation();

	void release();
};