#include <iostream>

using namespace std;

bool capture(int Q[], int n, int l){
	//returns true if queens stored in Q[0 . . k] capture each other.
	if(l == 1)return false;

	for(int j = 0;j<l-1;j++){
			if((Q[j] == Q[l-1])|| (abs(j-l+1) == abs(Q[j]-Q[l-1]))){
				//cout<<"check"<<l<<endl;
				return true;
			}
		
	}
	return false;
}


void search(int Q[], int k, int n, int &count){
	//Q is a queen configurations in which first K
	//queens are in rows of Q[0]...Q[k-1] and don't intersect each other
	//Of this add the (k+1)th queen in on Kth column on row Q[k+1] and 
	//check if it gets captured or not. If it doesn't continue to append
	//until k = n. If it gets, captured try different value of Q[k+1].

	if(k==n){
			for (int i = 0; i < k; ++i)
			{
				cout<<Q[i]<<" ";
			}
			cout<<endl;
			count = count+1;
		
		return;
	}

	else{
		for(int i =0;i<n;++i){
			Q[k] = i;
			if(!capture(Q,n,k+1)){

				search(Q,k+1,n,count);
			}
		}
	}

	
}


int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int Q[n];
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		Q[i] = 0;
	}
	search(Q,0,n,count);
	cout<<"count "<<count<<endl;
	return 0;
}