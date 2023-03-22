#include "star.h"


void Star::init(double m, V3 r1, V3 v1){
	mass = m;
	r = r1;
	v = v1;
}

void Star::vStep(double dT, V3 f){
	v = v+ f*(dT/mass);
}

void Star::rStep(double dT){
	r = r + v*dT;
}

V3 Star::forceOf(Star &s){
	V3 R = s.r - r;
	return R*(mass*s.mass/pow(R.length(),3));
}

std::ostream & operator<< (std::ostream &ost, const Star &st){
	ost<< st.r<<std::endl;
	return ost;
}