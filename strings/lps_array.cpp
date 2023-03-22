#include <iostream>
#include <string>
using namespace std;

void swap( int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	return;
}

int* filllps(string s, int lps[]){

	int n = s.length();
	int len = 0;

	
	lps[0] = 0;


	int i = 1;

	while(i<n){
		if(s[i] == s[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else{
			if(len == 0){
				lps[i] = 0;
				i++;
			}
			else{
				len = lps[len-1];
			}

		}
	}

	return lps;

}


int main(int argc, char const *argv[])
{
	string s;
	int n;
	cin>>s;
	n = s.length();

	int *arr = new int[n];

	arr = filllps(s,arr);
	for(int i = 0;i<n;i++){
		cout<<arr[i]<<" " ;
	}
	return 0;
}