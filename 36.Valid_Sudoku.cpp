class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty())return false;
        //[] or [[],[],[]]
        int m=board.size(),n=board[0].size();
        vector<bool>a(m,false) 
        vector<vector<bool>>rowFlag(m,a);
        vector<vector<bool>>colFlag(m,a);
        vector<vector<bool>>cellFlag(m,a);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]>='1'&&board[i][j]<='9'){
                    //exist number instead of '.'
                    int c=board[i][j]-'1';
                    if(rowFlag[i][c]||colFlag[c][j]||cellFlag[3*(i/3)+j/3][c])return false;
                    rowFlag[i][c]=true;
                    colFlag[c][j]=true;
                    cellFlag[3*(i/3)+j/3][c]=true;
                }
            }
        }
        return true;
    }
};
