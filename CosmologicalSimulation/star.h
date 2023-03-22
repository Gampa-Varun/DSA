#include "V3.h"
#include <cmath>


class Star
{
private:
	double mass;
	V3 r,v;
public:
	friend std::ostream & operator<< (std::ostream &ost, const Star &st);
	Star(){};
	void init(double m, V3 position, V3 velocity);
	void vStep(double dT, V3 f);
	void rStep(double dT);
	V3 forceOf(Star &s);
};