//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	int plt[n]={0},plt_count=0,t=0;
    	pair<int,int> pr[n];
    	for(int i=0;i<n;i++)
    	{
    	    pr[i].first=arr[i];
    	    pr[i].second=dep[i];
    	}
    	sort(pr,pr+n);
    	plt[0]=pr[0].second;
    	for(int i=1;i<n;i++)
    	{
    	    for(int j=0;j<n;j++)
    	    {
    	        if(plt[j]==0)
    	        {
    	            plt[j]=pr[i].second;
    	            break;
    	        }
    	        if(plt[j]<pr[i].first)
    	        {
    	            plt[j]=pr[i].second;
    	            break;
    	        }
    	    }
    	}
    	for(int i=0;i<n;i++)
    	{
    	    if(plt[i]>0)
    	    {
    	        plt_count++;
    	    }
    	    else
    	    {
    	        break;
    	    }
    	}
    	return plt_count;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends



/*
Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
*/
