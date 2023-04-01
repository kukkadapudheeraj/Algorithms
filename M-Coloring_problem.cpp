//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool possible(int nd,int i,int col[101],bool graph[101][101])
    {
        for(int j=0;j<101;j++)
        {
            if(graph[nd][j]==true && col[j]==i) return false;
        }
        return true;
    }
    
    bool colorGraph(bool graph[101][101],int m,int n,int nd,int col[101])
    {
        if(nd==n) return true;
        for(int i=1;i<=m;i++)
        {
            if(possible(nd,i,col,graph))
            {
                col[nd] = i;
                if(colorGraph(graph,m,n,nd+1,col) == true) return true;
                col[nd]= 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int col[101]={0};
        bool res = colorGraph(graph,m,n,0,col);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends






/*
Input:
  N = 4
  M = 3
  E = 5
  Edges[] = {(0,1),(1,2),(2,3),(3,0),(0,2)}
Output: 
  1
Explanation: 
  It is possible to colour the
  given graph using 3 colours.
*/
