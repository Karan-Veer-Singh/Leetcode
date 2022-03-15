class Solution {
public:
	string minRemoveToMakeValid(string s)
	{
		int count = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(')
			{
				count++;
			}
			else if (s[i] == ')')
			{
				if (count == 0)
					s[i] = 'A';
				else
					count--;
			}
		}

		count = 0;

		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] == ')')
			{
				count++;
			}
			else if (s[i] == '(')
			{
				if (count == 0)
					s[i] = 'A';
				else
					count--;
			}
		}

		string ans = "";

		for (char c : s)
			if (c != 'A')
				ans += c;

		return ans;
	}
};

// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/submissions/