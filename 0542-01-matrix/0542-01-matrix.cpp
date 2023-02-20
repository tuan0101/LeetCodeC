class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int INF = row + col;
        // top left -> bottom right
        for (int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j]!=0){
                    // before update, ignore this value completely
                    mat[i][j] = INF;
                    
                    if(i>0) 
                        //top
                        mat[i][j] = min(mat[i][j], mat[i-1][j] +1);
                    if(j>0) 
                        //left
                        mat[i][j] = min(mat[i][j], mat[i][j-1] +1);
                }
            }
        }
        
        // bottom right -> top left
        for(int i=row-1; i>=0; i--){
            for(int j=col-1; j>=0; j--){
                if(mat[i][j]!=0){
                    if(i<row-1) 
                        //bottom
                        mat[i][j] = min(mat[i][j], mat[i+1][j] +1);
                    if(j<col-1) 
                        //right
                        mat[i][j] = min(mat[i][j], mat[i][j+1] +1);
                }
            }
        }
        return mat;
    }
};

// first direction
// current cell = min(top, left) + 1
// but if top or left is invalid, we have to split them to 2 statements