#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// print first subsequence whose sum is equal to target
bool printFirstSubseq(vector<int> &arr,vector<int> &res,int n,int i,int sum,int s)
{
	if(i==n)
	{
		if(s==sum)
		{for(auto x:res) 
			cout<<x<<" ";
		 return true;
		}
		return false;
	}
	res.push_back(arr[i]);
	s+=arr[i];
	if(printFirstSubseq(arr,res,n,i+1,sum,s)==true){return true;}
	res.pop_back();
	s-=arr[i];
	if(printFirstSubseq(arr,res,n,i+1,sum,s)==true){return true;}
	return false;
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
	printFirstSubseq(arr,res,arr.size(),0,sum,0);
	return 0;
}
