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