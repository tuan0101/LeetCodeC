class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        enum move{RIGHT, DOWN, UP, LEFT};
        
        vector<int> result;
        move dir = RIGHT;
        //updateOrder(matrix, dir, 0, 0);
        int left=0, right=matrix[0].size()-1, top=0, bottom = matrix.size()-1;
        
        while(left<=right && top<=bottom){
            switch(dir){
                case RIGHT:
                    for(int i=left; i<=right; i++){
                        result.push_back(matrix[top][i]);
                    }
                    top++;
                    dir = DOWN;
                    break;
                case DOWN:
                    for(int i=top; i<=bottom; i++){
                        result.push_back(matrix[i][right]);
                    }                       
                    right--;
                    dir = LEFT;
                    break;
                case LEFT:
                    for(int i=right; i>=left; i--){
                        result.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                    dir = UP;
                    break;
                case UP:
                    for(int i=bottom; i>=top; i--){
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                    dir = RIGHT;
                    break;
            }              
        }
        return result;
    }

};

// [[1,2,3,4],
//  [5,6,7,8],
//  [9,10,11,12],
//  [13,14,15,16]]