class Solution {
public:
    void moveZeroes(vector<int>& A) 
    {
        int j = 0;
	    for (int i = 0; i < A.size(); i++)
		    if (A[i] != 0)
			    swap(A[i], A[j++]);    
    }
};

// Time Complexity: O(N).

// https://leetcode.com/problems/move-zeroes/submissions/
