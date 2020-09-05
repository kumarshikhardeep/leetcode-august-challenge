class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0]>='a' && word[0]<='z'){
            for(int i=1; i<word.size(); i++){
                if(word[i]<'a' || word[i]>'z')
                    return false;
            }
            return true;
        }
        
        int countCaps = 0;
        int countSmall = 0;
        if(word[0]>='A' && word[0]<='Z'){
            for(int i=1; i<word.size(); i++){
                if(word[i]>='A' && word[i]<='Z')
                    countCaps++;
            }
            if(countCaps == word.size()-1)
                return true;
            
            for(int i=1; i<word.size(); i++){
                if(word[i]>='a' && word[i]<='z')
                    countSmall++;
            }
            if(countSmall == word.size()-1)
                return true;
        }
        
        return false;
        
    }
};
