class Solution {
public:
bool helper(vector<vector<char>>&board,char ch,int row,int col){
    for(int i=0;i<9;i++){
        if(board[row][i]==ch)return false;
    }
    for(int i=0;i<9;i++){
        if(board[i][col]==ch)return false;
    }
    for(int i=0;i<9;i++){
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==ch)return false;
    }
    return true;
}
bool solver(vector<vector<char>>&board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]=='.'){
                for(char ch='1';ch<='9';ch++){
                    if(helper(board,ch,i,j)){
                        board[i][j]=ch;
                      bool a=solver(board);
                      if(a)return true;
                        board[i][j]='.';
                    }
                }
                return false;
            }
        }
    }
    return true;

}
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};