

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<string> fin_ans;
    void findAllPossiblePaths(vector<vector<int>> &m, int n,string ans,vector<vector<int>> vis,int row,int col)
    {
        vis[row][col]=1;
        if(row==n-1&&col==n-1)
        {
            fin_ans.push_back(ans);
            return;
        }
        if(row+1<n&&vis[row+1][col]==0&&m[row+1][col]==1)
        {
            ans.push_back('D');
            findAllPossiblePaths(m,n,ans,vis,row+1,col);
            ans.pop_back();
        }
        if(col+1<n&&vis[row][col+1]==0&&m[row][col+1]==1)
        {
            ans.push_back('R');
            findAllPossiblePaths(m,n,ans,vis,row,col+1);
            ans.pop_back();
        }
        if(row-1>=0&&vis[row-1][col]==0&&m[row-1][col]==1)
        {
            ans.push_back('U');
            findAllPossiblePaths(m,n,ans,vis,row-1,col);
            ans.pop_back();
        }
        if(col-1>=0&&vis[row][col-1]==0&&m[row][col-1]==1)
        {
            ans.push_back('L');
            findAllPossiblePaths(m,n,ans,vis,row,col-1);
            ans.pop_back();
        }
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        string ans;
        if(m[0][0]==0) return fin_ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        findAllPossiblePaths(m,n,ans,vis,0,0);
        return fin_ans;
    }
};

    


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}



/*
  Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
  DDRDRR DRDDRR
Explanation:
  The rat can reach the destination at 
  (3, 3) from (0, 0) by two paths - DRDDRR 
  and DDRDRR, when printed in sorted order 
  we get DDRDRR DRDDRR.
*/
