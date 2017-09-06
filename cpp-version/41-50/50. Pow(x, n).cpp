class Solution {
public:
    double myPow(double x, int n) {
        double base = x;
        double res = 1.0;
        bool sign = n>0?true:false;

        //n为最小值转为正数时会溢出
        bool ismin = n == 0x80000000;
        if(ismin) ++n;
        
        n = n>0?n:-n;

        while(n){
            if(n&1){
                res *= base;
            }
            base *= base;
            n >>= 1;
        }
        
        if(ismin) res *= x;
        
        return sign?res:1.0/res;
    }
};