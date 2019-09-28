# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    # 返回合并后列表
    def Merge(self, pHead1:ListNode, pHead2:ListNode)->ListNode:
        if(pHead1==None):
            return pHead2
        if(pHead2==None):
            return pHead1
        mergePhead = None
        if(pHead1.val<pHead2.val):
            mergePhead = pHead1
            mergePhead.next = self.Merge(pHead1.next,pHead2)
        else:
            mergePhead = pHead2
            mergePhead.next = self.Merge(pHead1,pHead2.next)
        return mergePhead


# write code here