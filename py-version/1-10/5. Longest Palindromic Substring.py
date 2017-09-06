class Solution(object):
    def extendStr(self,s,start,end):
        radius = 0
        start -= 1
        end += 1
        while start>-1 and end<len(s) and s[start]==s[end]:
            radius += 1
            start -= 1
            end +=1
        return radius

    def longestPalindrome(self, s):
        ret = ""
        maxlen = 0
        start=0
        end =0
        #print("start")
        for i in range(len(s)):
            if (len(s)-i)<maxlen/2:
                break
            r1 = self.extendStr(s,i,i)
            len1 = r1*2+1
            if len1>maxlen:
                start = i-r1
                end = start + len1
                maxlen = len1
            if i+1<len(s) and s[i]==s[i+1]:
                r2 = self.extendStr(s,i,i+1)
                len2 = r2*2+2
                if len2>maxlen:
                    start = i-r2
                    end = start + len2
                    maxlen = len2
        return s[start:end]
