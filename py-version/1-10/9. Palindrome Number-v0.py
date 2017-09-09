class Solution(object):
    def isPalindrome(self, x):
        if x<0 or (x!=0 and x%10==0):
            return False
        res = 0
        while res<x:
            res =res*10+ x%10
            x/=10
        if res==x or (res/10==x):
            return True
        return False