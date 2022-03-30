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

        if (s1 == s2)    return true;

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                rank[s2] += rank[s1];
                parent[s1] = s2;
            }
            else {
                rank[s1] += rank[s2];
                parent[s2] = s1;
            }
        }

        return false;
    }
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        DSU d(1001);

        int V = edges.size();
        vector<int> indegree(V + 1, -1);
        int bl1 = -1, bl2 = -1;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            if (indegree[v] == -1) {
                indegree[v] = i;
            }
            else {
                bl1 = i;
                bl2 = indegree[v];
                break;
            }
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == bl1)    continue;

            int u = edges[i][0];
            int v = edges[i][1];

            bool cycle = d.unionSet(u, v);

            if (cycle == true) {
                if (bl1 == -1)   return edges[i];
                else    return edges[bl2];
            }
        }

        return edges[bl1];
    }
};

// https://leetcode.com/problems/redundant-connection-ii/submissions/