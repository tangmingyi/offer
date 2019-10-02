# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next:ListNode = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead:ListNode)->ListNode:
        if(pHead == None):
            return None
        pNode = pHead.next
        pHead.next = None
        while(pNode!=None):
            pTemp = pNode.next
            pNode.next = pHead
            pHead = pNode
            pNode = pTemp
        return pHead


# write code here