#include<iostream>
#include<vector>

using namespace std;





int max_profit(int arr[], int n){
	
	int max_profit = 0;

	for(int i =1;i<n;i++){
		if (arr[i]>arr[i-1]){

			max_profit = max_profit + arr[i] - arr[i-1];
		}
	}

	return max_profit;



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



	int max;

	max = max_profit(arr,n);

	

	cout<<endl;

	cout<<max;

	cout<<endl;
	

}