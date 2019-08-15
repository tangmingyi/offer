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

    ListNode* getOneNode(ListNode* pHead, int index){
        int i = 1;
        while(pHead != nullptr){
            if(index==i){
                return pHead;
            }
            pHead = pHead->p_next;
            i++;
        }
        throw "index too big";
    }

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

    ListNode* getListNode(int length){
        ListNode* OneNode = nullptr;
        ListNode** pHead = &OneNode;
        for (int i=1;i<=length;i++){
            AddNodeEnd(pHead,i);
        }
        return *pHead;
    }

    ListNode* getListNode(int length,int (*fun)(int)){
        ListNode* OneNode = nullptr;
        ListNode** pHead = &OneNode;
        for (int i=1;i<=length;i++){
            AddNodeEnd(pHead,fun(i));
        }
        return *pHead;
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

namespace offer_23_1{
    offer_6_1::ListNode* isLoopLinkList(offer_6_1::ListNode* pHead){
        offer_6_1::ListNode* pLast = pHead;
        offer_6_1::ListNode* pFast = pHead->p_next;
        while (pFast != nullptr){
            if(pFast == pLast){
                pFast = nullptr;
                return pLast;
            }
            pLast = pLast->p_next;
            pFast = pFast->p_next->p_next;
        }
        pFast = nullptr;
        pLast = nullptr;
        return nullptr;
    }
    int getLoopNum(offer_6_1::ListNode* pNode){
        int i = 1;
        offer_6_1::ListNode* pTemp = pNode->p_next;
        while(pTemp!=pNode){
            pTemp = pTemp->p_next;
            i++;
        }
        return i;
    }
    offer_6_1::ListNode entryNodeOfLoop(offer_6_1::ListNode* pHead){
        if(pHead== nullptr){
            throw "pHeac == nullptr";
        }
        offer_6_1::ListNode* pNode = nullptr;
        pNode = isLoopLinkList(pHead);
        if(pNode == nullptr){
            throw "linklist is not loop";
        }
        int loopLength = getLoopNum(pNode);
        pNode = nullptr;
        offer_6_1::ListNode* pOne = pHead;
        offer_6_1::ListNode* pTwo = pHead;
        offer_22_1::initPOne(&pOne,loopLength);
        while (pOne->p_next!=pTwo){
            pOne = pOne->p_next;
            pTwo = pTwo->p_next;
        }
        offer_6_1::ListNode loopEntry = *pTwo;
        pOne = nullptr;
        pTwo = nullptr;
        return loopEntry;
    }
}

namespace offer_24_1{
    offer_6_1::ListNode* ReverseList(offer_6_1::ListNode* pHead){
        if(pHead== nullptr){
            throw "linklist is not exit";
        }
        if(pHead->p_next== nullptr){
            return pHead;
        }
        offer_6_1::ListNode* pPreNode = pHead;
        offer_6_1::ListNode* pMidNode = pHead->p_next;
        if(pHead->p_next->p_next== nullptr){
            pHead = pHead->p_next;
            pPreNode->p_next = nullptr;
            pMidNode->p_next = pPreNode;
            pPreNode = nullptr;
            pMidNode = nullptr;
            return pHead;
        }
        offer_6_1::ListNode* pLastNode = pHead->p_next->p_next;
        pPreNode->p_next = nullptr;
        while (pLastNode->p_next!= nullptr){
            pMidNode->p_next = pPreNode;
            pPreNode = pMidNode;
            pMidNode = pLastNode;
            pLastNode = pLastNode->p_next;
        }
        pMidNode->p_next = pPreNode;
        pLastNode->p_next = pMidNode;
        pHead = pLastNode;
        pPreNode = nullptr;
        pMidNode = nullptr;
        pLastNode = nullptr;
        return pHead;
    }
    namespace right{
        offer_6_1::ListNode* ReverseList(offer_6_1::ListNode* pHead){
            offer_6_1::ListNode* pReversedHead = nullptr;
            offer_6_1::ListNode* pNode = pHead;
            offer_6_1::ListNode* pPrev = nullptr;
            while (pNode!= nullptr){
                offer_6_1::ListNode* pNext = pNode->p_next;
                if(pNext== nullptr){
                    pReversedHead = pNode;
                }
                pNode->p_next = pPrev;
                pPrev = pNode;
                pNode = pNext;
            }
            return pReversedHead;
        }
    }
}

namespace offer_25_1{
    offer_6_1::ListNode* Merge(offer_6_1::ListNode* pHead1,offer_6_1::ListNode* pHead2){
        if(pHead1== nullptr&&pHead2== nullptr){
            throw "input have some probem";
        }
        if(pHead1== nullptr){
            return pHead2;
        }else if(pHead2== nullptr){
            return pHead1;
        }
        offer_6_1::ListNode* pMergeHead = nullptr;
        offer_6_1::ListNode* pNode = nullptr;
        offer_6_1::ListNode* pNode1 = pHead1;
        offer_6_1::ListNode* pNode2 = pHead2;
        if(pHead1->value<=pHead2->value){
            pNode = pHead1;
            pMergeHead = pHead1;
            pNode1 = pNode1->p_next;
        }else {
            pNode = pHead2;
            pMergeHead = pHead2;
            pNode2 = pNode2->p_next;
        }
//        bool over = false;
        while (true){
            if(pNode1== nullptr){
                pNode->p_next = pNode2;
                break;
            }else if(pNode2== nullptr){
                pNode->p_next = pNode1;
                break;
            }
            if(pNode1->value <= pNode2->value){
                pNode->p_next = pNode1;
                pNode = pNode->p_next;
                pNode1 = pNode1->p_next;
            } else{
                pNode->p_next = pNode2;
                pNode = pNode->p_next;
                pNode2 = pNode2->p_next;
            }
        }
        return pMergeHead;
    }
    namespace right{
        offer_6_1::ListNode* Merge(offer_6_1::ListNode* pHead1,offer_6_1::ListNode* pHead2){
            if(pHead1== nullptr&&pHead2== nullptr){
                return nullptr;
            }
            if(pHead1== nullptr){
                return pHead2;
            }else if(pHead2== nullptr){
                return pHead1;
            }
            offer_6_1::ListNode* pMerge = nullptr;
            if(pHead1->value<=pHead2->value){
                pMerge = pHead1;
                pMerge->p_next = Merge(pHead1->p_next,pHead2);
            }else{
                pMerge = pHead2;
                pMerge->p_next = Merge(pHead1,pHead2->p_next);
            }
            return pMerge;
        }
    }
}