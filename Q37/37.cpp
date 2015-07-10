class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        solve(board);
    }
    //backtrace
    bool solve(vector<vector<char> > &board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char c='1';c<='9';c++){
                        if(check(board,i,j,c)){
                            board[i][j] = c;
                            if(solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;//be care
                }
            }
        }
        return true;//be care
    }

    bool check(vector<vector<char> > &board, int row,int col,char value) {
        int i;
        for (i=0; i<9; i++) {
            if (board[row][i]==value) return false;
        }
        for (i=0; i<9; i++) {
            if (board[i][col]==value) return false;
        }
        //Check 3 x 3 block
        for(i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++)
            for(int j = (col / 3) * 3; j < (col / 3) * 3 + 3; j++)
                if(board[i][j] == value)
                    return false;
        return true;
    }
};
