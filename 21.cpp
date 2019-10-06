//
// Created by zb198 on 2019/10/6.
//
#include <vector>
using namespace std;
class Solution {
private:
    bool isOod(int num){
        return num % 2 != 0;
    }
public:
    void reOrderArray(vector<int> &array) {
        vector<int > OodList;
        vector<int > EvenList;
        for (int i=0;i<array.size();i++){
            if(isOod(array[i])){
                OodList.push_back(array[i]);
            } else{
                EvenList.push_back(array[i]);
            }
        }
        int j = 0;
        for(auto Iter = OodList.begin();Iter!=OodList.end();Iter++){
            array[j] = *Iter;
            j++;
        }
        for(auto Iter = EvenList.begin();Iter!=OodList.end();Iter++){
            array[j] = *Iter;
            j++;
        }

    }
};
