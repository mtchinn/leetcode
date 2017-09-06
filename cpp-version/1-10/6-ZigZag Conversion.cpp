//设置row行的队列，先把字母存进对应的行的队列
class Solution {
public:
    string convert(string s, int numRows) {
        string ret;
        vector<vector<char>>pos(numRows,vector<char>());
        for(int i=0; i<s.size();){
            for(int j=0; j<numRows && i<s.size(); ++j,++i){
                pos[j].push_back(s[i]);
            }
            for(int j=numRows-2; j>0 && i<s.size(); --j,++i){
                pos[j].push_back(s[i]);
            }
        }
        for(int i=0; i<numRows; ++i){
            for(int j=0; j<pos[i].size(); ++j)
                ret.push_back(pos[i][j]);
        }
        return ret;
    }
};