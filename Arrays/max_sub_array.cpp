#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;





int max_sub_array(int arr[], int n){
	/*vector<int> positive_ind;
	std::vector<int> max_sums;
	int j = 0;
	int max_sub_sum = 0;
	bool cont = false;
	bool neg_cont = false;

	for(int i  = 0;i<n;i++){
		if(arr[i]>0){
			positive_ind.push_back(i);
		}
	}

	if(positive_ind.size()>0){
		for(int i =0;i<n;i++){
			if(arr[i]>0 && neg_cont){
				//cout<<arr[i]<<endl;
				if(max_sub_sum>0){
					cont =true;
				}
				max_sub_sum = max_sub_sum + arr[i];
				max_sums.push_back(max_sub_sum);
		
				neg_cont = false;

				if(cont){
					i=i+1;	
				}
				
			}

			if(arr[i]>0 && !cont){
				max_sub_sum = arr[i];
				max_sums.push_back(arr[i]);
				j=j+1;
				cont = true;

			}
			else if(arr[i]>0 && cont){
				max_sums.back() = max_sums.back() + arr[i];
				max_sub_sum = max_sums.back();
			
				j= j+1;
			}
			else if(arr[i]<=0 && (!neg_cont)){
				max_sub_sum = max_sub_sum + arr[i];
		
				cont = false;
				neg_cont = true;
			}

			else if(arr[i]<0 && neg_cont){
				max_sub_sum = max_sub_sum + arr[i];
			}
			


			
		}
		max_sub_sum = *std::max_element(max_sums.begin(),max_sums.end());
	}
	else{
		max_sub_sum = *max_element(arr,arr+n);
	}

	

	return max_sub_sum;*/


	int res = arr[0];
	int maxEnding = arr[0];

	for (int i = 1; i < n; ++i)
	{
		maxEnding = max(maxEnding+arr[i], arr[i]);
		res = max(res,maxEnding);
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