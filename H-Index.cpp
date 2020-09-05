class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> v(n+1, 0);
        for(int i:citations){
            if(i >= n)
                v[n]++;
            else
                v[i]++;
        }
        
        int count = 0;
        for(int i=n; i>=0; i--){
            count = count+v[i];
            if(count >= i)
                return i;
        }
        
        return -1;
    }
};
