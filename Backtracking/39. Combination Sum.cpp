class Solution {
public:
    
    void combination(int index, int target, vector<int> &candidates, vector<int> &v, vector<vector<int>>&ans)
    {
        if(index == candidates.size())
        {
            if(target == 0)
                ans.push_back(v);
            
            return;
        }
        
        if(candidates[index] <= target)
        {
            v.push_back(candidates[index]);
            combination(index, target-candidates[index], candidates, v, ans);
            v.pop_back();
        }
        
        combination(index+1, target, candidates, v, ans);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> v;
        
        combination(0, target, candidates, v, ans);
        
        return ans;
    }
};

// https://leetcode.com/problems/combination-sum/
