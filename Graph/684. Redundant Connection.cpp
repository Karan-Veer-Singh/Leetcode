class DSU {
public:
    int *parent;
    int *rank;

    DSU(int size) {
        parent = new int[size];
        rank = new int[size];

        for (int i = 0; i < size; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int findSet(int i) {
        if (parent[i] == -1) return i;
        return parent[i] = findSet(parent[i]);
    }

    bool unionSet(int x, int y) {
        int s1 = findSet(x);
        int s2 = findSet(y);

        if (s1 == s2)    return false;

        if (rank[s1] < rank[s2]) {
            rank[s2] += rank[s1];
            parent[s1] = s2;
        }
        else {
            rank[s1] += rank[s2];
            parent[s2] = s1;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU d(1001);
        vector<int> ans;

        for (vector<int> e : edges)
            if (d.unionSet(e[0], e[1]) == false)
                return e;

        return ans;
    }
};

// https://leetcode.com/problems/redundant-connection/