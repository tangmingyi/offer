# -*- coding:utf-8 -*-
class Solution:
    def isOod(self,num:int)->bool:
        return not self.isEven(num)
    def isEven(self,num:int)->bool:
        return num % 2 == 0
    def reOrderArray(self, array:list)->list:
        if(len(array)==0):
            return array
        pOod = 0
        pEven = len(array)-1
        while(not (pEven==pOod or pEven<pOod)):
            if(self.isOod(array[pEven]) and self.isEven(array[pOod])):
                temp = array[pOod]
                array[pOod] = array[pEven]
                array[pEven] = temp
                pOod += 1
                pEven -= 1
            else:
                if(self.isOod(array[pOod])):
                    pOod += 1
                else:
                    pEven -= 1
        return array
# write code here