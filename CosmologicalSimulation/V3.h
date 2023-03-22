#include<cmath>
#include<iostream>

class V3
{

private:
	double x,y,z;
public:
	friend std::ostream & operator<< (std::ostream &ost, const V3 &v);
	V3(double p =0, double q =0, double r =0);
	V3 operator+(V3 const &w) const;
	V3 operator*(double t) const;
	V3 operator-(V3 const &w)const;
	double length() const;

};