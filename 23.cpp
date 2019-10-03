//
// Created by zb198 on 2019/10/3.
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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead== nullptr){
            return nullptr;
        }
        ListNode* pKNode = pListHead;
        for (int i = 1; i <=k-1 ; ++i) {
            pListHead = pListHead->next;
            if(pListHead== nullptr){
                return nullptr;
            }
        }
        while (pListHead->next!= nullptr){
            pListHead = pListHead->next;
            pKNode = pKNode->next;
        }
        return pKNode;

    }
};
