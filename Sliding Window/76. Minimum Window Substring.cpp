class Solution {
public:
	string minWindow(string s, string t) {
		if (s.size() == 0 || t.size() == 0)	return "";

		unordered_map<char, int> pattern;
		for (char ch : t)	pattern[ch]++;

		int required = pattern.size();

		int l = 0, r = 0, start = 0, end = 0, windowLength = -1;
		int formed = 0;

		unordered_map<char, int> window;

		while (r < s.size()) {
			char ch = s[r];
			window[ch]++;

			if (pattern.find(ch) != pattern.end() && window[ch] == pattern[ch])
				formed++;

			while (l <= r && formed == required) {
				char c = s[l];

				if (windowLength == -1 || r - l + 1 < windowLength) {
					windowLength = r - l + 1;
					start = l;
					end = r;
				}

				window[c]--;

				if (pattern.find(c) != pattern.end() && window[c] < pattern[c])
					formed--;

				l++;
			}

			r++;
		}

		return windowLength == -1 ? "" : s.substr(start, end - start + 1);

	}
};

// https://leetcode.com/problems/minimum-window-substring/