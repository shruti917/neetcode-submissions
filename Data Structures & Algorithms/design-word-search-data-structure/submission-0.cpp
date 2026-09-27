class TrieNode {
public:
    vector<TrieNode*> children;
    bool isleaf;

    TrieNode() {
        children.resize(26, nullptr);
        isleaf = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isleaf = true;
    }

    bool searchHelper(TrieNode* curr, string& word, int i) {
        if (i == word.size()) {
            return curr->isleaf;
        }

        char c = word[i];

        if (c != '.') {
            int idx = c - 'a';

            if (curr->children[idx] == nullptr) {
                return false;
            }

            return searchHelper(curr->children[idx], word, i + 1);
        }

        // Wildcard: try every available child
        for (int j = 0; j < 26; j++) {
            if (curr->children[j] != nullptr) {
                if (searchHelper(curr->children[j], word, i + 1)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};