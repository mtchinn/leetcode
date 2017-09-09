class Solution(object):
    def myAtoi(self, str):
        str = str.strip()
        str = re.findall('^[\+\-0]?\d+',str)

        INT_MAX = 2**31-1
        INT_MIN = -2**31
        try:
            res = int(''.join(str))
            if res > INT_MAX:
                return INT_MAX
            if res < INT_MIN:
                return INT_MIN
            return res
        except:
            return 0
