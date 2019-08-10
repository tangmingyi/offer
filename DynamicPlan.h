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
namespace {
    bool checkIndex(int index,int rows,int cols){
        if (index>=0 && index<rows*cols){
            return true;
        }else{
            return false;
        }
    }

    bool corePath(char* matrix,int rows,int cols,char* str,int index,bool* visited){
        if (*str == '\0') {
            return true;
        }
        int left = index-1;
        int right = index+1;
        int top = index-cols;
        int down = index+cols;
        if (checkIndex(left,rows,cols)&&matrix[left]==*str&&!visited[left]){
            visited[left] = true;
            if (corePath(matrix,rows,cols,++str,left,visited)) return true;
            visited[left] = false;
        }
        if (checkIndex(right,rows,cols)&&matrix[right]==*str&&!visited[right]){
            visited[right] = true;
            if (corePath(matrix,rows,cols,++str,right,visited)) return true;
            visited[right] = false;
        }
        if (checkIndex(top,rows,cols)&&matrix[top]==*str&&!visited[top]){
            visited[top] = true;
            if(corePath(matrix,rows,cols,++str,top,visited)) return true;
            visited[top] = false;
        }
        if (checkIndex(down,rows,cols)&&matrix[down]==*str&&!visited[down]){
            visited[down] = true;
            if(corePath(matrix,rows,cols,++str,down,visited)) return true;
            visited[down] = false;
        }
        return false;

    }
}
namespace offer_12_1{

    bool hasPath(char* matrix,int rows,int cols,char* str){
        bool visited[rows*cols];
        char* pstr = str;
        for (int i=0;i<rows*cols;i++){
            visited[i] = false;
        }
        for (int i=0;i<rows*cols;i++){
            if(*str!=matrix[i]){
                continue;
            }
            if(corePath(matrix,rows,cols,++pstr,i,visited)){
                return true;
            }
            pstr = str;
        }
        pstr = nullptr;
        return false;
    }
}