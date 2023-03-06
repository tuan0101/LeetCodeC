class Solution {
private:
    int num = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0, offsets[] = {0, 1, 0, -1, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    grid[i][j] = '0';
                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> p = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = p.first + offsets[k], c = p.second + offsets[k + 1];
                            if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == '1') {
                                grid[r][c] = '0';
                                todo.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return islands;
    // 70% 65%
//     int numIslands(vector<vector<char>>& grid) {
//         for(int i=0; i<grid.size(); i++)
//             for(int j=0; j<grid[0].size(); j++){
//                 if(grid[i][j] == '1')
//                     num++;
//                 dfs(grid, i, j);
//             }
//         return num;
//     }
    
//     void dfs(vector<vector<char>>& grid, int r, int c){
//         if(grid[r][c] == '2' || grid[r][c] == '0') return;
//         grid[r][c] = '2';
//         if(c>0) dfs(grid, r, c-1); // top
//         if(r>0) dfs(grid, r-1, c); // left
//         if(r<grid.size()-1) dfs(grid, r+1, c); //bottom
//         if(c<grid[0].size()-1) dfs(grid, r, c+1); //right
    }
};