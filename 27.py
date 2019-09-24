# -*- coding:utf-8 -*-
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
class Solution:
    # 返回镜像树的根节点
    def core(self,pNode:TreeNode):
        if(pNode==None):
            return
        temp = pNode.left
        pNode.left = pNode.right
        pNode.right = temp
        self.core(pNode.right)
        self.core(pNode.left)
    def Mirror(self, root:TreeNode):
        self.core(root)
        return root
# write code here