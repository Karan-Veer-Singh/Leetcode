class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_map<int, int> m;
        
        for(int i = 0; i < nums1.size(); i++)
            m[nums1[i]]++;
        
        for(int i = 0; i < nums2.size(); i++)
        {
            int x = nums2[i];
            
            if(m.find(x) != m.end() && m[x] > 0)
            {
               ans.push_back(x);
               m[x]--;
            }
        }
        
        return ans;    
    }
};

// https://leetcode.com/problems/intersection-of-two-arrays-ii/submissions/
