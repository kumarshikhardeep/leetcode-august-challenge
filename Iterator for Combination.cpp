class CombinationIterator {
public:
    
    
    int len;
    string sol = "";
    vector<string> res;
    int index = 0;
     
    CombinationIterator(string characters, int combinationLength) {
        len = combinationLength;
        backtrack(0, characters);
        // for(string s:res)
        //     cout<<s<<" ";
    }
    
    void backtrack(int start, string characters) {
        
        if (sol.length() == len) {
            res.push_back(sol);
            return;
        }
        
        for (int i = start; i < characters.length(); i++) {
            sol += characters[i];
            backtrack(i+1, characters);
            sol = sol.substr(0, sol.length()-1);
            // sol.setLength(sol.length()-1);
        }
    }
    
    string next() {
     
        if(!hasNext())
            return "";
        return res[index++];
        
    }
    
    bool hasNext() {
        return index < res.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
