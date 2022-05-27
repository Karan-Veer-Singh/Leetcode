class Solution {
public:
    int numberOfSteps(int num) {
        int count = 0;
        while (num) {
            num = (num % 2) ? num - 1 : num / 2;
            count++;
        }
        return count;
    }
};

// Time Complexity : O(logN)
// Space Complexity : O(1)
---------------------------------------------------- -

class Solution {
public:
    int numberOfSteps(int num) { //  number of steps to reach 0
        int count = 0; // number of steps
        while (num) { // while n is not 0
            num = num & 1 ? num - 1 : num >> 1; // if n is odd, subtract 1, else right shift by 1
            count++; // increment count
        }
        return count; // return count
    }
};

// Time Complexity : O(No. of bits in N)
// Space Complexity : O(1)


// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/