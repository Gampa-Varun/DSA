#include <iostream>
#include "star.h"

using namespace std;


void read_star_data(Star stars[], int n){
	float mass, vx, vy, vz, x, y, z;
	for(int i =0;i<n;i++){
		cout<< "Enter the mass, position (in x y z coordinates) and velocity (in vx, vy , vz coordinates) "<<endl;
		cin >> mass >> x >> y >> z >> vx >> vy >> vz;
		stars[i].init(mass, V3(x,y,z), V3(vx,vy,vz));
	}
}

void calculate_net_force(int n, Star stars[], V3 forces[]){
	for(int i =0; i<n;i++){
		forces[i] = V3(0,0,0);
	}

	for(int i =0;i<n;i++){
		for(int j=i+1; j<n;j++){
			V3 f = stars[i].forceOf(stars[j]);
			forces[i] = forces[i] + f;
			forces[j] = forces[j] -f;	
		}
	}
}

int main(int argc, char const *argv[])
{
	double T, delta;
	cout<<"Enter simulation time and time interval "<<endl;
	cin >> T >> delta;
	int n;
	cout<<" Enter the number of stars "<<endl;
	cin>>n;
	Star stars[n];
	read_star_data(stars,n);

	V3 forces[n];

	calculate_net_force (n,stars,forces);
	for (int i = 0; i < n; ++i)
	{
		stars[i].vStep(delta/2,forces[i]);
	}

	for (float t = 0; t < T; t+=delta)
	{
		cout<< "time: "<<t<<endl;
		for(int i = 0;i<n;i++){
			stars[i].rStep(delta);
			cout<< "star "<< i << " : "<< stars[i] <<endl;
		}
		calculate_net_force(n,stars,forces);
		for (int i = 0; i < n; ++i)
		{
			stars[i].vStep(delta,forces[i]);
		}
	}
	return 0;
}