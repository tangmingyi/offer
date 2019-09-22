# -*- coding:utf-8 -*-
class RandomListNode:
    def __init__(self, x):
        self.label = x
        self.next = None
        self.random = None
class Solution:
    # 返回 RandomListNode
    def Clone(self, pHead:RandomListNode):
        hashMap={}
        pNode = pHead
        while(pNode!=None):
            hashMap[pNode] = RandomListNode(pNode.label)
            pNode = pNode.next
        for key in hashMap:
            hashMap[key].next = hashMap[key.next]
            hashMap[key].random = hashMap[key.random]
        return hashMap[pHead]
# write code here