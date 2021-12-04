class Solution {
public:
    
    void subset(int index, vector<int> A, vector<int> &ds, vector<vector<int>> &ans)
    {
        if(index == A.size())
        {
            ans.push_back(ds);
            return;
        }

        ds.push_back(A[index]);
        subset(index+1, A, ds, ans);

        ds.pop_back();
        subset(index+1, A, ds, ans);
    }
    
    vector<vector<int>> subsets(vector<int>& A) 
    {
        vector<vector<int>> ans;
        vector<int> ds;

        subset(0, A, ds, ans);

        return ans;
    }
};

// https://leetcode.com/problems/subsets/
