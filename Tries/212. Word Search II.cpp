class Node {
private:
    unordered_map<char, Node*> children;
    bool EndOfWord;

public:
    Node() {
        EndOfWord = false;
    }

    bool containsKey(char ch) {
        return (children[ch] != NULL);
    }

    void put(char ch, Node *node) {
        children[ch] = node;
    }

    Node *get(char ch) {
        return children[ch];
    }

    void setEnd(bool val) {
        EndOfWord = val;
    }

    bool isEnd() {
        return EndOfWord;
    }
};


class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd(true);
    }

    void dfs(vector<vector<char>> &board, int i, int j, string temp, vector<string> &ans, Node *curr) {
        if (curr->isEnd()) {
            ans.push_back(temp);
            curr->setEnd(false);
        }

        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size())    return;

        char ch = board[i][j];
        if (ch == '$' || !curr->containsKey(ch))  return;

        curr = curr->get(ch);

        board[i][j] = '$';
        dfs(board, i + 1, j, temp + ch, ans, curr);
        dfs(board, i - 1, j, temp + ch, ans, curr);
        dfs(board, i, j + 1, temp + ch, ans, curr);
        dfs(board, i, j - 1, temp + ch, ans, curr);
        board[i][j] = ch;
    }

    void solve(vector<vector<char>>& board, vector<string> &ans) {
        int r = board.size(), c = board[0].size();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                dfs(board, i, j, "", ans, root);
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for (auto w : words) t.insert(w);

        vector<string> ans;
        t.solve(board, ans);

        return ans;
    }
};

// https://leetcode.com/problems/word-search-ii/