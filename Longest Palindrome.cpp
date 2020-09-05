class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> counts(123, 0);
        for(int i=0; i<s.length(); i++){
            counts[(int)s[i]]++;
        }
        
        int len = 0;
        int singlechar = 0;
        for(int i=65; i<=122; i++){
            if(counts[i]%2==0)
                len += counts[i];
            else{
                len += counts[i]-1;
                singlechar = 1;
            }
        }
        
        len += singlechar;
        return len;
    }
};
