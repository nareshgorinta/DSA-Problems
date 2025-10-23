class Solution(object):
    def hasSameDigits(self, s):
        """
        :type s: str
        :rtype: bool
        """
        while(len(s) != 2):
            a=''
            for i in range(1,len(s)):
                val = (int(s[i]) + int(s[i-1]) )%10
                a+= str(val)
            s=a
        if(s[0] == s[1]):
            return True
        return False

        