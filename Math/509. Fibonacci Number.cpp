class Solution {
public:
    int fib(int n) {
        if (n == 0 || n == 1)    return n;
        int a = 0, b = 1, f;

        for (int i = 2; i <= n; i++) {
            f = a + b;
            a = b;
            b = f;
        }
        return f;
    }
};

// https://leetcode.com/problems/fibonacci-number/