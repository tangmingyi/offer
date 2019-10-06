# -*- coding:utf-8 -*-
class Solution:
    def isOod(self,num:int)->bool:
        return not self.isEven(num)
    def isEven(self,num:int)->bool:
        return num % 2 == 0
    def reOrderArray(self, array:list)->list:
        OodList = []
        EvenList = []
        for num in array:
            if(self.isOod(num)):
                OodList.append(num)
            else:
                EvenList.append(num)
        OodList.extend(EvenList)
        return OodList
# write code here