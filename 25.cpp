
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(nullptr) {
	}
};
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1== nullptr){
            return pHead2;
        }
        if(pHead2== nullptr){
            return pHead1;
        }
        ListNode* mergerPhead = nullptr;
        if(pHead1->val<pHead2->val){
            mergerPhead = pHead1;
            mergerPhead->next = Merge(pHead1->next,pHead2);
        } else{
            mergerPhead = pHead2;
            mergerPhead->next = Merge(pHead1,pHead2->next);
        }
        return mergerPhead;

    }
};