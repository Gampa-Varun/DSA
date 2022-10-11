#include<iostream>

using namespace std;


int* deleteop(int arr[],int n , int val){
	int i;
	for(i=0;i<n;++i){
		if(val==arr[i]){
			break;
		}
	}
	if(i==n){
		arr[i-1]=0;
		return arr;
	}
	for(int j =i;j<n-1;j++){
		arr[j] = arr[j+1];
	}
	arr[n-1] = 0;
	return arr;
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

	int val;

	cin>>val;

	int *result;

	result = deleteop(arr,n,val);

	cout<<endl;

	for (int i = 0; i < n; ++i)
	{
		cout<<result[i]<<endl;
	}
	

}