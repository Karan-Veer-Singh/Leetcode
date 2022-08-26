class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string number = sortedDigits(n);

        for (int i = 0; i < 30; ++i) {
            string powerOfTwo = sortedDigits(1 << i);
            if (number == powerOfTwo)
                return true;
        }

        return false;
    }

private:
    string sortedDigits(int n) {
        string digits = to_string(n);
        sort(digits.begin(), digits.end());
        return digits;
    }
};

// https://leetcode.com/problems/reordered-power-of-2/