#include<iostream>
#include<vector>

using namespace std;




vector<int> leader(int arr[],int n){

	vector<int> arr_leader;
	int lead_count = 0;
	
	for(int i = 0;i<n;i++){
		if(i == 0){
			arr_leader.push_back(arr[n-i-1]);
			lead_count = 1;
		}
		else{
			if(arr[n-i-1]>arr_leader[lead_count-1]){
				arr_leader.push_back(arr[n-i-1]);
				lead_count = lead_count+1;
			}
		}
	}

	int high = arr_leader.size()-1;
	int low = 0;
	int temp;

	while(high>low){
		temp = arr_leader[low];
		arr_leader[low] = arr_leader[high];
		arr_leader[high] = temp;
		high = high-1;
		low = low +1;
	}

	return arr_leader;


}


int main(){
	int n;
	cin>>n;


	int arr[n];
	vector<int> result;


	
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		arr[i] = temp;
	}


	result = leader(arr,n);

	cout<<endl;

	for (const int& i : result) {
    cout << i << "  ";
  	}

	cout<<endl;
	

}