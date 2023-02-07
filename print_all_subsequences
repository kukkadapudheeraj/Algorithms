#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// print all possible subsequences
void printAllSubseq(vector<int> &arr,vector<int> &res,int n,int i)
{
	if(i==n)
	{
		for(auto x:res) 
			cout<<x<<" ";
		 cout<<"\n";
		return;
	}
	res.push_back(arr[i]);
	printAllSubseq(arr,res,n,i+1);
	res.pop_back();
	printAllSubseq(arr,res,n,i+1);
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
	printAllSubseq(arr,res,arr.size(),0);
	return 0;
}
