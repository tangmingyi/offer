//
// Created by zb198 on 2019/9/16.
//
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
            val(x), left(nullptr), right(nullptr) {
    }
};
class Solution {
private:
    vector<int > temp;
    vector<vector<int> > result;
    void core(TreeNode* pNode,int target){
        temp.push_back(pNode->val); //pNode opt
        if(target-pNode->val==0&&!pNode->left&&!pNode->right){
            result.push_back(temp);
        } else{
            if(pNode->left)core(pNode->left,target-pNode->val);
            if(pNode->right)core(pNode->right,target-pNode->val);
        }
        temp.pop_back();
    }
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root)core(root,expectNumber);
        return result;
    }
};
