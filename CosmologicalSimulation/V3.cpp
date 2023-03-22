#include "V3.h"

V3::V3(double p, double q, double r){
	x = p; y =q; z=r;
}

V3 V3::operator+(V3 const &w)const{
	return V3(x+w.x,y+w.y,z+w.z);
}

V3 V3::operator-(V3 const &w)const{
	return V3(x-w.x,y-w.y,z-w.z);
}

V3 V3::operator*(double t)const {
	return V3(x*t,y*t,z*t);
}

double V3::length() const{
	return sqrt(x*x+y*y+z*z);
}

std::ostream & operator<< (std::ostream &ost, const V3 &v){
	ost<< v.x <<' '<<v.y<<' '<<v.z<<' '<<std::endl;
	return ost;
}