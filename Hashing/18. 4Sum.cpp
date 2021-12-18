class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector< vector<int> > ans;
        
        if(nums.empty())
            return ans;
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                int t = target - nums[i] - nums[j];
                
                int front = j+1;
                int end = n-1;
                
                while(front < end)
                {
                    int s = nums[front] + nums[end];
                    
                    if(s < t)
                        front++;
                    else if(s > t)
                        end--;
                    else
                    {
                        vector<int> quad(4, 0);
                        quad[0] = nums[i];
                        quad[1] = nums[j];
                        quad[2] = nums[front];
                        quad[3] = nums[end];
                        
                        ans.push_back(quad);
                        
                        while(front < end && nums[front] == quad[2])
                        {
                            front ++;
                        }
                        
                        while(front < end && nums[end] == quad[3])
                        {
                            end--;
                        }
                    }
                }
                
                while(j+1 < n && nums[j+1] == nums[j])
                {
                    j++;
                }
            }
            
            while(i+1 < n && nums[i+1] == nums[i])
            {
                i++;
            }
        }
        
        return ans;
        
    }
};

// https://leetcode.com/problems/4sum/
