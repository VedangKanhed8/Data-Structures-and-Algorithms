
struct TrieNode {
private :
    TrieNode* links[26];
    bool isTerminal;
    int count;
    int prefixCount;
    
public:    
    TrieNode() {
        for(char ch = 'a' ; ch <= 'z' ; ++ch) {
            this->links[ch - 'a'] = nullptr;
        }
        isTerminal = false;
        count = 0;
        prefixCount = 0;
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

    void increaseCount() {
        this->count += 1;
    }

    void decreaseCount() {
        this->count -= 1;
    }

    int getCount() {
        return this->count;
    }

    void increasePrefixCount() {
        this->prefixCount += 1;
    }

    int getPrefixCount() {
        return this->prefixCount;
    }

    void decreasePrefixCount() {
        this->prefixCount -= 1;
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

    int countWordsEqualTo(string);

    int countWordsStartingWith(string);

    void erase(string);
};

void Trie:: insert(string word) {
    TrieNode* cur = root;
    for(char& ch : word) {
        if(cur->containsLink(ch) == false) {
            cur->put(ch);
        }
        cur = cur->getLink(ch);
        cur->increasePrefixCount();
    }

    cur->setEnd();
    cur->increaseCount();
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

int Trie:: countWordsEqualTo(string word) {
    TrieNode* cur = root;
    for(char& ch : word) {
        if(cur->containsLink(ch) == false) {
            return 0;
        } 
        cur = cur->getLink(ch);
    }
    return cur->getCount();
}

int Trie:: countWordsStartingWith(string prefix) {
    TrieNode* cur = root;
    for(char& ch : prefix) {
        if(cur->containsLink(ch) == false) return 0;
        cur = cur->getLink(ch);
    } 
    return cur->getPrefixCount();
}

void Trie:: erase(string word) {
    TrieNode* cur = root;
    for(char& ch : word) {
        cur = cur->getLink(ch);
        cur->decreasePrefixCount();
    }
    cur->decreaseCount();
}
