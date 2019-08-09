//
// Created by tmy on 19-8-7.
//

#ifndef OFFER_TREE_H
#define OFFER_TREE_H

#endif //OFFER_TREE_H

namespace offer_7_1{
    struct BinaryTreeNode{
      int value;
      BinaryTreeNode* left;
      BinaryTreeNode* right;
      BinaryTreeNode* father;
    };
}

namespace {
//    using namespace offer_7_1;
    offer_7_1::BinaryTreeNode* conpenont(int* preorderStart,int*preorderEnd,int* middleorderStart,int* middleorderEnd,offer_7_1::BinaryTreeNode* father ){
        offer_7_1::BinaryTreeNode* pNewNode = new offer_7_1::BinaryTreeNode();
        pNewNode->value=*preorderStart;
        pNewNode->father=father;
        pNewNode->left = nullptr;
        pNewNode->right = nullptr;
        int* rootmiddleorder = middleorderStart;
        while (*rootmiddleorder!=pNewNode->value){
            rootmiddleorder++;
        }
        int leftlength = rootmiddleorder-middleorderStart;
        //注意建树tiaoijan。
        if (leftlength > 0){
            pNewNode->left = conpenont(preorderStart+1,preorderStart+leftlength,middleorderStart,rootmiddleorder-1,pNewNode);
        }
        if (leftlength < preorderEnd - preorderStart){
            pNewNode->right = conpenont(preorderStart+leftlength+1,preorderEnd,rootmiddleorder+1,middleorderEnd,pNewNode);
        }
        return pNewNode;
    }
}

namespace offer_7_1{

    BinaryTreeNode* Construct(int* preorder,int* middleorder,int length){
        if(preorder== nullptr||middleorder== nullptr||length<=0){
            return nullptr;
        }
        BinaryTreeNode* pHead = conpenont(preorder,preorder+length-1,middleorder,middleorder+length-1, nullptr);
        return pHead;
    }
}

namespace offer_8_1{
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

    offer_7_1::BinaryTreeNode* GetNext(offer_7_1::BinaryTreeNode* pNode){
        if (pNode==nullptr){
            return nullptr;
        }
        if (pNode->right != nullptr){
            pNode = pNode->right;
            while (pNode->left != nullptr){
                pNode = pNode->left;
            }
        } else if (pNode->father->left==pNode){
            pNode = pNode->father;
        } else{
            while (pNode->father->left!=pNode){
                pNode = pNode->father;
            }
        }
        return pNode;
    }
}

