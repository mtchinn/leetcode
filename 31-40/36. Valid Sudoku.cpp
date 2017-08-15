class Solution {
public:
    vector<vector<int>> trans(vector<vector<char>>& board){
        vector<vector<int>>ret(board.size(),vector<int>(board.size(),0));
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j] != '.')
                    ret[i][j] = board[i][j] - '0';
            }
        }
        return ret;
    }

    bool isvalidate(int x,int y, vector<vector<int>>bd,int num){

        for(int i=0; i<bd[x].size(); ++i)
            if(bd[x][i] == num && i!=y) return false;

        for(int i=0; i<bd.size(); ++i)
            if(bd[i][y] == num && i!=x) return false;

        int r = (x/3)*3;
        int c = (y/3)*3;

        for(int i =r; i<r+3; ++i){
            for(int j=c; j<c+3; ++j){
                if(num == bd[i][j] && i!=x && j!=y)
                    return false;
            }
        }

        return true;

    }
    
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<vector<int>> bd = trans(board);

        for(int i=0; i<bd.size(); ++i){
            for(int j = 0; j<bd.size(); ++j){
                if(bd[i][j] && !isvalidate(i,j,bd,bd[i][j]))
                    return false;
            }
        }

        return true;
    }
};