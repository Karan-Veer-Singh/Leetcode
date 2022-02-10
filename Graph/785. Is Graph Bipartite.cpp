// BFS

class Solution 
{
    bool checkBipartite(int src, vector<int>&color, vector<vector<int>> graph)
    {
        color[src] = 1;
        
        queue<int> q;
        q.push(src);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto ngbr: graph[node])
            {
                if(color[ngbr] == -1)
                {
                    color[ngbr] = 1-color[node];
                    q.push(ngbr);
                }
                else if(color[ngbr] == color[node])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        int V = graph.size();
        
        vector<int> color(V, -1);
        
        for(int i = 0; i < V; i++)
            if(color[i] == -1)
                if(checkBipartite(i, color, graph) == false)
                    return false;
        
        return true;
    }
};

// https://leetcode.com/problems/is-graph-bipartite/submissions/
