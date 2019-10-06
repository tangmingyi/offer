# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base:float, exponent:int)->float:
        result=1.0
        if(exponent==0):
            return 1.0
        else:
            temp = abs(exponent)
            for _ in range(temp):
                result *= base
            if(exponent<0):
                result = 1/result
            return result
# write code here