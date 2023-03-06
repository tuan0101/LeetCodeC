class Solution {
private:
    int num = 0;
public:

    int numIslands(vector<vector<char>>& grid) {
        for(int i=0; i<grid.size(); i++)
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == '1')
                    num++;
                dfs(grid, i, j);
            }
        return num;
    }
    
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(grid[r][c] == '2' || grid[r][c] == '0') return;
        grid[r][c] = '2';
        if(c>0) dfs(grid, r, c-1); // top
        if(r>0) dfs(grid, r-1, c); // left
        if(r<grid.size()-1) dfs(grid, r+1, c); //bottom
        if(c<grid[0].size()-1) dfs(grid, r, c+1); //right
    }
};