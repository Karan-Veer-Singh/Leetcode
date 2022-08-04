class Solution {
public:
    int mirrorReflection(int p, int q) {
        while (p % 2 == 0 && q % 2 == 0) {
            p /= 2;
            q /= 2;
        }
        return q % 2 + (p - 1) % 2;
    }
};

// https://leetcode.com/problems/mirror-reflection/