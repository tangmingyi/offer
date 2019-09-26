//
// Created by zb198 on 2019/9/26.
//

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(nullptr), right(nullptr) {
	}
};
class Solution {
private:
    bool equal(TreeNode* pNode1,TreeNode* pNode2){
        if(pNode2== nullptr){
            return true;
        }
        if(pNode1== nullptr){
            return false;
        }
        if(pNode1->val!=pNode2->val){
            return false;
        }
        return equal(pNode1->left,pNode2->left) && equal(pNode1->right,pNode2->right);
    }
    bool core(TreeNode* pNode,TreeNode* pRoot){
        bool result = false;
        if(pNode!= nullptr && pRoot!= nullptr){
            result = equal(pNode,pRoot);
            if(!result){
                result = core(pNode->left,pRoot);
            }
            if(!result){
                result = core(pNode->right,pRoot);
            }
        }
        return result;
    }
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        return core(pRoot1,pRoot2);
    }
};

