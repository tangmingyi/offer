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
bool comp(vector<int>& a,vector<int >& b){
    return a.size() < b.size();
}
class Solution {
public:
    stack<int > s;
    int sum=0;
    vector<vector<int> > result;
    vector<int > getResult(){
        stack<int> temp = s;
        vector<int > List(s.size());
        for(int i=s.size()-1;i>=0;i--){
            List[i] = temp.top();
            temp.pop();
        }
        return List;
    }
    void update(){
        sum-=s.top();
        s.pop();
    }
    void NodeOpe(TreeNode* pNode){
        s.push(pNode->val);
        sum += pNode->val;
    }
    void core(TreeNode* pNode,int target){
        if(pNode== nullptr){
            if(sum==target){
                result.push_back(getResult());
            }
            update();
            return;
        }
        NodeOpe(pNode);
        core(pNode->left,target);
        core(pNode->right,target);
        update();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        core(root,expectNumber);
        sort(result.begin(),result.end(),comp);
        return result;
    }
};
