class Solution {
public:
    void dfs(vector<vector<int>> graph, vector<bool> &vis, int src, int dest, 
             vector<vector<int>> &ans, vector<int> &path)
    {
        if(src == dest)
        {
            path.push_back(dest);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        vis[src] = true;
              
        for(auto ngbr : graph[src])
        {
            if(vis[ngbr] == false)
            {
                path.push_back(src);
                dfs(graph, vis, ngbr, dest, ans, path);
                path.pop_back();
            }
        }
        
        vis[src] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int n = graph.size();
        vector<bool> vis(n, false);
        
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(graph, vis, 0, n-1, ans, path);
        
        return ans;
    }
};

// https://leetcode.com/problems/all-paths-from-source-to-target/submissions/
