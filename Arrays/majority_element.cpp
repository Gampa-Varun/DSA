#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int majorityElement(int arr[], int n){
	


	int res = 0;
	int count = 1;

	for (int i = 1; i < n; ++i)
	{
		if(arr[res]==arr[i]){
			count ++;
		}
		else
			count --;
		if(count == 0){
			res = i;
			count = 1;
		}

	}
	count = 0;
	for(int i = 0;i<n;++i){
		if(arr[res]==arr[i]){
			count++;
		}

		if(count>n/2){
			return res;
		}
	}

	return -1;



}


int main(){
	int n;
	cin>>n;


	int arr[n];



	
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		arr[i] = temp;
	}



	int majorityelement;

	majorityelement = majorityElement(arr,n);

	

	cout<<endl;

	cout<<majorityelement;

	cout<<endl;
	

}