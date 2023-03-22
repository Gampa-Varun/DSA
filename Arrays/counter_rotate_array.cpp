#include<iostream>

using namespace std;




int* counter_array(int arr[],int n,int d){

	int arr_temp[n];

	for(int i = 0;i<n;i++){
		if(i<d){
			arr_temp[i] = arr[i];
		}
		else{
			arr[i-d] = arr[i];
		}
	}
	for(int i = 0;i<d;i++){
		arr[n-i-1] = arr_temp[d-i-1];
	}
	return arr;
}


int main(){
	int n,d;
	cin>>n;
	cin>>d;

	int arr[n];
	int* result;


	
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		arr[i] = temp;
	}


	result = counter_array(arr,n,d);

	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<result[i]<<",";
	}

	cout<<endl;
	

}