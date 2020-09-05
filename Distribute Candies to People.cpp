class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int n = 1;
        int ind = 0;
        int tot = 0;
        while(tot<=candies){
            tot += n;
            if(tot>candies)
                break;
            res[ind] += n;
            ind++;
            n++;
            if(ind>=num_people){
                ind = 0;
            }
        }
        
        int remaining = candies - (tot - n);
        res[ind] += remaining;
        return res;
    }
};
