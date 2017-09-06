class Solution {
public:
    string add(string num1, string num2){
        int len1 = num1.size();
        int len2 = num2.size();
        string str("");
        int jz = 0;
        int i=0, j=0;
        for(; i<len1&&j<len2; ++i,++j){
            int sum = num1[i] - '0' + num2[j] - '0' + jz;
            str.push_back(sum%10 + '0');
            jz = sum/10;
        }
        while(i<len1){
            int sum = num1[i] - '0' + jz;
            str.push_back(sum%10 + '0');
            jz = sum/10;
            ++i;
        }
        while(j<len2){
            int sum = num2[j] - '0' + jz;
            str.push_back(sum%10 + '0');
            jz = sum/10;
            ++j;
        }
        while(jz){
            str.push_back(jz%10 + '0');
            jz/=10;
        }
        return str;
    }
    string multiByOneNum(string str, int x){
        string ret("");
        int len = str.size();
        int jz = 0;
        for(int i=0; i<len; ++i){
            int sum = (str[i]-'0') * x + jz;
            ret.push_back(sum%10+'0');
            jz = sum / 10;
        }
        while(jz){
            ret.push_back(jz%10 + '0');
            jz/=10;
        }
        //reverse(ret.begin(),ret.end());
        return ret;
    }
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        int len2 = num2.size();
        int len1 = num1.size();
        string ret("");
        int i=0;
        while((num2[i]-'0') == 0){
            ++i;
        }
        int k = i;
        for(; i<len2; ++i){
            string str = multiByOneNum(num1,num2[i]-'0');
            str.insert(0,i-k,'0');
            ret = add(ret,str);
        }
        reverse(ret.begin(),ret.end());
        while(k--){
            ret.push_back('0');
        }
        return ret;
    }
};