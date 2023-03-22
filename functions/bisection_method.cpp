#include<cstdio>
#include <cassert>
#include<cmath>
#include<iostream>

double squarert(double x, double d){
	assert(d>=0);
	return x*x-d;
}

double sin(double x, double d){
	assert(d<1 && d>-1);
	return sin(x) - d;
}

double bisection(double xL, double xR, double epsilon, double (*pf)(double,double), double param){
	//precondition: f(xL),f(xR) have different signs. (>0 and <=0)
	assert(pf(xL,param)*pf(xR,param)<=0);
	bool xL_is_positive = pf(xL,param) > 0;
	//invariant: x_L_is_positive gives the sign of f(x_L).
	//Invariant: f(xL),f(xR) have different signs.

	while(xR-xL>=epsilon){
		double xM = (xL+xR)/2;
		bool xM_is_positive = pf(xM,param) >0;
		if(xL_is_positive == xM_is_positive){
			xL = xM;
		}
		else{
			xR=xM;
		}
	}

	return xL;
}

int main()
{
	double value = 0.5;
	double y = bisection(-1,1,0.0001, sin,value);
	std::cout<<"sin inv of "<<value << " is "<<y<<std::endl;

	return 0;
}