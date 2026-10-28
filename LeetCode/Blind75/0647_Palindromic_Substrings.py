# 647. Palindromic Substrings
# https://leetcode.com/problems/palindromic-substrings/

class Solution:
    def countSubstrings(self, s: str) -> int:

        n = len(s)

        c = 0
        for i in range(0,n):
            
            # l = i, r = i
            l , r = i, i
            while True:
                if l >= 0 and r <= n-1 and s[l] == s[r]:
                    c+=1
                    l-=1
                    r+=1
                else:
                    break
                
        for i in range(0,n-1):
            
            l, r = i, i+1
            while True:
                if l >= 0 and r <= n-1 and s[l] == s[r]:
                    c+=1
                    l-=1
                    r+=1
                else:
                    break

        return c
