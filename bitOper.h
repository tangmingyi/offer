//
// Created by zb198 on 2019/8/11.
//

#ifndef OFFER_BITOPER_H
#define OFFER_BITOPER_H

#endif //OFFER_BITOPER_H
namespace offer_15_1 {
    int NumberOf1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while (flag) {
            if (n & flag) {
                count++;
            }
            flag = flag << 1;
        }
        return count;
    }
};
namespace {
    double core(double base, unsigned int exponent) {
        if (exponent == 0) return 1.0;
        if (exponent == 1) return base;
        double resoult = core(base, exponent >> 1);
        resoult *= resoult;
        if (exponent & 1) {
            resoult *= base;
        }
        return resoult;
    }
}
namespace offer_16_1 {
    double Power(double base, int exponent) {
        if (exponent == 0) {
            return 1.0;
        }
        if (exponent == 1) {
            return base;
        }
        unsigned int absExponent;
        if (exponent < 0) {
            absExponent = (unsigned int) (-exponent);
        } else {
            absExponent = (unsigned int) (exponent);
        }
        double resoult = core(base, absExponent);
        if (exponent < 0) {
            resoult = 1.0 / resoult;
        }
        return resoult;
    }
}

namespace offer_17_1 {
    void initNum(char *str, int length) {
        for (int i = 0; i < length - 1; i++) {
            str[i] = '0';
        }
        str[length-1]='\0';
    }

    void print(char *num) {
        int i=0;
//        char* pNode= nullptr;
        while (num[i]!='\0'){
            if(num[i]=='0'){
                i++;
                continue;
            }
//            pNode = &num[i];
            while (num[i]!='\0') {
                printf("%c", num[i]);
                i++;
            }
            break;
        }
        printf("\n");
    }
    //模拟进位，更好的是模拟加法。
    void printToN(int n) {
        if (n < 1) return;
        char num[n + 1];
        initNum(num, n + 1);
//        char* pNode = &num[n-1];
        while (num[0] < 58) {
            if (num[n - 1] < 57) {
                num[n - 1] = num[n - 1] + 1;
            } else {
                num[n - 1] = '0';
                int i = n - 2;
                while (num[i] == 57) {
                    if (i == 0) {
                        return;
                    }
                    num[i] = '0';
                    i--;
//                    pNode--;
                }
                num[i] = num[i] + 1;
//                pNode = &num[i];
            }
            print(num);
        }
    }
    bool addOne(char* num,int length){
        int carry = 0;
        bool overflow = false;
        for(int i=length-2;i>=0;i--){ //模拟加法
            int nSum = num[i] - '0' + carry;
            if(i==length-2){
                nSum++;
            }
            if(nSum>=10){
                if(i==0){
                    overflow= true;
                }else {
                    carry = 1;
                    nSum -= 10;
                    num[i] = '0' + nSum;
                }
            } else{
                num[i] = '0' + nSum;
                break;
            }
        }
        return overflow;
    }
    void printToNadd(int n){
        if(n<1){
            return;
        }
        char num[n+1];
        initNum(num,n+1);
        while(!addOne(num,n+1)){
            print(num);
        }
    }
    void core(char* num,int length,int index){
        if(index==length-2){
            print(num);
            return;
        }
        for(int i=0;i<10;i++){
            num[index+1] = '0'+i;
            core(num,length,index+1);
        }
    }
    void printToNrecursion(int n){
        if(n<1){
            return;
        }
        char num[n+1];
        initNum(num,n+1);
        for(int i=0;i<10;i++){
            num[0] = '0'+i;
            core(num,n+1,0);
        }
    }
}