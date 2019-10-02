//
// Created by zb198 on 2019/10/2.
//
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead== nullptr){
            return nullptr;
        }
        ListNode* pNode = pHead->next;
        pHead->next = nullptr;
        while (pNode!= nullptr){
            ListNode* pTemp = pNode->next;
            pNode->next = pHead;
            pHead = pNode;
            pNode = pTemp;
            pTemp = nullptr;
        }
        return pHead;
    }
};

