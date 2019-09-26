# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def equal(self, pNode1: TreeNode, pNode2: TreeNode) -> bool:
        if(pNode2==None):
            return True
        if(pNode1==None):
            return False
        if(pNode1.val!=pNode2.val):
            return False
        return self.equal(pNode1.left,pNode2.left) and self.equal(pNode1.right,pNode2.right)
    def core(self,pNode1: TreeNode, pNode2: TreeNode)->bool:
        result = False
        if(pNode1!=None and pNode2!=None):
            result = self.equal(pNode1,pNode2)
            if(result == False):
                result = self.core(pNode1.left,pNode2)
            if(result==False):
                result = self.core(pNode1.right,pNode2)
        return result
    def HasSubtree(self, pRoot1:TreeNode, pRoot2:TreeNode):
        return self.core(pRoot1,pRoot2)
# write code here
