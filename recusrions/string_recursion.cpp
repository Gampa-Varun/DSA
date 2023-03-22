#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



void substrings(char arr[], vector<char> str, int n, int index){
	
	if(n == index) {
		for (auto i: str){
    		cout << i;

		}
		cout<<endl;
		return;
	}

	else{
		substrings(arr,str,n,index+1);
		str.push_back(arr[index]);
		substrings(arr,str,n,index+1);
	}

	return;

	
}


int main(){
	int n;
	cin>>n;


	char arr[n];

	
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	int index = 0;

	vector<char> str;


	substrings(arr,str,n,index);

	

}