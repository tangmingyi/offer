//
// Created by tmy on 19-8-9.
//

#ifndef OFFER_SORTANDFIND_H
#define OFFER_SORTANDFIND_H
#include <exception>
//#include <stdio.h>
#include <stdlib.h>
#endif //OFFER_SORTANDFIND_H
using namespace std;
namespace {
    int RandomInRange(int min,int max){
        int random = rand()%(max-min+1) +min;
        return random;
    }

    void Swap(int& a,int& b){
        int temp = a;
        a = b;
        b = temp;
    }

    int Partition(int data[],int length,int start,int end){
        if (data== nullptr || length <=0 || start < 0 || end >= length){
            return -1;
        }

        int index = RandomInRange(start,end);
        Swap(data[index],data[end]);

        int small = start - 1;
        for(index=start;index<end;++index){
            if(data[index]<data[end]){
                ++small;
                if(small != index){
                    Swap(data[small],data[index]);
                }
            }
        }
        ++small;
        Swap(data[small],data[end]);

        return small;

    }
}
namespace sort{

    void QuickSort(int data[],int length,int start,int end){
        if(start==end){
            return;
        }
        int index = Partition(data,length,start,end);
        if (index > start){
            QuickSort(data,length,start,index-1);
        }
        if (index < end){
            QuickSort(data,length,index+1,end);
        }
    }
}