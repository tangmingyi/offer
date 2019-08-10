//
// Created by tmy on 19-8-9.
//

#ifndef OFFER_DYNAMICPLAN_H
#define OFFER_DYNAMICPLAN_H

#endif //OFFER_DYNAMICPLAN_H
namespace offer_10_1{
    long long Fibonacci(unsigned n){
        long long one=0;
        long long two=1;
        long long temp;
        if (n==0){
            return 0;
        } else if(n==1){
            return 1;
        } else {
            int i = 2;
            while (i != n) {
                temp = one;
                one = two;
                two = temp + two;
                i++;
            }
            return two+one;
        }
    }
}

namespace offer_12_1{
    void corePath(char* matrix,int rows,int cols,char* str,int index){
        int left = index-1;
        int right = index+1;
        int top = index-cols;
        int down = index+cols;
        if (*str == '\0') {
            return
        }
        if (left>=0&&left<cols*rows&&(index!=left)&&matrix[left]==*str){

            corePath(matrix,rows,cols,)
        }
    }

    bool hasPath(char* matrix,int rows,int cols,char* str){
        return false;
    }
}