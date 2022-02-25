/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node == NULL)
            return node;
        
        unordered_map<Node*, Node*> m;
        queue<Node*> q;
        
        Node *copyNode = new Node(node->val);
        
        m[node] = copyNode;
        q.push(node);

        Node *temp = nullptr;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();

            for(auto ngbr: temp->neighbors)
            {
                if(m.find(ngbr) == m.end())
                {
                    m[ngbr] = new Node(ngbr->val);
                    q.push(ngbr);
                }

                m[temp] -> neighbors.push_back(m[ngbr]);
            }
        }

        return m[node];           
    }
};

// https://leetcode.com/problems/clone-graph/submissions/
