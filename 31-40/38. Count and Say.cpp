class Solution {
public:
    string countAndSay(int n) {
        string ret("1");
        while(--n){
            string t("");
            for(int i=0; i<ret.size(); ++i){
                int repeat = 1;
                while((i+1)<ret.size() && ret[i+1] == ret[i]){
                    ++repeat;
                    ++i;
                }
                char c = repeat + '0';
                t.push_back(c);
                c = ret[i];
                t.push_back(c);
            }
            ret = t;
        }
        return ret;
    }
};