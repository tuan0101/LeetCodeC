class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // TIme: O(M*N*4^L) L is the length of word
        // M*N is number of cell
        // each cell could have 4 directions
        // each direction and another 4 directions up to L time
        // Space: O(L) the call stack is up to L
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(visitTo(board, word, i, j, 0)) return true;
                }
            }
        }
        return false;
    }
    
    bool visitTo(vector<vector<char>>& board, string& word, int i, int j, int index){
        if(index==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()) return false;
        if(word[index] != board[i][j]) return false;
        char current = board[i][j];
        board[i][j] = '*';
        
        bool res = visitTo(board, word, i-1, j, index+1) || //top
            visitTo(board, word, i, j-1, index+1) ||        //left
            visitTo(board, word, i+1, j, index+1) ||        //bottom
            visitTo(board, word, i, j+1, index+1);          //right
        board[i][j] = current;
        return res;
    }
};