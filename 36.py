# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    def __init__(self):
        self.pEnd = None
        self.Head = None
    def core(self,pNode:TreeNode):
        self.core(pNode.left)
        if(self.Head==None):
            self.pEnd = pNode
            self.Head = pNode
        else:
            self.pEnd.right = pNode
            pNode.left = self.pEnd
            self.pEnd = pNode
        self.core(pNode.right)

    def Convert(self, pRootOfTree):
        self.core(pRootOfTree)
        return self.Head
