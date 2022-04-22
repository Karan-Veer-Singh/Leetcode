class MyHashMap {
private:
    vector<int> hMap;

public:
    MyHashMap() {
        hMap.resize(1e6 + 7, -1);
    }

    void put(int key, int value) {
        hMap[key] = value;
    }

    int get(int key) {
        return hMap[key];
    }

    void remove(int key) {
        hMap[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

// https://leetcode.com/problems/design-hashmap/