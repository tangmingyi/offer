#include <iostream>
#include "duplicate_num_3.h"
#include "duplicate_num_4.h"
#include "charOpe.h"
#include "linkList.h"
#include "tree.h"
#include "stackAndQueue.h"
#include "DynamicPlan.h"
#include "SortAndFind.h"
#include "list.h"
#include "bitOper.h"
//using namespace ios;
//3.1
//int main() {
//    int lenght=7;
//    int num_list[7] = {2,3,1,0,2,5,3};
//    int temp = 0;
//    int* duplicate=&temp;   //声明空指针报错
//    if (offer3_1::duplicate(num_list,lenght,duplicate)) {
//        printf("have duplicate num:%d",*duplicate);
//    }
//    else{
//        printf("have not duplicate.");
//    }
//    return 0;
//}

//3.2
//int main(){
//    int length = 7;
//    int num_list[length] = {7,3,1,1,2,5,3};
//    int duplicate = offer3_2::duplicate(num_list,length);
//    if (duplicate != -1){
//        printf("duplicate number is: %d",duplicate);
//    } else{
//        printf("have some problem,not fint duplicaqte.");
//    }
//    return 0;
//}

//4
namespace offer_4_1 {
    void test() {
        int rows = 4;
        int columns = 4;
        int matrix[] = {1, 2, 8,9,2, 4, 9,12,4,7,10,13,6, 8, 11, 15};
        int found_num = 7;
        if (duplicate(matrix, rows, columns, found_num)) {
            printf("have find duplicate number");
        } else {
            printf("not fount duplicate number");
        }
    }
}

//5
namespace offer_5_1{
    void test(){
        int lenght = 100;
        char string[lenght] = "we are happy";
        printf("old string is %s\n",string);
        replace_blank(string,lenght);
        printf("new string is %s",string);
    }
}

namespace offer_6_1{
    void test(){
        ListNode* OneNode = nullptr;
        ListNode** pHead = &OneNode;
        int lenght = 3;
        for (int i=0;i<lenght;i++){
            AddNodeEnd(pHead,i);
        }
        print_list_reversing(*pHead);

    }
}
namespace offer_7_1{
    void test(){
        int length = 9;
        int preorder[length] = {1,2,4,5,8,9,3,6,7};
        int middleorder[length] = {4,2,8,5,9,1,6,3,7};
        BinaryTreeNode* pHead;
        pHead = Construct(preorder,middleorder,length);
        BinaryTreeNode* a=pHead;
        BinaryTreeNode* b = a->right;
        BinaryTreeNode* c = b->left;
//        BinaryTreeNode* d = c->right;
        printf("%d -> %d -> %d \n",a->value,b->value,c->value);
        printf("%d",c->father->value);
    }
}

namespace offer_8_1{
    void test(){
        int length = 9;
        int preorder[length] = {1,2,4,5,8,9,3,6,7};
        int middleorder[length] = {4,2,8,5,9,1,6,3,7};
        offer_7_1::BinaryTreeNode* pHead = offer_7_1::Construct(preorder,middleorder,length);
        offer_7_1::BinaryTreeNode* pNext = GetNext(pHead);
        printf("%d -> %d",pHead->value,pNext->value);
    }
}
namespace offer_9_1{
    void test(){
        CQueue<int> queue;
        int length=10;
        for (int i=0;i<length;i++) {
            queue.appendTail(i);
        }
        queue.deleteHead();

    }
}

namespace offer_10_1{
    void test(){
        unsigned n = 5;
        printf("%d",Fibonacci(n));
    }
}

namespace sort{
    void test(){
        int length = 5;
        int data[length] = {2,4,1,2,9};
        QuickSort(data,length,0,length-1);
        for (int i=0;i<length;i++){
            printf("%d",data[i]);
        }
    }

}

namespace offer_11_1{
    void test() {
        int length = 4;
        int data[length] = {1,0,1,1};
        int a = Min(data,length);
        printf("%d",a);
    }

}
namespace offer_12_1{
    void test(){
        int rows = 3;
        int cols = 4;
        char martrix[rows*cols] = {'a','b','t','g','c','f','c','s','j','d','e','h'};
        char strs[] = "abfb";
//        char* str = strs;
        if(hasPath(martrix,rows,cols,strs)){
            printf("have path for string: %s",strs);
        } else{
            printf("have not path for str: %s",strs);
        }
    }
}
namespace offer_13_1{
    void test(){
        int threshold=6;
        int rows=10;
        int cols=10;
        printf("count is %d",movingCount(threshold, rows, cols));
    }
}

namespace offer_14_1{
    void test(){
        int length = 6;
        printf("max result is %d",maxProduct(length));
    }
}

namespace offer_15_1{
    void test(){
        int number = 9;
        printf("number %d have %d number of 1",number,NumberOf1(number));
    }
}

namespace offer_16_1{
    void test(){
        double base = 9.0;
        int expont = -3;
        double resoult = Power(base,expont);
        printf("%f ^ %d = %f",base,expont,resoult);
    }
}

namespace offer_18_1{
    void test(){
        offer_6_1::ListNode* OneNode = nullptr;
        offer_6_1::ListNode** pHead = &OneNode;
        int lenght = 3;
        for (int i=0;i<lenght;i++){
            AddNodeEnd(pHead,i);
        }
        offer_6_1::ListNode* pNode = *pHead;
        offer_6_1::ListNode* toBeDelete = pNode -> p_next;
        DeleteNode(pHead,toBeDelete);
        while (pNode->p_next!= nullptr){
            printf("-> %d",pNode->value);
            pNode = pNode->p_next;
        }
        printf("-> %d",pNode->value);
    }
}

namespace offer_18_2{
    void test(){
        offer_6_1::ListNode* OneNode = nullptr;
        offer_6_1::ListNode** pHead = &OneNode;
        int lenght = 6;
        for (int i=0;i<lenght;i++){
            AddNodeEnd(pHead,i);
        }
        offer_6_1::ListNode* pNode = *pHead;
        while(pNode->value!=3){
            pNode=pNode->p_next;
        }
        pNode = *pHead;
        pNode->p_next->value = 0;
        offer_6_1::printLinkList(*pHead);
//        pNode->p_next->p_next->value=3;
        deleteDuplication(pHead);
        offer_6_1::printLinkList(*pHead);

    }
}

namespace offer_19_1{
    void test(){
        char str[] = "tangmingi";
        char pattren[] = "t.*g.*i";
        if(match(str,pattren)){
            printf("match succesful!");
        } else{
            printf("do not match");
        }
    }
}

int main(){
//    offer_4_1::test();
//    offer_5_1::test();
//    offer_6_1::test();
//    offer_7_1::test();
//    offer_8_1::test();
//    offer_9_1::test();
//    offer_10_1::test();     //#include "DynamicPlan.h"
//    sort::test(); //快排 #include "SortAndFind.h"
//    offer_11_1::test(); //#include "list.h"
//    offer_12_1::test(); //#include "DynamicPlan.h"
//    offer_13_1::test(); //#include "DynamicPlan.h"
//    offer_14_1::test(); //#include "DynamicPlan.h"
//    offer_15_1::test(); //bitOper.h
//    offer_16_1::test(); //bitOper.h
//    offer_17_1::printToN(10);   //bitOper.h
//    offer_17_1::printToNadd(10); //bitOper.h
//    offer_17_1::printToNrecursion(10); //bitOper.h
//    offer_18_1::test();  //linkList.h
//    offer_18_2::test(); //linkList.h
    offer_19_1::test();  //charOpe.h
    return 0;

}