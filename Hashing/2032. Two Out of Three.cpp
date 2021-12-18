class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) 
    {
        vector<int> ans;

        int m1[101] = {0};
        int m2[101] = {0};
        int m3[101] = {0};

        for (int i : nums1)  m1[i]++;
        for (int i : nums2)  m2[i]++;
        for (int i : nums3)  m3[i]++;

        for (int i = 1; i <= 100; i++)
            if ( (m1[i] > 0 && m2[i] > 0) || (m2[i] > 0 && m3[i] > 0) || (m3[i] > 0 && m1[i] > 0) )
                ans.push_back(i);

        return ans;    
    }
};

// https://leetcode.com/problems/two-out-of-three/submissions/
