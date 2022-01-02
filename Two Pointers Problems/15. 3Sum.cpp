class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector< vector<int> > ans;
        
        if(nums.size() < 3)
            return ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(i == 0 || (i > 0 && nums[i] != nums[i-1]))
            {
                int low = i+1;
                int high = nums.size()-1;
                
                int sum = -nums[i];
                
                while(low < high)
                {
                    if(nums[low] + nums[high] == sum)
                    {
                        vector<int> res(3, 0);
                        res[0] = nums[i];
                        res[1] = nums[low];
                        res[2] = nums[high];
                        
                        ans.push_back(res);
                        
                        while(low < high && nums[low] == nums[low+1]) low++;
                        while(low < high && nums[high] == nums[high-1]) high--;
                        
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < sum)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                }
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/3sum/
