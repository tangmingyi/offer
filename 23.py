# -*- coding:utf-8 -*-
import copy
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def FindKthToTail(self, head:ListNode, k:int)->ListNode:
        if(head==None):
            return None
        pNode = copy.deepcopy(head)
        pKNode = copy.deepcopy(head)
        for _ in range(1,k-1):
            pNode = pNode.next
            if(pNode==None):
                return None
        while(pNode.next!=None):
            pNode = pNode.next
            pKNode = pKNode.next
        return pKNode
# write code here