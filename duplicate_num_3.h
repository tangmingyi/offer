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

