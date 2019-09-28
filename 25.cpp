//
// Created by zb198 on 2019/9/28.
//

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
private:
    ListNode* pHead = nullptr;
    ListNode* pNode = nullptr;
    void updata(ListNode** pHead1, ListNode** pHead2){
        if((*pHead1)->val<(*pHead2)->val){
            if(pNode== nullptr){
                pNode = *pHead1;
                pHead = pNode;
            } else {
                pNode->next = *pHead1;
            }
            *pHead1 = (*pHead1)->next;
        } else{
            if(pNode== nullptr){
                pNode = *pHead2;
                pHead = pNode;
            } else {
                pNode->next = *pHead2;
            }
            *pHead2 = (*pHead2)->next;
        }
        pNode = pNode->next;
    }
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1== nullptr and pHead2== nullptr){
            return nullptr;
        }
        while (pHead1 != nullptr || pHead2!= nullptr){
            updata(&pHead1,&pHead2);
        }
        if(pHead1== nullptr){
            pNode->next = pHead2;
        } else{
            pNode->next = pHead1;
        }
        return pHead;
    }
};

