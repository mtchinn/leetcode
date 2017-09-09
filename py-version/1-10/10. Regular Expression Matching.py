class Solution(object):
    def isMatch(self, s, p):
        m = len(s)
        n = len(p)
        dp = [[False for i in range(n+1)] for i in range(m+1)]
        dp[0][0] = True
        for i in range(1,n):
            dp[0][i+1] = dp[0][i-1] and p[i]=='*'

        for i in range(m):
            for j in range(n):
                if s[i]==p[j] or p[j] == '.':
                    dp[i+1][j+1] = dp[i][j]
                if p[j]=='*':
                    if s[i]!=p[j-1] and p[j-1]!='.':
                        dp[i+1][j+1] = dp[i+1][j-1]
                    else:
                        dp[i+1][j+1] = dp[i][j+1] or dp[i+1][j] or dp[i+1][j-1]
        return dp[m][n]