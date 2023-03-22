#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int* minFlips(int arr[], int n){
	

	int count0 = 0;
	int count1 = 0;

	bool count1start = false;
	bool count0start = false;

	for(int i = 0;i<n;i++){

		if(arr[i]==0 && !count0start){
			count0++;
			count0start = true;
			count1start = false;
		}

		else if(arr[i] == 0 && count0start){
			continue;
		}

		else if(arr[i] == 1 && !count1start){
			count1++;
			count0start = false;
			count1start = true;
		}

		else if(arr[i] == 1 && count1start){
			continue;
		}
	}

	if(count0 == 0 || count1 ==0){
		return arr;
	}

	if(count1>count0){

		cout<<count0<<endl;

		for(int i = 0;i<n;i++){
			if(arr[i] == 0){
				arr[i] = 1;
			}
		}
	}

	else{
		cout<<count1<<endl;
		for(int i = 0;i<n;i++){
			if(arr[i] == 1){
				arr[i] = 0;
			}
		}
	}

return arr;

}


int main(){
	int n;
	cin>>n;


	int arr[n];
	int* result;



	
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		arr[i] = temp;
	}




	result = minFlips(arr,n);

	

	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<result[i]<<" ";
	}

	cout<<endl;
	

}