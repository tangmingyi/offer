#include <iostream>
#include "duplicate_num_3.h"
#include "duplicate_num_4.h"
#include "replace_blank.h"
#include "print_list_reversingly_6.h"
#include "tree.h"
#include "stackAndQueue.h"
#include "DynamicPlan.h"
#include "SortAndFind.h"
#include "list.h"
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
    return 0;
}