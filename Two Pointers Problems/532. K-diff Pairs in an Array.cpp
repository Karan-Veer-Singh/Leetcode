class Solution {
public:
    int findPairs(vector<int>& A, int k) 
    {
        unordered_map<int, int> m;
        int n = A.size();
        int count = 0;      
        
        for(int x : A)
            m[x]++;
        
        for(auto p : m)
        {
            int x = p.first;
            if( (k > 0 && m.count(x+k) > 0) || (k == 0 && m[x] > 1) )
                count++;       
        }
        
        return count;
    }
};


// https://leetcode.com/problems/k-diff-pairs-in-an-array/submissions/
