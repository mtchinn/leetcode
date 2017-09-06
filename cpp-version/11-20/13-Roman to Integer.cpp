class Solution {
public:
    // I 1 V 5 X 10 L 50 C 100 D 500 M1000
    int romanToInt(string s) {
        int ret = 0;
        for(int i=0; i<s.size(); ++i){
            if(s[i]=='M'){
                ret += 1000;
            }else if(s[i]=='D'){
                ret += 500;
            }else if(s[i]=='C')
                ret+=100;
            else if(s[i]=='L')
                ret+=50;
            else if(s[i]=='X')
                ret+=10;
            else if(s[i]=='V')
                ret+=5;
            else if(s[i]=='I')
                ++ret;
        }
        if(s.find("CM")!=-1){
            ret-=200;
        }
        if(s.find("CD")!=-1){
            ret-=200;
        }
        if(s.find("XC")!=-1){
            ret-=20;
        }
        if(s.find("XL")!=-1){
            ret-=20;
        }
        if(s.find("IX")!=-1){
            ret-=2;
        }
        if(s.find("IV")!=-1){
            ret-=2;
        }
        return ret;
    }
};