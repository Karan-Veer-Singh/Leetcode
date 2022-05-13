/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL)    return NULL;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            Node *dummy = new Node(0);
            while (size--) {
                Node *front = q.front();
                q.pop();

                dummy->next = front;
                dummy = dummy->next;

                if (front->left)     q.push(front->left);
                if (front->right)    q.push(front->right);
            }
        }

        return root;
    }
};

// TC - O(N)
// SC - O(N)
----------------------------------------------------------------------------------

class Solution {
public:
    Node* connect(Node* root) {
        Node *head = root;
        while (head != NULL) {
            Node *dummy = new Node(0);
            Node *temp = dummy;

            while (head != NULL) {
                if (head->left) {
                    dummy->next = head->left;
                    dummy = dummy->next;
                }
                if (head->right) {
                    dummy->next = head->right;
                    dummy = dummy->next;
                }
                head = head->next;
            }
            head = temp->next;
        }
        return root;
    }
};

// TC - O(N)
// SC - O(1)

// https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/