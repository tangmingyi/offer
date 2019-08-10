//
// Created by tmy on 19-8-10.
//

#ifndef OFFER_LIST_H
#define OFFER_LIST_H

#endif //OFFER_LIST_H
namespace offer_11_1{
    int Min(int* data,int lenght){
        if (data == nullptr || lenght <= 0){
            return -1;
        }
        if(lenght==1){
            return *data;
        }
        int* pStart = data;
        int* pEnd = data + lenght -1;
        if (*pStart == *pEnd){
            for(int i=1;i<lenght;i++){
                if(data[i-1]>data[i]){
                    return data[i];
                }
            }
        }
        int* pMiddle = data + (lenght>>1);
        while (pStart+1 != pEnd){
            if(*pMiddle > *pEnd){
                pStart = pMiddle;
            } else{
                pEnd = pMiddle;
            }
            pMiddle = pStart + ((pEnd-pStart)>>1);
        }
        return *pEnd;

    }
}