#include<iostream>

using namespace std;


int* move_zero(int arr[],int n){
	int movcount,zero_count;
	zero_count = 0;
	movcount = 0;

	for (int i = 0; i < n; ++i)
	{
		if(arr[i]==0){
			movcount = movcount + 1;
			zero_count = zero_count+1;
		}
		if(arr[i]!=0 && movcount > 0){
			arr[i-movcount] = arr[i];
		}
	}

	if (movcount>0){
		for (int i = 0;i<movcount;i++){
			arr[n-i-1] = 0; 
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


	result = move_zero(arr,n);

	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<result[i]<<",";
	}

	cout<<endl;
	

}