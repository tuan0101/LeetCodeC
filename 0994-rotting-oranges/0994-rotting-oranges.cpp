class Solution {
private:
    queue<pair<int, int>> q;
    int fresh = 0;
    int minute = 0;
public:
    int orangesRotting(vector<vector<int>>& grid) {   

        int m = grid.size(), n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        
        while(!q.empty()){
            int q_size = q.size();
            int count = 0;
             //std::cout<<"q_size: "<<q_size;
            for(int i=0; i<q_size; i++){
                pair<int,int> p=q.front();
                int r = p.first;
                int c = p.second;
                q.pop();

                bfs(grid, r-1, c, count); // top  
                bfs(grid, r, c-1, count); // left
                bfs(grid, r+1, c, count); // bottom
                bfs(grid, r, c+1, count); // right
            }
            //std::cout<<"count: "<<count;
            if(count>0)
                minute++;                         
        }
        if (fresh>0) return -1;
        return minute;
        
    }
    
    void bfs(vector<vector<int>>& grid, int r, int c, int &count){
         if(r<0 || c<0 || r> grid.size()-1 || c>grid[0].size()-1 || grid[r][c]!=1)
             return;
                  
        grid[r][c]=2;
        fresh--;
        count++;
        q.push({r, c});    
    }
};