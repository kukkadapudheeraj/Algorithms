class Solution {
public:
    vector<vector<int>> result;
    void printPerm(vector<int>& arr,int n,vector<int> mp,vector<int> res)
    {
         if(res.size()==n)
        {
            result.push_back(res);
            return;
        }
        for(int ind=0;ind<n;ind++)
        {
            if(mp[ind]==0)
            {
                mp[ind]=1;
                res.push_back(arr[ind]);
                printPerm(arr,n,mp,res);
                res.pop_back();
                mp[ind]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> mp(nums.size(),0);
        vector<int> res;
        printPerm(nums,nums.size(),mp,res);
        return result;
    }
};

/*


Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]


Example 3:
Input: nums = [1]
Output: [[1]]


*/
