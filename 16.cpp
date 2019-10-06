#include <complex>

//
// Created by zb198 on 2019/10/6.
//
class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent==0){
            return 1.0;
        } else{
            double result = 1.0;
            int temp = abs(exponent);
            for(int i=0;i<temp;i++){
                result *= base;
            }
            if(exponent<0){
                result = 1/result;
            }
            return result;
        }
    }
};
