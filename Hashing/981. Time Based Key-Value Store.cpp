class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> keyTimeMap;
    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        // Push '(timestamp, value)' pair in 'key' bucket.
        keyTimeMap[key].push_back({ timestamp, value });
    }

    string get(string key, int timestamp) {
        // If the 'key' does not exist in map we will return empty string.
        if (keyTimeMap.find(key) == keyTimeMap.end()) {
            return "";
        }

        if (timestamp < keyTimeMap[key][0].first) {
            return "";
        }

        // Using binary search on the array of pairs.
        int left = 0;
        int right = keyTimeMap[key].size() - 1;
        string ans;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (keyTimeMap[key][mid].first == timestamp) {
                return keyTimeMap[key][mid].second;
            }
            else if (keyTimeMap[key][mid].first < timestamp) {
                ans = keyTimeMap[key][mid].second;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */


// https://leetcode.com/problems/time-based-key-value-store/