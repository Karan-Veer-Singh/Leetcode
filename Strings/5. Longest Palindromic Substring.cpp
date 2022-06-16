class Solution {
private:
    int expandFromCenter(string s, int left, int right)
    {
        while (left >= 0 && right < s.length() && s[left] == s[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        if (s.length() < 1)  return "";
        int end = 0, start = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int oddLength = expandFromCenter(s, i, i);
            int evenLength = expandFromCenter(s, i, i + 1);
            int len = max(oddLength, evenLength);

            if (len > end - start)
            {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

// https://leetcode.com/problems/longest-palindromic-substring/