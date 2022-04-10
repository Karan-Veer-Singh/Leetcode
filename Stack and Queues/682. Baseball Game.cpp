class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (string op : ops) {
            if (op == "+") {
                int first = s.top(); s.pop();
                int second = first + s.top();
                s.push(first);
                s.push(second);
            }
            else if (op == "C")   s.pop();
            else if (op == "D")   s.push(2 * s.top());
            else    s.push(stoi(op));
        }

        int ans = 0;
        while (!s.empty()) {
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};

// https://leetcode.com/problems/baseball-game/submissions/