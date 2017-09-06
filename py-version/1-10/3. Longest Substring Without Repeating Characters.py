class Solution(object):
    def lengthOfLongestSubstring(self, s):
        pre_char = {}
    
        maxlen = 0
        start = -1
        for i in range(len(s)):
            index = -1
            if s[i] in pre_char:
                index = pre_char[s[i]]
            start = max(start,index)
            pre_char[s[i]] = i
            maxlen = max(maxlen,i-start)
        return maxlen