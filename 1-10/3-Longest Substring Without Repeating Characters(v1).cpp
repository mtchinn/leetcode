//找出往前有多少(k)个无重复子串，往前走k步
class Solution {
public:
	    int lengthOfLongestSubstring(string s) {
	        if(s.size() == 0) return 0;
	        int len = s.size();
	        int maxlen = 1;
	        vector<int>mHash(500,0);
	        for(int i=0; i<len; ++i){
	            mHash.clear();
	            mHash.resize(500,0);
	            int cc = 1;
	            mHash[s[i]]=1;
	            for(int j=i+1; j< len; ++j){
	                if(mHash[s[j]]){
	                    break;
	                }
	                mHash[s[j]] = 1;
	                ++cc;
	            }
	            if(cc> maxlen)
	                maxlen = cc;
	        }
	        return maxlen;
	    }
	};