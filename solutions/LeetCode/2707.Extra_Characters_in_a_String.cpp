// https://leetcode.com/problems/extra-characters-in-a-string/submissions/1038907356/

#define MAX_CHAR 26

struct TrieNode{
    bool isWord;
    TrieNode* childs[MAX_CHAR];

    TrieNode(){
        isWord = false;
        fill(childs, childs + 26, (TrieNode*)NULL);
    }
};

class Trie {
private:
    TrieNode* root;
public:
    // TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    ~Trie(){
        delete root;
    }

    TrieNode* getRoot(){
        return this->root;
    }

    void insert(const string& word) {
        TrieNode* current = root;
        for(char c: word){
            int i = c - 'a';
            if(current->childs[i] == NULL)
                current->childs[i] = new TrieNode();
            current = current->childs[i];
        }
        current->isWord = true;
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int len = s.length();
        Trie trie;
        for(const string& str : dictionary)
            trie.insert(str);

        vector<int> minExtraCh(len + 1, 0);
        TrieNode* current;
        for (int i = len - 1; i >= 0; i--) {
            minExtraCh[i] = minExtraCh[i+1]+1;
            current = trie.getRoot();

            for (int j = i; j < len; j++) {
                if (current->childs[s[j] - 'a'] == NULL)
                    break;
                
                current = current->childs[s[j] - 'a'];
                if(current->isWord)
                    minExtraCh[i] = min(minExtraCh[i], minExtraCh[j+1]);
            }
        }
        return minExtraCh[0];
    }
};