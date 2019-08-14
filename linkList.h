//
// Created by tmy on 19-8-7.
//

#ifndef OFFER_PRINT_LIST_REVERSINGLY_6_H
#define OFFER_PRINT_LIST_REVERSINGLY_6_H

#include <stack>
#include <iostream>
#endif //OFFER_PRINT_LIST_REVERSINGLY_6_H
namespace offer_6_1 {
    struct ListNode{
        int value;
        ListNode* p_next;
    };
    void printLinkList(ListNode* pHead){
        printf("Head");
        ListNode* pNode = pHead;
        while (pNode != nullptr){
            printf("-> %d",pNode->value);
            pNode = pNode->p_next;
        }
        printf("\n");
    }
    //链表尾部添加节点
    void AddNodeEnd(ListNode** pHead, int value){
        ListNode* pNew = new ListNode();
        pNew ->value = value;
        pNew ->p_next = nullptr;
        if (*pHead== nullptr){
            *pHead = pNew;
        } else{
            ListNode* pNode = *pHead;
            while (pNode->p_next!= nullptr){
                pNode = pNode->p_next;
            }
            pNode->p_next = pNew;
        }
    }

    void print_list_reversing(ListNode* pHead) { //这里不需要改变头指针，因此不需要二级头指。
        std::stack<int> s;

        ListNode* pNode = pHead;
        while(pNode != nullptr) {
            s.push(pNode->value);
            pNode = pNode->p_next;
        }

        while (! s.empty()){
            printf("%d ",s.top());
            s.pop();
        }

    }
}

namespace offer_18_1{
    void DeleteNode(offer_6_1::ListNode** pListHead,offer_6_1::ListNode* pToBeDeleted){
        if(pListHead== nullptr||pToBeDeleted== nullptr){
            printf("input have some probrom place chack");
            return;
        }
        if(pToBeDeleted->p_next!= nullptr){
            pToBeDeleted->value = pToBeDeleted->p_next->value;
            offer_6_1::ListNode *pTemp = pToBeDeleted->p_next;
            pToBeDeleted->p_next = pToBeDeleted->p_next->p_next;
            delete pTemp;
            pTemp = nullptr;
        }else if(*pListHead==pToBeDeleted){
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
            *pListHead = nullptr;
        }else {
            offer_6_1::ListNode* pNode = *pListHead;
            while(pNode->p_next!= pToBeDeleted){
                pNode = pNode->p_next;
            }
            pNode->p_next= nullptr;
            delete pToBeDeleted;
            pToBeDeleted= nullptr;
        }
    }
}

namespace offer_18_2{
    void deleteDuplication(offer_6_1::ListNode** pHead){
        if(*pHead== nullptr||pHead== nullptr){
            return;
        }
        offer_6_1::ListNode* pNode = *pHead;
        bool duplicat = false;
        offer_6_1::ListNode* deleteNode = nullptr;
        while(pNode->p_next != nullptr){
            if(pNode->value == pNode->p_next->value){
                deleteNode = pNode->p_next;
                pNode->p_next = deleteNode->p_next;
                delete deleteNode;
                deleteNode = nullptr;
                duplicat = true;
            } else {
                if(duplicat) {
                    deleteNode = *pHead;
                    if (*pHead == pNode) {
                        *pHead = pNode->p_next;
                        pNode = pNode->p_next;
                        delete deleteNode;
                        deleteNode = nullptr;
                        duplicat = false;
                        continue;
                    } else {
                        while (deleteNode->p_next != pNode) {
                            deleteNode = deleteNode->p_next;
                        }
                        pNode = deleteNode;
                        deleteNode = deleteNode->p_next;
                        pNode->p_next = deleteNode->p_next;
                        delete deleteNode;
                        deleteNode = nullptr;
                        duplicat = false;
                    }
                }
                pNode = pNode->p_next;
            }
        }
        if(duplicat){
            deleteNode = *pHead;
            if(deleteNode->p_next!=pNode){
                deleteNode = deleteNode->p_next;
            }
            pNode = deleteNode;
            deleteNode = deleteNode->p_next;
            pNode->p_next = nullptr;
            delete deleteNode;
            deleteNode = nullptr;
        }
    }
}

namespace offer_22_1{
    bool initPOne(offer_6_1::ListNode** pOne ,int k){
        offer_6_1::ListNode* pNode = *pOne;
        for(int i=1;i<k;i++){
            if(pNode->p_next== nullptr){
                return false;
            }
            pNode = pNode->p_next;
        }
        *pOne = pNode;
        pNode = nullptr;
        return true;
    }
    int printLinkListK(offer_6_1::ListNode* pHead,int k){
        if(pHead== nullptr || k<1){
            throw "input have probrom";
        }
        offer_6_1::ListNode* pOne = pHead;
        offer_6_1::ListNode* pTwo = pHead;
        bool pStatus = initPOne(&pOne,k);
        if(!pStatus){
            throw "k may be too big than linklist total length";
        }
        while (pOne->p_next!= nullptr){
            pOne = pOne->p_next;
            pTwo = pTwo->p_next;
        }
        return pTwo->value;
    }
}