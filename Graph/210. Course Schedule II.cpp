class Solution {
public:
    void toposort(int numCourses, vector<int> &indegree, vector<vector<int>> &adj, vector<int> &ans) {
        queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)    q.push(i);

        while (!q.empty()) {
            int curr = q.front(); q.pop();
            ans.push_back(curr);
            for (auto ngbr : adj[curr]) {
                indegree[ngbr]--;
                if (indegree[ngbr] == 0) q.push(ngbr);
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (vector<int> v : prerequisites) {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }

        vector<int> ans;
        toposort(numCourses, indegree, adj, ans);

        if (ans.size() == numCourses)    return ans;
        return {};
    }
};

// https://leetcode.com/problems/course-schedule-ii/