//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

struct newItem{
    int value;
    int weight;
    double ratio;
};
bool compareRatio(newItem a,newItem b)
{
    return a.ratio>b.ratio;
}

class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        newItem newArr[n];
        double sum=0;
        for(int i=0;i<n;i++)
        {
            newArr[i].value=arr[i].value;
            newArr[i].weight=arr[i].weight;
            newArr[i].ratio = (double)newArr[i].value/(double)newArr[i].weight;
        }
        sort(newArr,newArr+n,compareRatio);
        for(int i=0;i<n;i++)
        {
            // cout<<newArr[i].ratio <<" "<< newArr[i].value<<" "<<newArr[i].weight<<"\n";
            
            if(W>=newArr[i].weight)
            {
                sum+=newArr[i].value;
                W=W-newArr[i].weight;
            }
            else
            {
                sum+=(newArr[i].ratio*W);
                break;
            }
        }
        return sum;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends


/*
Input:
N = 3, W = 50
values[] = {60,100,120}
weight[] = {10,20,30}
Output:
240.00
Explanation:Total maximum value of item
we can have is 240.00 from the given
capacity of sack.

*/
