class Solution {
public:
    void generate(vector<string>&ret,string str,int n, int m){
        if(n==0 && m==0){
            ret.push_back(str);
            return;
        }
        if(n>0) generate(ret,str+"(",n-1,m);
        if(m>0 && m>n) generate(ret,str+")",n,m-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ret;
        generate(ret,"",n,n);
        return ret;
    }
};