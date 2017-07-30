//字符串转数字，还要判断是否溢出
class Solution {
public:
    int myAtoi(string str) {
        int start = str.find_first_not_of(' ');
        int sign = 1;
        if(str[start] == '-' || str[start] == '+'){
            sign = (str[start++]=='-')?-1:1;
        }
        int res = 0 ;
        while(start<str.size()){
            if(str[start]>='0' && str[start]<='9'){
                if(res>INT_MAX/10)
                    return (sign==1)?INT_MAX:INT_MIN;
                if(sign == 1 && res==INT_MAX/10 && str[start]>'7')
                    return INT_MAX;
                if(sign == -1 && res==INT_MAX/10 && str[start]>'8')
                    return INT_MIN;
                res = res*10 + str[start++] - '0';
            }
            else break;
        }
        return  sign*res;
    }
};