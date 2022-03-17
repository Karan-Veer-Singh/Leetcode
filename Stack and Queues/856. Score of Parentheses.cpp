class Solution {
public:
	int scoreOfParentheses(string str) {
		int count = 0;
		stack<int> s;
		for (char c : str) {
			int val = 0;
			if (c == '(')    s.push(0);
			else {
				while (s.top() != 0) {
					val += s.top();
					s.pop();
				}
				val = max(2 * val, 1);
				s.pop();
				s.push(val);
			}
		}

		while (!s.empty()) {
			count += s.top();
			s.pop();
		}

		return count;
	}
};

// https://leetcode.com/problems/score-of-parentheses/