class Solution {
public:
    string simplifyPath(string A)
    {
        int len_A = A.length();
        vector<string> v;
        string ans;

        for (int i = 0; i < len_A; i++)
        {
            string dir = "";

            while ( (i < len_A) && (A[i] != '/'))
            {
                dir += A[i];
                i++;
            }

            if (dir == ".." )
            {
                if (!v.empty())
                    v.pop_back();
            }

            else if (dir == "." || dir == "")
                continue;

            else
                v.push_back(dir);
        }

        for (string s : v)
            ans += "/" + s;

        if (ans == "")
            return "/";

        return ans;

    }
};

// https://leetcode.com/problems/simplify-path/