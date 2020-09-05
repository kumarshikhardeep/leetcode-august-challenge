class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int last = A.size()-1;
        vector<int> res;
        while(last>=0){
            int i;
            int maxVal = A[0];
            int maxInd = 0;
            for(i=0; i<=last; i++){
                if(A[i]>maxVal){
                    maxVal = A[i];
                    maxInd = i;
                }
            }
            // cout<<maxInd<<" "<<maxVal<<"  ";
            reverse(A.begin(), A.begin()+maxInd+1);
            if(maxInd>0)
                res.push_back(maxInd);
            reverse(A.begin(), A.begin()+last+1);
            if(last>0)
                res.push_back(last);
            last--;
        }
        
        return res;
    }
};
