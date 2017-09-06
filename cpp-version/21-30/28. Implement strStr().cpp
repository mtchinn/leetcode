class Solution {
public:
	// 酱紫算作弊吗？ Σ(っ°Д°;)っ
    int strStr(string haystack, string needle) {
        if(needle.compare("") == 0 ) return 0;
        return haystack.find(needle);
    }
};