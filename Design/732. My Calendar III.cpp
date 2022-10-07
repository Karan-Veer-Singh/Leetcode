class MyCalendarThree {
public:
    map<int, int> m;
    int maxCount = 0;
    MyCalendarThree() {

    }

    int book(int start, int end) {
        m[start]++;
        m[end]--;
        int count = 0;
        for (auto it = m.begin(); it != m.end(); it++) {
            count += it->second;
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

// https://leetcode.com/problems/my-calendar-iii/