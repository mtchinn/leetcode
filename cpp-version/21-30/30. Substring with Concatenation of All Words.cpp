class Solution {
public:
    bool find(string s, vector<string>& words, int start, int end,int wsize){
        vector<bool>myhash(words.size(),false);
        for(int i=start; i<end; i+=wsize){
            string t = s.substr(i,wsize);
            int j = 0;
            for(; j<words.size(); ++j){
                if(t == words[j] && !myhash[j]){
                    myhash[j] = true;
                    break;
                }
            }
            if(j == words.size())
                return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        if(words.size() == 0) return ret;
        int wsize = words[0].size();
        int wlen = wsize * words.size();
        if(s.size()<wlen) return ret;
        for(int i=0; i<=s.size()-wlen; ++i){
            if(find(s,words,i,i+wlen,wsize))
                ret.push_back(i);
        }
        return ret;
    }
};