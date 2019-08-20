//
// Created by tmy on 19-8-7.
//

#ifndef OFFER_TREE_H
#define OFFER_TREE_H

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#endif //OFFER_TREE_H
namespace tree {
    struct BinaryTreeNode {
        int value;
        BinaryTreeNode *left;
        BinaryTreeNode *right;
        BinaryTreeNode *father;
    };
    namespace tool {
        void Traversal(BinaryTreeNode *root, void (*RootOpt)(BinaryTreeNode *), int rule = 1) {
            if (root == nullptr) {
                RootOpt(root);
                return;
            }
            if (rule == 1) {        //前序遍历
                RootOpt(root);
                Traversal(root->left, RootOpt, rule);
                Traversal(root->right, RootOpt, rule);
            } else if (rule == 2) {      //中序遍历
                Traversal(root->left, RootOpt, rule);
                RootOpt(root);
                Traversal(root->right, RootOpt, rule);
            } else { //后序遍历
                Traversal(root->left, RootOpt, rule);
                Traversal(root->right, RootOpt, rule);
                RootOpt(root);
            }
        }


        void __printTree(BinaryTreeNode *root) {
            if(root != nullptr) {
                printf("%d--", root->value);
            }
        }

        void printTree(BinaryTreeNode *root, int rule = 1) {
            Traversal(root, __printTree, rule);
        }


    }
}

namespace {
//    using namespace offer_7_1;
    tree::BinaryTreeNode *conpenont(int *preorderStart, int *preorderEnd, int *middleorderStart, int *middleorderEnd,
                                    tree::BinaryTreeNode *father) {
        tree::BinaryTreeNode *pNewNode = new tree::BinaryTreeNode();
        pNewNode->value = *preorderStart;
        pNewNode->father = father;
        pNewNode->left = nullptr;
        pNewNode->right = nullptr;
        int *rootmiddleorder = middleorderStart;
        while (*rootmiddleorder != pNewNode->value) {
            rootmiddleorder++;
        }
        int leftlength = rootmiddleorder - middleorderStart;
        //注意建树tiaoijan。
        if (leftlength > 0) {
            pNewNode->left = conpenont(preorderStart + 1, preorderStart + leftlength, middleorderStart,
                                       rootmiddleorder - 1, pNewNode);
        }
        if (leftlength < preorderEnd - preorderStart) {
            pNewNode->right = conpenont(preorderStart + leftlength + 1, preorderEnd, rootmiddleorder + 1,
                                        middleorderEnd, pNewNode);
        }
        return pNewNode;
    }
}

namespace offer_7_1 {

    tree::BinaryTreeNode *Construct(int *preorder, int *middleorder, int length) {
        if (preorder == nullptr || middleorder == nullptr || length <= 0) {
            return nullptr;
        }
        tree::BinaryTreeNode *pHead = conpenont(preorder, preorder + length - 1, middleorder, middleorder + length - 1,
                                                nullptr);
        return pHead;
    }
}

namespace tree {
    namespace tool {
        //根据前序遍历和中序遍历拿到二叉树。
        BinaryTreeNode *getTree(int *preorder, int *middleorder, int length) {
            return offer_7_1::Construct(preorder, middleorder, length);
        }
    }
}

namespace offer_8_1 {
//    void precessNode(BinaryTreeNode* pNode){
//        if (pNode->left != nullptr) {
//            pNode->left->father = pNode;
//        }
//        if (pNode->right != nullptr) {
//            pNode->right->father = pNode;
//        }
//    }
//
//    void handly_node(BinaryTreeNode*pNode) {
////        BinaryTreeNode* pNode = pHead;
//        precessNode(pNode);
//        if (pNode->left != nullptr) {
//            handly_node(pNode->left);
//        }
//        if (pNode->right != nullptr) {
//        handly_node(pNode->right);
//        }
//    }
//
//    BinaryTreeNode* build_tree(int* preorder,int* middleorder,int length){
//        BinaryTreeNode* pHead = offer_7_1::Construct(preorder,middleorder,length);
//        handly_node(pHead);
//        return pHead;
//    }

    tree::BinaryTreeNode *GetNext(tree::BinaryTreeNode *pNode) {
        if (pNode == nullptr) {
            return nullptr;
        }
        if (pNode->right != nullptr) {
            pNode = pNode->right;
            while (pNode->left != nullptr) {
                pNode = pNode->left;
            }
        } else if (pNode->father->left == pNode) {
            pNode = pNode->father;
        } else {
            while (pNode->father->left != pNode) {
                pNode = pNode->father;
            }
        }
        return pNode;
    }
}

namespace offer_26_1 {
    bool core(tree::BinaryTreeNode *pRoot1, tree::BinaryTreeNode *pRoot2) {
        if (pRoot2 == nullptr) {
            return true;
        }
        if (pRoot1 == nullptr) {
            return false;
        }
        if (pRoot1->value == pRoot2->value) {
            return core(pRoot1->left, pRoot2->left) && core(pRoot1->right, pRoot2->right);
        }
        return false;
    }

    bool Traversal(tree::BinaryTreeNode *pRoot1, tree::BinaryTreeNode *pRoot2) {
        bool result = false;
        if (pRoot1 == nullptr) {
            return false;
        }
        if (pRoot1->value == pRoot2->value) {
            result = core(pRoot1, pRoot2);
        }
        if (!result) {
            result = Traversal(pRoot1->left, pRoot2);
        }
        if (!result) {
            result = Traversal(pRoot1->right, pRoot2);
        }
        return result;
    }

    bool HasSubtree(tree::BinaryTreeNode *pRoot1, tree::BinaryTreeNode *pRoot2) {
        if (pRoot1 == nullptr || pRoot2 == nullptr) {
            return false;
        }
        return Traversal(pRoot1, pRoot2);
    }
}
namespace offer_27_1 {
    void exchange(tree::BinaryTreeNode *pNode) {
        if (pNode != nullptr) {
        tree::BinaryTreeNode *pTemp = pNode->left;
        pNode->left = pNode->right;
        pNode->right = pTemp;
        }
    }

    void MirrorRecursively(tree::BinaryTreeNode *pRoot) {
        if (pRoot == nullptr) {
            return;
        }
        tree::tool::Traversal(pRoot, exchange);
    }
}

namespace offer_28_1 {
    bool isSymmertrical(tree::BinaryTreeNode *pRoot1, tree::BinaryTreeNode *pRoot2) {
        if(pRoot1== nullptr && pRoot2== nullptr){
            return true;
        }
        if(pRoot1== nullptr || pRoot2== nullptr){
            return false;
        }
        if (pRoot1->value == pRoot2->value) {
            return isSymmertrical(pRoot1->left, pRoot2->right) && isSymmertrical(pRoot1->right, pRoot2->left);
        }
        return false;
    }

    bool isSymmertrical(tree::BinaryTreeNode *pRoot) {
        if (pRoot == nullptr) {
            return false;
        }
        if(pRoot->right== nullptr && pRoot->left== nullptr){
            return true;
        }
        return isSymmertrical(pRoot->left,pRoot->right);
    }
}

namespace offer_37_1{
    void Serialize(tree::BinaryTreeNode* pRoot,std::ofstream& out){
        if(pRoot== nullptr){
            out<<"$,";
            return;
        }
        out<<pRoot->value<<',';
        Serialize(pRoot->left,out);
        Serialize(pRoot->right,out);
    }
    void core(tree::BinaryTreeNode** pHead, char* nums,int index){
        if(!(nums[index]=='\0'||nums[index]=='$')) {
            *pHead = new tree::BinaryTreeNode();
            (*pHead)->value = nums[index] - '0';
            (*pHead)->left = nullptr;
            (*pHead)->right = nullptr;
            index++;
            core(&(*pHead)->left, nums, index);
            index++;
            core(&(*pHead)->right, nums, index);
        }
    }
    tree::BinaryTreeNode* Deserialize(char* nums,int length){
        if(nums == nullptr || length<=0){
            return nullptr;
        }
        tree::BinaryTreeNode* pHead = nullptr;
        core(&pHead,nums,0);
        return pHead;
    }
}

namespace offer_32_1{
    std::vector<int> PrintFromTopToBottom(tree::BinaryTreeNode* root) {
        std::vector<int> ver;
        if(root == nullptr) return ver;
        std::queue<tree::BinaryTreeNode> temp;
        temp.push(*root);
        while (!temp.empty()){
            tree::BinaryTreeNode a = temp.front();
            if(a.left!= nullptr) {
                temp.push(*(a.left));
            }
            if(a.right!= nullptr) {
                temp.push(*(a.right));
            }
            temp.pop();
            ver.push_back(a.value);
        }
        return ver;
    }
}

namespace offer_33_1{
    bool core(std::vector<int> sequence,int start,int end){
        if(start==-1 || start==end){
            return true;
        }
        int bigStart = -1;
        int bigEnd = -1;
        int smallStart = -1;
        int smallEnd = -1;
        int root = sequence[end];
        bool haveSmall = false;
        bool haveBig = false;
        if(sequence[start]<root){
            smallStart = start;
            haveSmall = true;
        }
        for(int i = start+1;i<=end;i++){
            if(!haveSmall && sequence[i]<root){
                return false;
            }
            if(sequence[i]>root){
                if(!haveBig){
                    if(haveSmall) {
                        smallEnd = i - 1;
                    }
                    bigStart = i;
                    haveSmall = false;
                    haveBig = true;
                }
            }
        }
        if(haveBig){
            bigEnd = end-1;
        }
        if(haveSmall){
            smallEnd = end-1;
        }

        return core(sequence,smallStart,smallEnd) && core(sequence,bigStart,bigEnd);

    }
    bool VerifySquenceOfBST(std::vector<int> sequence) {
        if(sequence.empty()){
            return false;
        }
        return core(sequence,0,sequence.size()-1);
    }

    void test(){
        std::vector<int> sequence({7,4,6,5});
        if(VerifySquenceOfBST(sequence)){
            printf("ture");
        }else{
            printf("false");
        }
    }
    namespace right{
        bool core(std::vector<int> sequence,int start,int end){
            if(sequence.empty()||start>end){
                return false;
            }
            int root = sequence[end];
            int i = start;
            for(i;i<end;i++){
                if(sequence[i]>root){
                    break;
                }
            }
            for (int j=i;j<end;j++){
                if(sequence[j]<root){
                    return false;
                }
            }
            bool left = true;
            if(i>start){
                left = core(sequence,start,i-1);
            }

            bool right = true;
            if(i<end-1){
                right = core(sequence,i,end-1);
            }
            return left&&right;
        }
        bool VerifySquenceOfBST(std::vector<int> sequence) {
            return core(sequence,0,sequence.size()-1);
        }
    }
}