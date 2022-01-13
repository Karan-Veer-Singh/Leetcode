class Solution {
public:
    int atmost(vector<int> &A, int B)
    {
        int j = 0;
        int ans = 0;
        unordered_map<int, int> m;

        for(int i = 0; i < A.size(); i++)
        {
            m[A[i]]++;

            while(m.size() > B)
            {
                int e = A[j];
                m[e]--;

                if(m[e] == 0)
                    m.erase(e);

                j++;
            }

            ans += (i-j+1);
        }

        return ans;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) 
    {
        return atmost(nums, k) - atmost(nums, k-1);    
    }
};

// https://leetcode.com/problems/subarrays-with-k-different-integers/submissions/
