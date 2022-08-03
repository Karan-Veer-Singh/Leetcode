class MyCalendar {
private:
    vector<pair<int, int>> v;

public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (auto it : v)
            if (end > it.first && start < it.second)
                return false;

        v.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
------------------------------------------------------------------------
// Efficient Approach
// Binary Search

class MyCalendar {
private:
    map<int, int> m;

public:
    MyCalendar() {

    }

    bool book(int start, int end) {
        auto it = m.upper_bound(start);
        if (it != m.end() && end > it->second)
            return false;

        m[end] = start;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */