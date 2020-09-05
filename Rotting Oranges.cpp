class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> rot;
        int fresh = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 2){
                    rot.push(make_pair(i,j));
                }
                if(grid[i][j] == 1)
                    fresh++;
            }
        }
        
        if(fresh == 0)
            return 0;
        
        queue<pair<int,int>> neighbor;
        int time = 0;
        while(!rot.empty()){
            
            pair p = rot.front();
            int x = p.first;
            int y = p.second;
            // cout<<x<<" "<<y<<"\n";
            rot.pop();
            
            if(x>0){
                if(grid[x-1][y] == 1){
                    grid[x-1][y] = 2;
                    fresh--;
                    neighbor.push(make_pair(x-1,y));
                }
            }
            if(x<grid.size()-1){
                if(grid[x+1][y] == 1){
                    grid[x+1][y] = 2;
                    fresh--;
                    neighbor.push(make_pair(x+1,y));
                }
            }
            if(y>0){
                if(grid[x][y-1] == 1){
                    grid[x][y-1] = 2;
                    fresh--;
                    neighbor.push(make_pair(x,y-1));
                }
            }
            if(y<grid[0].size()-1){
                if(grid[x][y+1] == 1){
                    grid[x][y+1] = 2;
                    fresh--;
                    neighbor.push(make_pair(x, y+1));
                }
            }
            
            
            if(rot.empty()){
                time++;
                swap(rot, neighbor);
            }
        }
        if(fresh == 0)
            return time-1;
        return -1;
    }
};
