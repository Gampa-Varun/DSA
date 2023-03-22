#include <iostream>

using namespace std;

void swap( int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
	return;
}


int partition(int arr[], int l, int h){
	//Hoover's method will be used.
	//swap(arr[l],arr[p]);
	int pivot = arr[l]; 
	int i = l-1;
	int j = h+1;

	while(true){
		do{
			i++;
		}while(arr[i]<pivot);

		do{
			j--;
		}while(arr[j]>pivot);
		if(j<=i){
			return j;
		}
		swap(arr[i],arr[j]);
	}
}

void quicksort(int arr[], int l, int h){

	if(l<h){
	int p = partition(arr, l, h);
	swap(arr[h],arr[p+1]);
	quicksort(arr,  l,  p-1);
	quicksort(arr, p+1,h);
	}
	else{
		return;
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

	quicksort(arr,0,n-1);

	for (int i = 0; i < n; ++i)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
	return 0;
}