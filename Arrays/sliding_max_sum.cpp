#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int maxsumslide(int arr[], int n, int d){
	
	int sum = 0;
	


	for (int i = 0; i < d; ++i)
	{
		sum = sum+ arr[i];
	}

	int maxsum = sum;

	for (int i = d; i < n; ++i)
	{
		sum = sum+arr[i] - arr[i-d];
		maxsum = max(maxsum,sum);
	}


	return maxsum;

	
}


int main(){
	int n;
	cin>>n;


	int arr[n];
	int result;



	
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		arr[i] = temp;
	}


	int d ;
	cin>>d;


	result = maxsumslide(arr,n,d);

	

	cout<<endl;


	cout<<result<<" ";


	cout<<endl;
	

}