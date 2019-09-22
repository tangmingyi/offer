# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.result = []
    def _core(self,ss:list,begin:int):
        if(begin==len(ss)):
            string = "".join(ss)
            if(string not in self.result):
                self.result.append(string)
        else:
            for index in range(begin,len(ss)):
                if(ss[index] != ss[begin]):
                    char = ss[index]
                    ss[index] = ss[begin]
                    ss[begin] = char
                self._core(ss,begin+1)
                if(ss[index] != ss[begin]):
                    char = ss[begin]
                    ss[begin] = ss[index]
                    ss[index] = char

    def Permutation(self, ss:str)->list:
        self._core([i for i in ss],0)
        return self.result
# write code here
if __name__ == '__main__':
    handly = Solution()
    result = handly.Permutation("aa")
    print(result)