class Solution {
public:
   string intToRoman(int num) {
        string I[10]={"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string X[10]={"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        string C[10]={"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        string M[4]={"","M","MM","MMM"};
        string ret;
        ret.append(M[num/1000]);
        ret.append(C[(num%1000)/100]);
        ret.append(X[(num%100)/10]);
        ret.append(I[num%10]);
        return ret;
    }
};