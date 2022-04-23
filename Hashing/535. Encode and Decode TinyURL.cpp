class Solution {
private:
    int id;
    unordered_map<string, string> m;

public:
    Solution() {
        id = 1;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string tinyUrl = to_string(id);
        m[tinyUrl] = longUrl;
        id++;
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

// https://leetcode.com/problems/encode-and-decode-tinyurl/