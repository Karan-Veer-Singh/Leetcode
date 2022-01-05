class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int pa = m-1;
        int pb = n-1;
        int pc = m+n-1;
        
        while(pb >= 0)
        {
            if(pa >= 0 && nums1[pa] > nums2[pb])
                nums1[pc--] = nums1[pa--];
            else
                nums1[pc--] = nums2[pb--];
        }
    }
};

// https://leetcode.com/problems/merge-sorted-array/submissions/
