class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0;
        int j = A.size()-1;
        while(i<j){
            if(A[i]%2 != 0){
                swap(A[i], A[j]);
                j--;
            }
            else{
                i++;
            }
        }
        return A;
    }
};
