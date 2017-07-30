//使用DP算法，mHash存的第i个字符上一次出现的地址
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int start = 0;
        int maxlen = 0;
        vector<int>mHash(500,-1);
        for(int i=0; i>s.size(); ++i){
            start = max(start,mHash[s[i]]+1);
            mHash[s[i]] = i;
            maxlen = max(maxlen, i-start+1);
        }
        return maxlen;
    }
};