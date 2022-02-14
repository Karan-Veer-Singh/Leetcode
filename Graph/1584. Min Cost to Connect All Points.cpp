class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n = points.size();
        
        if (n==1) return 0;
        
        vector<pair<int,int>> adj[n];
        
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int dist = abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        
        vector<int> dist(n,INT_MAX);
        vector<bool> vis(n,false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        dist[0] = 0;
        pq.push({0,0});
        
        int ans = 0;
        
        while (!pq.empty()){
            int u = pq.top().second;
            int c = pq.top().first;
            pq.pop();
            
            if (vis[u]) continue;
            
            ans += c;
            vis[u] = true;
            
            for (auto ad : adj[u]){
                int v = ad.first;
                int d = ad.second;
                
                if (!vis[v] && dist[v] > d){
                    dist[v] = d;
                    pq.push({dist[v],v});
                }
            }
        }
        
        return ans;   
    }
};

// https://leetcode.com/problems/min-cost-to-connect-all-points/submissions/
