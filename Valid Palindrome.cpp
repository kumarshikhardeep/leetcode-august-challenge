class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string s2 = "";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='a' & s[i]<='z' || s[i]>='A' && s[i]<='Z' || s[i]>='0' && s[i]<='9'){
                s2 += s[i];
            }
        }
        
        string s3  = s2;
        reverse(s2.begin(), s2.end());
        if(s2 == s3)
            return true;
        return false;
    }
};
