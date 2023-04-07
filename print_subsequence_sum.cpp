#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// print subsequences whose sum is matching the target

void printSubseq(vector<int> &arr,vector<int> &res,int n,int i,int sum,int s)
{
	if(i==n)
	{
		if(s==sum)
		{for(auto x:res) 
			cout<<x<<" ";
		 cout<<"\n";
		}
		return;
	}
	res.push_back(arr[i]);
	s+=arr[i];
	printSubseq(arr,res,n,i+1,sum,s);
	res.pop_back();
	s-=arr[i];
	printSubseq(arr,res,n,i+1,sum,s);
}


int main() {
	vector<int> arr,res;
	int sum,n,x;
	cin>>n;
	for(int i=0;i<n;i++) 
	{
		cin>>x;
		arr.push_back(x);
	}
	cin>>sum;
	printSubseq(arr,res,arr.size(),0,sum,0);
	return 0;
}
