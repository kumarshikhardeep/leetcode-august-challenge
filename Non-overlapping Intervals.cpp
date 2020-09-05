class Solution {
public:
    
    static bool comp(vector<int> a, vector<int> b){
        if(b[1] > a[1])
            return true;
        return false;
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return 0;
        
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), comp);
        for(int i=0; i<intervals.size(); i++){
            cout<<intervals[i][0]<<" "<<intervals[i][1]<<"\n";
        }
        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0] >= res.back()[1])
                res.push_back(intervals[i]);
        }
        
        return intervals.size()-res.size();
    }
};
