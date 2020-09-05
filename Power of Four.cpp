class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)
            return false;
        int n=num;
        if(!(num & num-1)){
            // cout<<"jhg "<<log2(n & -n);
            int pos = log2(n & -n);
            if(pos % 2 == 0)
                return true;
        }
        return false;
    }
};
