class Solution {
public:
    string addBinary(string A, string B) 
    {
        string ans = "";
        int sum = 0;

        int i = A.size()-1;
        int j = B.size()-1;

        while(i >= 0 || j >= 0 || sum == 1)
        {
            sum += ( (i >= 0) ? A[i]-'0' : 0);
            sum += ( (j >= 0) ? B[j]-'0' : 0);

            ans = char(sum%2 + '0') + ans;

            sum /= 2;
            i--;
            j--;
        }

        return ans;    
    }
};

// https://leetcode.com/problems/add-binary/submissions/
