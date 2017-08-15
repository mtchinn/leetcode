class Solution {
public:
    void dfs(int x, int y,vector<vector<char>>&bd,vector<vector<char>>&ret,vector<vector<bool>>&h1,vector<vector<bool>>&h2,vector<vector<bool>>&h3){
        if(x==bd.size() && y == 0) {
            ret = bd;
            return ;
        }
        if(ret.size()>0) return ;
        if(bd[x][y]!='.'){
            int xx = (y==8)?x+1:x;
            int yy = (y==8)?0:y+1;
            dfs(xx,yy,bd,ret,h1,h2,h3);
        }else {
            for (int i = 1; i < 10; ++i) {
                int k = x/3 *3 + y/3;
                if(!h1[i-1][x] && !h2[i-1][y] && !h3[i-1][k]){
                    bd[x][y] = i + '0';
                    int xx = (y==8)?x+1:x;
                    int yy = (y==8)?0:y+1;
                    h1[i-1][x] = true;
                    h2[i-1][y] = true;
                    h3[i-1][k] = true;
                    dfs(xx,yy,bd,ret,h1,h2,h3);
                    bd[x][y] = '.';
                    h1[i-1][x] = false;
                    h2[i-1][y] = false;
                    h3[i-1][k] = false;
                }
            }
        }
    }

    void init(vector<vector<char>>& board,vector<vector<bool>>&h1,vector<vector<bool>>&h2,vector<vector<bool>>&h3){
        for(int i=0; i<board.size(); ++i)
            for(int j=0; j<board.size(); ++j){
                if(board[i][j]!='.'){
                    int num = board[i][j] - '0' - 1;
                    int k = (i/3)*3+j/3;
                    h1[num][i] = true;
                    h2[num][j] = true;
                    h3[num][k] = true;
                }
            }
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>> temp = board;
        vector<vector<char>>ret;
        vector<vector<bool>>h1(board.size(),vector<bool>(board.size(),false));
        vector<vector<bool>>h2(board.size(),vector<bool>(board.size(),false));
        vector<vector<bool>>h3(board.size(),vector<bool>(board.size(),false));
        init(board,h1,h2,h3);
        dfs(0,0,board,ret,h1,h2,h3);
        board = ret;
    }
};