# -*- coding:utf-8 -*-
class Solution:
    # array 二维列表
    def Find(self, target:int, array:list)->bool:
        rows = len(array)
        cols = len(array[0])
        for col in range(cols-1,-1,-1):
            for row in range(rows):
                if(array[row][col]>target):
                    break
                else:
                    if(array[row][col]==target):
                        return True
        return False

# write code here
if __name__ == '__main__':
    array = [[1,2,8,9],[2,4,9,12],[4,7,10,13],[6,8,11,15]]
    target = 7
    sol = Solution()
    result = sol.Find(target,array)
    print(result)
