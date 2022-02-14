class Solution {
public:
    bool hasCycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> &path)
    {
        vis[node] = true;
        path[node] = true;

        for(auto ngbr : adj[node])
        {
            if(vis[ngbr] == false)
            {
                if(hasCycle(ngbr, adj, vis, path))
                    return true;
            }
            else if(path[ngbr] == true)
            {
                return true;
            }
        }

        path[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numCourses];
        for(auto x : prerequisites)
            adj[x[1]].push_back(x[0]);

        vector<bool> vis(numCourses, false);   
        vector<bool> path(numCourses, false);

        for(int i = 0; i < numCourses; i++)
            if(vis[i] == false)
                if(hasCycle(i, adj, vis, path))
                    return false;
        
        return true;
    }
};

// https://leetcode.com/problems/course-schedule/submissions/
