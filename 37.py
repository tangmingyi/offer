import _io
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
def serialization(wf:_io.TextIOWrapper,pNode:TreeNode):
    if(pNode==None):
        wf.write("$\n")
        return
    else:
        wf.write(str(pNode.val)+"\n")
    serialization(wf,pNode.left)
    serialization(wf,pNode.right)

def deserialization(rf:_io.TextIOWrapper)->TreeNode:
    pNode = TreeNode(int(rf.readline()))
    pNode.left = deserialization(rf)
    pNode.right = deserialization(rf)
    return pNode
