class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int n = nums.size();
        
        int low = 0;
        int mid = 0;
        int high = n-1;
        
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            else if(nums[mid] == 2)
            {
                swap(nums[mid], nums[high]);
                high--;
            }
            else
            {
                mid++;
            }
        }
        
    }
};

// Time Complexity: O(N).
// Dutch National Flag Algorithm.

// https://leetcode.com/problems/sort-colors/
