#include<iostream>
#include<vector>

using namespace std;




vector<int> leader(int arr[],int n){

	vector<int> arr_leader;
	std::vector<int> arr_leader_index;
	int lead_count = 0;
	
	for(int i = 0;i<n;i++){
		if(i == 0){
			arr_leader.push_back(arr[n-i-1]);
			arr_leader_index.push_back(n-i-1);
			lead_count = 1;
		}
		else{
			if(arr[n-i-1]>arr_leader[lead_count-1]){
				arr_leader.push_back(arr[n-i-1]);
				arr_leader_index.push_back(n-i-1);
				lead_count = lead_count+1;
			}
		}
	}

	int high = arr_leader_index.size()-1;
	int low = 0;
	int temp;

	while(high>low){
		temp = arr_leader_index[low];
		arr_leader_index[low] = arr_leader_index[high];
		arr_leader_index[high] = temp;
		high = high-1;
		low = low +1;
	}



	return arr_leader_index;


}




int max_diff(vector<int> arr_leader, int arr[], int n){
	int lead_count = 0;
	int min_in_lead[arr_leader.size()];
	int min = 10000;
	int traverse =0 ;
	min_in_lead[0] = 0;
	for(int i = 0; i<n;i++){
		if(i<arr_leader[lead_count]){
			if(min>=arr[i]){
				min_in_lead[lead_count] = i;
				min = arr[i];
				traverse=traverse+1;
			}
		}
		else{
			min = arr[i];

			if(traverse==0 && i!=0){
				min_in_lead[lead_count] = i-1;
			}
		

			traverse=0;	
			lead_count = lead_count+1;
		}
	
	}

	

	int max;
	for(int i = 0;i<arr_leader.size();i++){

		if(i ==0 && (arr_leader[i]!=min_in_lead[i])){
			max = arr[arr_leader[i]]-arr[min_in_lead[i]];
		}
		else if(i ==0 && (arr_leader[i] == min_in_lead[i])){
			max = -100000;
		}
		else if((arr[arr_leader[i]]-arr[min_in_lead[i]])>max){
			max = arr[arr_leader[i]]-arr[min_in_lead[i]];
		}
	}

	return max;



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





	int max;

	max = max_diff(result,arr,n);

	

	cout<<endl;

	cout<<max;

	cout<<endl;
	

}