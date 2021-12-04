class Solution {
public:
    
    void subset(int index, vector<int> &v, vector<int> &nums, vector<vector<int>> &ans)
    {
        ans.push_back(v);
        
        for(int i = index; i < nums.size(); i++)
        {
            if(i != index && nums[i] == nums[i-1])
                continue;
            
            v.push_back(nums[i]);
            
            subset(i+1, v, nums, ans);
            
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        vector<int> v;
        
        sort(nums.begin(), nums.end());
        
        subset(0, v, nums, ans);
        
        return ans;
    }
};	

// https://leetcode.com/problems/subsets-ii/
