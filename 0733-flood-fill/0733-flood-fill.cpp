class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {             if(image[sr][sc] != newColor)
            dfs(image, sr, sc,image[sr][sc], newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int r, int c, int color, int newColor){
        if(image[r][c] != color) return;
        image[r][c] = newColor;
        if(r > 0) dfs(image, r-1, c, color, newColor); //top
        if(c > 0) dfs(image, r, c-1, color, newColor); //left
        if(r+1 < image.size()) dfs(image, r+1, c, color, newColor); //bottom
        if(c+1 < image[0].size()) dfs(image, r, c+1, color, newColor); //left
    }
};