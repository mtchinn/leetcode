//字符串流
class Solution {
public:
    bool isPalindrome(int x) {
        if(x == INT_MIN )
            return false;
        if(x<0){
            return false;
        }
        stringstream ss;
        ss<<x;
        string strx;
        ss>>strx;
        string rev(strx.rbegin(),strx.rend());
        return (strx.compare(rev)==0);

    }
};