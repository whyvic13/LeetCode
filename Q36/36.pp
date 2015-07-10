//learn to use bit manipulation, to save space
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = 0, col[9]={0}, cell[3][3]={0};
        for(int i=0;i<9;i++){
            row = 0;
            for(int j=0;j<9;j++){
                if(board[i][j] == '.') continue;
                int ch = 1 << (int)(board[i][j] - '0');
                if((row & ch) || (col[j] & ch) || (cell[i/3][j/3] & ch)) return false;
                row |= ch;
                col[j] |= ch;
                cell[i/3][j/3] |= ch;
            }
        }
        return true;
    }
};
