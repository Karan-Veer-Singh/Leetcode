class Solution {
public:
    int removeDuplicates(vector<int>& A) 
    {
        if (A.size() < 3)
		return A.size();

        int i = 2;
        for (int j = 2; j < A.size(); j++)
            if (A[j] != A[i - 2])
                A[i++] = A[j];

        return i;    
    }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/submissions/
