class Solution(object):
    def convert(self, s, numRows):
        if numRows==1 or len(s)<=numRows:
            return s
        myList =['']*numRows
        index,step = 0,1
        for i in s:
            myList[index] += i
            if index==0:
                step = 1
            if index == numRows-1:
                step = -1
            index += step
        return ''.join(myList)