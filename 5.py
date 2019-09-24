# -*- coding:utf-8 -*-
class Solution:
    # s 源字符串
    def replaceSpace(self, s:str)->str:
        s = [i for i in s]
        for index,char in enumerate(s):
            if(char==" "):
                s[index]="%20"
        return "".join(s)
# write code here
if __name__ == '__main__':
    sol = Solution()
    string = "We Are Happy"
    string = sol.replaceSpace(string)
    print(string)
