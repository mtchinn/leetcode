class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string alphas[11]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ret;
        if(digits.size()==0 || digits == "")
            return ret;
        int d = digits[0]-'0';
        for(int i=0; i<alphas[d].size(); ++i) {
            string s = alphas[d].substr(i,1);
            ret.push_back(s);
        }
        for(int i=1; i<digits.size(); ++i){
            int d = digits[i]-'0';
            vector<string> t;
            for(int j=0; j<alphas[d].size(); ++j){
                for(int k=0; k<ret.size(); ++k){
                    string s(ret[k]);
                    s.append(alphas[d].substr(j,1));
                    t.push_back(s);
                }
            }
            ret = t;
        }
        return  ret;
    }
};