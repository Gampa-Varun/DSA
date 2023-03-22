#include<iostream>

using namespace std;


int largest_el(int arr[],int n){
	int maxelement;

	for (int i = 0; i < n; ++i)
	{
		if(i == 0){
			maxelement = arr[i];
		}
		if (arr[i]>maxelement){
			maxelement = arr[i];
		}
	}

	return maxelement;
}

int second_largest_el(int arr[], int n){
	int maxelement;
	int secondlargestElement;
	int res = -1;
	int largest = 0;

	for (int i = 0; i < n; ++i)
	{
		if(i==0){
			maxelement = arr[largest];
			secondlargestElement = arr[largest];
		}
		if(arr[i]>maxelement){
			secondlargestElement = maxelement;
			res = largest;
			maxelement = arr[i];
			largest = i;
		}
		else{
			if(secondlargestElement==maxelement && arr[i]!=maxelement){
				secondlargestElement = arr[i];
				res = i;
			}
			if(arr[i]>secondlargestElement){
				secondlargestElement = arr[i];
				res = i;
			}
		}
	}
	return res;
}


int main(){
	int n;
	cin>>n;

	int arr[n];
	int result;
	
	for (int i = 0; i < n; ++i)
	{
		int temp;
		cin>>temp;
		arr[i] = temp;
	}


	result = second_largest_el(arr,n);

	cout<<endl;

	cout<<result<<endl;
	

}