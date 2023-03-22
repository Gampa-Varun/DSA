#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int max_sub_array(int arr[], int n){
	


	int res = 0;
	int curr = 1;

	for (int i = 1; i < n; ++i)
	{
		if((arr[i]%2 == 0 && arr[i-1] %2 == 1)||(arr[i]%2 == 1 && arr[i-1] %2 == 0)){
			curr = curr+1;
			res = max(res,curr);
		}
		else curr = 1;

	}

	return res;



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



	int max;

	max = max_sub_array(arr,n);

	

	cout<<endl;

	cout<<max;

	cout<<endl;
	

}