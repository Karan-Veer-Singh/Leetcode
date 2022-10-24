class Solution {
private:
    void maxLengthUtil(int indx, vector<string> &arr, string temp, int &maxLength) {
        // Base Case
        if (indx == arr.size()) {
            // Calculate the frequency of each character
            int freq[26] = {0};

            for (char &ch : temp) {
                freq[ch - 'a']++;

                // If there is any repeating character then return
                if (freq[ch - 'a'] > 1)    return;
            }

            // Calculate the max size
            int l = temp.size();
            maxLength = max(maxLength, l);
            return;
        }

        // Take the string
        maxLengthUtil(indx + 1, arr, temp + arr[indx], maxLength);

        // Don't take the string
        maxLengthUtil(indx + 1, arr, temp, maxLength);
    }

public:
    int maxLength(vector<string>& arr) {
        vector<string> temp;
        int maxLength = 0;
        maxLengthUtil(0, arr, "", maxLength);
        return maxLength;
    }
};

// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/