#include <iostream>

using namespace std;

void heapify(int arr[], int n, int i){
	int largest = i, left = 2*i+1, right = 2*i+2;
	if(left < n){
		if(arr[left]>arr[largest]) largest = left;
	}
	if(right<n){
		if(arr[right]>arr[largest]) largest = right;
	}

	if(largest!=i){
		swap(arr[largest],arr[i]);
		heapify(arr,n,largest);
	}
}

void buildHeap(int arr[], int n){
	for (int i = (n-2)/2; i >= 0; i--)
	{
		heapify(arr,n,i);
	}
}

void heapSort(int arr[], int n){
	buildHeap(arr,n);

	for(int i = n-1; i>=0;i--){
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
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

	heapSort(arr,n);

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}