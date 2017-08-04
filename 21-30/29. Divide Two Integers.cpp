#define LL long long
class Solution {
    public:
    int divide(int dividend, int divisor) {
        if(!divisor || dividend == INT_MIN && divisor ==-1)
            return INT_MAX;
        int f = ((dividend<0) ^ (divisor<0))?-1:1;
        if(divisor ==1) return dividend;
        LL did = llabs(dividend);
        LL div = llabs(divisor);
        LL ret = 0;
        while(div <= did){
            LL mul = 1;
            LL num = div;
            while(did >= (num<<1)){
                num = num<<1;
                mul = mul<<1;
            }
            did -= num;
            ret += mul;
        }
        return f*ret;
    }
};