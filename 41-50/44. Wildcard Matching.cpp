//抄的discuss一边调一边敲的啊啊啊啊啊
//读书人的事情能叫抄吗？！啊啊啊啊啊
//窝好菜啊~~
class Solution {
public:
    bool isMatch(string str, string pattern) {
        int s = 0, p = 0,match = 0, index = -1;
        while(s<str.size()){
            if(str[s] == pattern[p] || pattern[p] == '?'){
                ++s;
                ++p;
            }else if(pattern[p] == '*'){
                index = p;
                match = s;
                ++p;
            }else if(index != -1){
                ++match;
                s = match;
                p = index+1;
            }else return false;
        }
        while(p<pattern.size() && pattern[p] == '*')
            ++p;
        return p == pattern.size();
    }
};