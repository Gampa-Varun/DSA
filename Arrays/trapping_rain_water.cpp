#include<iostream>
#include<vector>

using namespace std;





int trap_water(int arr[], int n){
	
	int max_profit = 0;
	int max_profit_temp = 0;
	bool start_down=false;
	bool start_up = false;
	int traverse = 0;

	int max_height = 0;

	for(int i =1;i<n;i++){
		if(arr[i]<arr[i-1] && !start_down){
			start_down = true;
			max_height = arr[i-1];
			traverse = traverse+1;
			max_profit_temp = max_height - arr[i];
		}

		else if(arr[i]<arr[i-1] && start_down){
			traverse = traverse+1;
			max_profit_temp = max_height - arr[i];
		}

		else if(arr[i]>arr[i-1]&& start_down && arr[i]<=max_height){
			traverse = traverse+1;
			start_up = true;
			max_profit_temp = max_profit_temp+ max_height-arr[i];
		}

		if(start_up && arr[i]>max_height){
			start_down = false;
			start_up = false;
			traverse = 0;
			max_profit = max_profit_temp + max_profit;
			max_profit_temp = 0;
		}

		if((arr[i]<arr[i-1]) && start_up){
			start_up = false;
			start_down = false;
			max_profit_temp = max_profit_temp - (traverse+1)*(max_height-arr[i-1]);
			max_profit = max_profit+max_profit_temp;
			max_profit_temp =  0;
			i = i-1;

		}

		if(( i== n-1) && start_up){
			start_up = false;
			start_down = false;
			max_profit_temp = max_profit_temp - (traverse)*(max_height-arr[i]);
			max_profit = max_profit+max_profit_temp;
			max_profit_temp =  0;
			i = i-1;

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

	max = trap_water(arr,n);

	

	cout<<endl;

	cout<<max;

	cout<<endl;
	

}