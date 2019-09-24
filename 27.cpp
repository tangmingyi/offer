//
// Created by zb198 on 2019/9/24.
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
    void core(TreeNode* pNode){
        if(pNode== nullptr){
            return;
        }
        TreeNode* temp = pNode->left;
        pNode->left = pNode->right;
        pNode->right = temp;
        core(pNode->right);
        core(pNode->left);
    }
public:
    void Mirror(TreeNode *pRoot) {
        core(pRoot);
        return;pRoot;
    }
};

