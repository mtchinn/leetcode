// 32位数字转置
class Solution {
public:
    int reverse(long long x) {
        long long mymax = (1<<31)-1;
        long long mymin = 1<<31;
        if(x>mymax || x<mymin)
            return 0;

        bool isneg = false;
        if(x<0) isneg = true, x=-x;
        long long  ret = x%10;
        x/=10;
        while(x){
            ret =ret*10 + x%10;
            x/=10;
        }
        if(ret>mymax || ret<mymin)
            return 0;

        return isneg?-ret:ret;
    }
};