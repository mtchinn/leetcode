class Solution(object):
    def isPalindrome(self, x):
        num0 = str(x)
        num1 = num0[::-1]
        if num0 == num1:
            return True
        return False