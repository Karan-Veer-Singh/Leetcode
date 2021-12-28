class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        int sum = 0;
        int right = 1;

        vector<int> left(n, 1);

        for(int i = 1; i < n; i++)
            if(ratings[i] > ratings[i-1])
                left[i] += left[i-1];

        for(int i = n-2; i >= 0; i--)
            if(ratings[i] > ratings[i+1])
                left[i] = max(left[i], ++right);
            else
                right = 1;

        for(int i : left)
            sum += i;

        return sum;   
    }
};

// https://leetcode.com/problems/candy/submissions/
