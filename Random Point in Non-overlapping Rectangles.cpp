class Solution {
public:
    vector <int> area;
    vector < vector <int> > rect;
    int sum;
    
    Solution(vector<vector<int>>& rects) {
        rect = rects;
        sum = 0;
        for(int i =0 ; i < rects.size(); i++){
           int x1 = rects[i][0];
           int y1 = rects[i][1];
           int x2 = rects[i][2];
           int y2 = rects[i][3];
           int temp = (abs(x2 - x1) + 1) * (abs(y2 - y1) + 1);
           sum += temp;
           area.push_back(sum);
        }
    }
    
    vector<int> pick() {
        int randArea = rand() % sum + 1;
        int i;
        for(i = 0; i < area.size(); i++){
           if(randArea <= area[i]) break;
        }
        int dist_x = rand() % (abs(rect[i][0] - rect[i][2] ) + 1);
        int dist_y = rand() % (abs(rect[i][1] - rect[i][3] ) + 1);
        return {dist_x + rect[i][0], dist_y + rect[i][1]};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
