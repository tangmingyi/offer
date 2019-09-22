//
// Created by zb198 on 2019/9/22.
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
public:
    TreeNode* pEnd= nullptr;
    TreeNode* Head = nullptr;
    void core(TreeNode* pNode){
        if(pNode== nullptr)
            return;
        core(pNode->left);
        if(Head== nullptr){
            Head = pNode;
            pEnd = pNode;
        } else{
            pEnd->right=pNode;
            pNode->left=pEnd;
            pEnd = pNode;
        }
        core(pNode->right);
    }
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        core(pRootOfTree);
        return Head;
    }
};

