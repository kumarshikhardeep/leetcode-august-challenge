class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v1;
        v1.push_back(1);
        
        if(rowIndex == 0)
            return v1;
        
        v1.push_back(1);
        if(rowIndex == 1)
            return v1;
        
        for(int i=2; i<=rowIndex; i++){
            
            vector<int> v2;
            v2.push_back(1);
            for(int j=1; j<i; j++){
                int sum = v1[j] + v1[j-1];
                v2.push_back(sum);
            }
            v2.push_back(1);
            swap(v1, v2);
            
        }
        return v1;
    }
};
