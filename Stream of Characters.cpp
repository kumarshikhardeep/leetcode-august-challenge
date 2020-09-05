class trie{
    trie* children[26];
    bool endOfWord;
    
    public:
        trie():endOfWord(false){
            for(int i=0; i<26; i++){
                children[i]=NULL;
            }
        }
    
        void insert(string s){
            trie* t = this;
            for(int i=0; i<s.length(); i++){
                int ind = s[i]-'a';
                if(t->children[ind] == NULL){
                    t->children[ind] = new trie();
                }
                t = t->children[ind];
            }
            t->endOfWord = true;
        }
    
        bool search(deque<char>& s){
            trie* t = this;
            for(int i=0; i<s.size(); i++){
                int ind = s[i] - 'a';
                if(t->children[ind] == NULL) 
                    return false;
                t = t->children[ind];
                if(t->endOfWord) 
                    return true;
            }
            return false;
        }
};

class StreamChecker {
public:
    trie t;
    deque<char> s;
    StreamChecker(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            reverse(words[i].begin(), words[i].end());
            t.insert(words[i]);
        }
    }
    
    bool query(char letter) {
        s.push_front(letter);
        return t.search(s);
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
