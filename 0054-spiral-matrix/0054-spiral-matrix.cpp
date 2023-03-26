class Solution {
private:
    vector<int> result;
    enum move{right, down, up, left};
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        move dir = right;
        updateOrder(matrix, dir, 0, 0);
        return result;
    }
    
    void updateOrder(vector<vector<int>>& matrix, move dir, int i, int j){
        if(i<0 || j<0 || i>=matrix.size() || j>= matrix[0].size() || matrix[i][j]==101){
            return;
        }

        if(dir == right){
            if(j == matrix[0].size()-1 || matrix[i][j+1] == 101){
                result.push_back(matrix[i][j]);
                matrix[i][j] = 101;                
                
                updateOrder(matrix, down, i+1, j);                
            }
            else {
                result.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                               
                updateOrder(matrix, right, i, j+1);

            }

        }else if(dir == down){
            if(i == matrix.size()-1 || matrix[i+1][j] == 101){
                result.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                               
                updateOrder(matrix, left, i, j-1);
            }
            else{
                result.push_back(matrix[i][j]);
                matrix[i][j] = 101;              
                
                updateOrder(matrix, down, i+1, j);
            }

        }else if(dir == left){
            if(j == 0 || matrix[i][j-1] == 101){
                result.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                
                
                updateOrder(matrix, up, i-1, j);
            }
            else{
                result.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                
                
                updateOrder(matrix, dir, i, j-1);
            }
        }else if(dir == up){
            if(i == 0 || matrix[i-1][j] == 101){
                result.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                
                
                updateOrder(matrix, right, i, j+1);
            }
            else{
                result.push_back(matrix[i][j]);
                matrix[i][j] = 101;
                
                
                updateOrder(matrix, up, i-1, j);
            }
        }
    }
};

// [[1,2,3,4],
//  [5,6,7,8],
//  [9,10,11,12],
//  [13,14,15,16]]