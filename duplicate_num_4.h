//
// Created by tmy on 19-8-5.
//

//#ifndef OFFER_DUPLICATE_NUM_4_H
//#define OFFER_DUPLICATE_NUM_4_H
//
//#endif //OFFER_DUPLICATE_NUM_4_H

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