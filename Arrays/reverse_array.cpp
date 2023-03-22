#include<iostream>

using namespace std;




int* reverse_array(int arr[],int n){

	if(n%2 == 0){
		for(int i =0;i<n/2;i++){
			swap(arr[i],arr[n-i-1]);
		}
	}

	else{
		for(int i=0;i<(n-1)/2;i++){
			swap(arr[i],arr[n-i-1]);
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


	result = reverse_array(arr,n);

	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<result[i]<<",";
	}

	cout<<endl;
	

}