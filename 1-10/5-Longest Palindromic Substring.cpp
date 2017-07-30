//从外往里递归判断是否回文，第92/94案例会超时~~，这个是从中间往外扩展找最大字符串
class Solution {
public:
    bool isLimit(string s, int x){
            if(x>=0 && x<s.size())
                return true;
            return false;
        }
        int extendStr(string s, int start, int end){
            int radius = 0;
            while(isLimit(s,start) && isLimit(s,end)){
                if(s[start]!=s[end])
                    break;
                --start;
                ++end;
                ++radius;
            }
            return radius;
        }
        string longestPalindrome(string s) {
            string ret("");
            int maxlen = 0;
            for(int i=0; i<s.size(); ++i){
                if(s.size()-i +1 <= maxlen/2)
                    break;
                int r1 = extendStr(s,i,i);
                int l1 = r1*2 -1;
                int r2 = extendStr(s,i,i+1);
                int l2 = r2*2;
                if(l1 > l2){
                    if(l1>maxlen){
                        maxlen = l1;
                        ret = s.substr(i-r1+1,l1);
                    }
                }else{
                    if(l2>maxlen){
                        maxlen = l2;
                        ret = s.substr(i-r2+1,l2);
                    }
                }
            }
            return ret;
        }
};