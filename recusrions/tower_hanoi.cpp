#include<iostream>

using namespace std;

void towerHanoi(int n, char A, char B, char C){

	if(n==1){
		cout<<"move disk "<< n <<" from "<< A <<" to "<<C<<endl;
		return;
		
	}

	else{
		towerHanoi(n-1,A,C,B);
		cout<<"move disk "<<n<< " from " << A<<" to "<< C<<endl;
		towerHanoi(n-1,B,A,C);
		return;
	}
}


int main(){

	int n;
	cin>>n;

	char A,B,C;

	A = 'A';
	B = 'B';
	C = 'C';

	towerHanoi(n,A,B,C);
}