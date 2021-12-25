class Node
{
    public:
    int element;
    int aIndex;
    int bIndex;
};

class NodeCompare
{
    public:
    bool operator()(Node A, Node B)
    {
        return A.element > B.element;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k) 
    {
        vector<vector<int>> ans;
        priority_queue<Node, vector<Node>, NodeCompare> pq;
        set<pair<int,int>> s;
        
        int e = A[0] + B[0];
        int i = 0;
        int j = 0;
        
        pq.push({e,i,j});
        s.insert({0,0});
        
        int n = A.size() * B.size();
        if(k > n)
            k = n;
        
        while(k--)
        {
            Node temp = pq.top();
            pq.pop();
            
            i = temp.aIndex;
            j = temp.bIndex;
            
            ans.push_back({A[i], B[j]});
            
            if(i < A.size()-1 && j < B.size() && s.find({i+1, j}) == s.end())
            {
                pq.push({A[i+1]+B[j], i+1, j});
                s.insert({i+1, j});
            }
            
            if(i < A.size() && j < B.size()-1 && s.find({i, j+1}) == s.end())
            {
                pq.push({A[i]+B[j+1], i, j+1});
                s.insert({i, j+1});
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/submissions/
