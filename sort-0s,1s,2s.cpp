
// Dutch National Flag problem
#include <bits/stdc++.h> 
void sortArray(vector<int>& arr, int n)
{
    // Write your code here
    int l=0,m=0,h=n-1,t;
    while(m<h)
    {
        if(arr[m]==0)
        {
            t=arr[m];
            arr[m]=arr[l];
            arr[l]=t;
            l++;
            m++;
        }
        else if(arr[m]==1)
        {
            m++;
        }
        else if(arr[m]==2&&arr[h]!=2)
        {
            t=arr[m];
            arr[m]=arr[h];
            arr[h]=t;
        }
        else
        {
            h--;
        }
    }
    
}
