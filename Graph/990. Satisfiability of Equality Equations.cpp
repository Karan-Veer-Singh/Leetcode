class Solution {
private:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x)  return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        int lx = find(x);
        int ly = find(y);

        if (lx != ly) {
            if (rank[lx] < rank[ly]) parent[lx] = ly;
            else if (rank[ly] < rank[lx])    parent[ly] = lx;
            else    parent[lx] = ly, rank[ly]++;
        }
    }

public:
    Solution() {
        parent.resize(26);
        rank.resize(26);

        for (int i = 0; i < 26; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        for (string eqn : equations)
            if (eqn[1] == '=')
                unite(eqn[0] - 'a', eqn[3] - 'a');

        for (string eqn : equations) {
            if (eqn[1] == '!') {
                int lx = find(eqn[0] - 'a');
                int ly = find(eqn[3] - 'a');
                if (lx == ly)    return false;
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/satisfiability-of-equality-equations/