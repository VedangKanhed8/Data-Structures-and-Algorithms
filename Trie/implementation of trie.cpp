struct TrieNode {
private :
    TrieNode* links[26];
    bool isTerminal = false;
    
public:    
    TrieNode() {
        for(char ch = 'a' ; ch <= 'z' ; ++ch) {
            this->links[ch - 'a'] = nullptr;
        }
        isTerminal = false;
    }  

    bool containsLink(char ch) {
        return this->links[ch - 'a'] != nullptr;
    }

    void put(char ch) {
        this->links[ch - 'a'] = new TrieNode();
    }

    TrieNode* getLink(char ch) {
        return this->links[ch-'a'];
    }

    void setEnd() {
        this->isTerminal = true;
    }

    bool isEnd() {
        return this->isTerminal;
    }
};

class Trie {
private:
    TrieNode* root;
public :
    Trie() {
        root = new TrieNode();
    }

    void insert(string); 

    bool search(string);

    bool startsWith(string);
};

void Trie:: insert(string word) {
    TrieNode* cur = root;
    for(char& ch : word) {
        if(cur->containsLink(ch) == false) {
            cur->put(ch);
        }
        cur = cur->getLink(ch);
    }
    cur->setEnd();
}

bool Trie:: search(string word) {
    TrieNode* cur = root;
    for(char& ch : word) {
        if(cur->containsLink(ch) == false) return false;
        cur = cur->getLink(ch);
    }
    return cur->isEnd();
}

bool Trie:: startsWith(string prefix) {
    TrieNode* cur = root;
    for(char& ch : prefix) {
        if(cur->containsLink(ch) == false) return false;
        cur = cur->getLink(ch);
    }
    return true;
}
