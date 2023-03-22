#include <iostream>
#include <cmath>
using namespace std;

void countingSort( int arr[], int n, int exp){
	int count[10];
	int output[n];
	for(int i = 0;i<10;i++){
		count[i] = 0;
	}

	for(int i = 0; i<n;i++){
		count[int(arr[i]/(pow(10,exp-1)))%10]++;
	}
	for(int i = 1;i<10;i++){
		count[i] = count[i] + count[i-1]; 
	}

	for(int i = n-1;i>=0;i--){
		output[count[int(arr[i]/pow(10,exp-1))%10]-1] = arr[i];
		count[int(arr[i]/pow(10,exp-1))%10]--;
	}
	for (int i = 0; i < n; ++i)
	{
		arr[i] = output[i];
	}

}

void radixSort(int arr[], int n){
	int max = 0;
	for (int i = 0; i < n; ++i)
	{
		if(arr[i]>max){
			max = arr[i];
		}
	}
	int exp = 1;
	while(int(max/pow(10,exp))>0){
		exp ++;
	}
	

	for(int i = 0;i<exp;i++){
		countingSort(arr, n, exp);
	}
}

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int arr[n];

	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
	}

	//partition(arr,0,n-1,1);

	radixSort(arr,n);

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}