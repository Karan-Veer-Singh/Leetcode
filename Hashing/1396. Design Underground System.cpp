class UndergroundSystem {
public:
    map<int , pair<string, double>> mp1; // [id]->{station name,time}
    map<pair<string, string>, pair<int, int>> mp2;
    // [{checkIn,checkOut}]->{total travel time,total data count}
    UndergroundSystem() {

    }
    void checkIn(int id, string checkIn, int dept) {
        mp1[id] = {checkIn, dept};
    }
    void checkOut(int id, string checkOut, int arrival) {
        string checkIn = mp1[id].first;
        int dept = mp1[id].second;
        int prevValue = mp2[ {checkIn, checkOut}].first;
        int count = mp2[ {checkIn, checkOut}].second;
        mp2[ {checkIn, checkOut}] = { prevValue + (arrival - dept), count + 1};
    }
    double getAverageTime(string checkIn, string checkOut) {
        int totalTime = mp2[ {checkIn, checkOut}].first;
        int totalData = mp2[ {checkIn, checkOut}].second;
        return ((double)totalTime / totalData);
    }
};

// https://leetcode.com/problems/design-underground-system/