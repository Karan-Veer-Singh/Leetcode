// Using Priority Queue
------------------------ -

class Solution {
private:
    struct comparator {
        bool operator() (pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)          return a.second < b.second;
            return a.first > b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (string word : words)    freq[word]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, comparator> minH;

        for (auto x : freq) {
            minH.push({x.second, x.first});
            if (minH.size() > k)   minH.pop();
        }

        vector<string> res;

        while (!minH.empty()) {
            res.push_back(minH.top().second);
            minH.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

--------------------------------------------------------------------------------------

// Using Vector
---------------- -

class Solution {
private:
    bool static comparator(pair<string, int>&p1, pair<string, int>& p2) {
        if (p1.second == p2.second) return p1.first < p2.first;
        return p1.second > p2.second;
    }

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (string word : words)    freq[word]++;

        vector<pair<string, int>> v;
        for (auto it : freq)
            v.push_back({it.first, it.second});

        sort(v.begin(), v.end(), comparator);

        vector<string> res;
        for (int i = 0; i < k; i++)
            res.push_back(v[i].first);

        return res;
    }
};