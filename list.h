//
// Created by tmy on 19-8-10.
//

#ifndef OFFER_LIST_H
#define OFFER_LIST_H

#endif //OFFER_LIST_H
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