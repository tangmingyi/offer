# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None
class Solution:
    # 返回合并后列表
    def init(self,pHead1:ListNode, pHead2:ListNode):
        self.pHead1:ListNode = pHead1
        self.pHead2:ListNode = pHead2
        if(self.pHead1.val<self.pHead2.val):
            self.pHead = self.pHead1
            self.pHead1 = self.pHead1.next
        else:
            self.pHead = self.pHead2
            self.pHead2 = self.pHead2.next
        self.pNode = self.pHead

    def core(self):
        if(self.pHead1.val<self.pHead2.val):
            self.pNode.next = self.pHead1
            self.pHead1 = self.pHead1.next
            self.pNode = self.pNode.next
        else:
            self.pNode.next = self.pHead2
            self.pNode = self.pNode.next
            self.pHead2 = self.pHead2.next

    def Merge(self, pHead1:ListNode, pHead2:ListNode):
        if(pHead1==None and pHead2==None):
            return None
        self.init(pHead1,pHead2)
        while(self.pHead1!=None or self.pHead2!=None):
            self.core()
        if(self.pHead1==None):
            self.pNode.next = self.pHead2
        else:
            self.pNode.next = self.pHead1
        return self.pHead

# write code here