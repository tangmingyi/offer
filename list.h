//
// Created by tmy on 19-8-10.
//

#ifndef OFFER_LIST_H
#define OFFER_LIST_H

#endif //OFFER_LIST_H
//
// Created by tmy on 19-8-4.
//剑值offer 3.1题
namespace {
    int countRange(const int* number,int length, int start,int end){
        int count = 0;
        for (int i=0;i< length;i++){
            if (number[i]>=start && number[i]<=end ){
                count++;
            }
        }
        return count;
    }
}
namespace offer3_1{
    bool duplicate(int number[], int length, int* duplicatate) {
        for (int i = 0; i < length; i++) {
            while (number[i] != i) {
                if (number[i] == number[number[i]]) {
                    *duplicatate = number[i];
                    return true;
                }
                int temp = number[i];
                number[i] = number[number[i]];
                number[temp] = temp;
            }
        }
        return false;
    }

}

namespace offer3_2{
    int duplicate(const int* num_list,int length){
        int start = 1;
        int end = length-1;
        while (end >= start){
            int middle = ((end - start) >> 1) + start;//求中位数的骚操作
            int count = countRange(num_list,length,start,middle);
            if (start == end){
                if (count > 1){
                    return start;
                } else{
                    break;
                }
            }
            if (count > (middle-start+1)){
                end = middle;
            }
            else{
                start = middle + 1;
            }

        }
        return -1;
    }
}

namespace offer_4_1{
    bool duplicate(int* matrix,int rows,int colums,int number){
        bool found = false;
        int row = 0;
        int colum = colums -1;
        while(row<rows && colum >=0){           //退出边界的确定
            if (matrix[colum + row * colums] == number){
                found = true;
                break;
            }else if (matrix[colum + row * colums] > number){
                --colum;
            } else if(matrix[colum + row * colums] < number){
                ++row ;
            }
        }
        return found;
    }
}

namespace offer_11_1 {
    int Min(int *data, int lenght) {
        if (data == nullptr || lenght <= 0) {
            return -1;
        }
        if (lenght == 1) {
            return *data;
        }
        int *pStart = data;
        int *pEnd = data + lenght - 1;
        if (*pStart == *pEnd) {
            for (int i = 1; i < lenght; i++) {
                if (data[i - 1] > data[i]) {
                    return data[i];
                }
            }
        }
        int *pMiddle = data + (lenght >> 1);
        while (pStart + 1 != pEnd) {
            if (*pMiddle > *pEnd) {
                pStart = pMiddle;
            } else {
                pEnd = pMiddle;
            }
            pMiddle = pStart + ((pEnd - pStart) >> 1);
        }
        return *pEnd;

    }
}

namespace offer_21_1 {
    bool findEvenNum(int **pNum, const int *num, int length) {
        while (*pNum != num) {
            if ((**pNum) % 2 == 1) {
                return true;
            }
            (*pNum)--;
        }
        return false;
    }

    bool fingOodNum(int **pNum, const int *num, int length) {
        while (*pNum != (num + length - 1)) {
            if ((**pNum) % 2 == 0) {
                return true;
            }
            (*pNum)++;
        }
        return false;
    }

    void ReorderOodEvent(int *nums, int length) {
        if (nums == nullptr || length <= 0) {
            return;
        }
        int *pStart = nums;
        int *pEnd = nums + length - 1;
        while (true) {
            bool ood = fingOodNum(&pStart, nums, length);
            bool even = findEvenNum(&pEnd, nums, length);
            if (pStart > pEnd) {
                break;
            }
            if (ood && even) {
                int temp = *pStart;
                *pStart = *pEnd;
                *pEnd = temp;
            } else {
                return;
            }
        }
        return;
    }

    namespace right {
        void ReorderOodEvent(int *nums, int length, bool (*rule1)(int **, const int *, int),
                             bool(rule2)(int **, const int *, int)) {
            if (nums == nullptr || length <= 0) {
                return;
            }
            int *pStart = nums;
            int *pEnd = nums + length - 1;
            while (true) {
                bool ood = rule1(&pStart, nums, length);
                bool even = rule2(&pEnd, nums, length);
                if (pStart > pEnd) {
                    break;
                }
                if (ood && even) {
                    int temp = *pStart;
                    *pStart = *pEnd;
                    *pEnd = temp;
                } else {
                    return;
                }
            }
            return;
        }
    }
}