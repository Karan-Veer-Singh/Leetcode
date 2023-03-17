struct Node {
public:
    Node *links[26];
    bool isEndOfWord = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        isEndOfWord = true;
    }

    bool isEnd() {
        return isEndOfWord;
    }
};

class Trie {
private :
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
        node->setEnd();
    }

    bool search(string word) {
        Node *node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (!node->containsKey(ch))  return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            if (!node->containsKey(ch))  return false;
            node = node->get(ch);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// https://leetcode.com/problems/implement-trie-prefix-tree/