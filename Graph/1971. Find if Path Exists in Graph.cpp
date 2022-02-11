class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) 
    {
        vector<int> adj[n];
        
        for(auto edge : edges)
        {
            int x = edge[0], y = edge[1];
            
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        
        vector<bool> vis(n, false);
        queue<int> q;
        
        q.push(source);
        vis[source] = true;
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            if(node == destination)
                return true;
            
            for(auto ngbr : adj[node])
            {
                if(vis[ngbr] == false)
                {
                    q.push(ngbr);
                    vis[ngbr] = true;
                }
            }
        }
        
        return false;
    }
};

// https://leetcode.com/problems/find-if-path-exists-in-graph/submissions/
