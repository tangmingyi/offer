//
// Created by zb198 on 2019/9/22.
//
#include <map>
using namespace std;
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(nullptr), random(nullptr) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode&,RandomListNode&> hashMap;
        RandomListNode* pNode = pHead;
        while(pNode->next!= nullptr){
            hashMap[pNode] = RandomListNode(pNode->label);
            pNode = pNode->next;
        }
        for(auto Iter = hashMap.begin();Iter!=hashMap.end();Iter++){
            Iter->second.next = hashMap[Iter->first.next];
            Iter->second.random = hashMap[Iter->first.random];
        }
        return hashMap[pHead];
    }
};
