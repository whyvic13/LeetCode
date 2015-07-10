void solveSudoku(vector<vector<char> > &board) {
    solveSudoku(board, 0, 0);
}
//backtrace
bool solveSudoku(vector<vector<char> > &board, int row, int col) {
    if (board.size()==row) return true;
    if (board[row][col]!='.') {
        if (col==board.size()-1) return solveSudoku(board, row+1, 0);
        else return solveSudoku(board, row, col+1);
    }
    for (int i=1; i<=9; i++) {
        if (check(board, row, col, '0'+i)) {
            board[row][col] = '0'+i;
            if (col==board.size()-1 && solveSudoku(board, row+1, 0)) return true;
            else if (solveSudoku(board, row, col+1)) return true;
            board[row][col] = '.';
        }
    }
    return false;
}

bool check(vector<vector<char> > &board, int row, int col, char value) {
    int i;
    for (i=0; i<9; i++) {
        if (board[row][i]==value) return false;
    }
    for (i=0; i<9; i++) {
        if (board[i][col]==value) return false;
    }
    for (i=0; i<9; i++) {
        int r = (row/3)*3+i/3;
        int c = (col/3)*3+i%3;
        if (board[r][c]==value) return false;
    }
    return true;
}
