//
// Created by zb198 on 2019/9/22.
//
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
private:
    vector<string> result;
public:
    void core(string str,int begin){
        if(begin==str.size()){
            auto Iter = find(result.begin(),result.end(),str);
            if(Iter == result.end()) {
                result.push_back(str);
            }
        } else{
            for(int Index=begin;Index<str.size();Index++){
                char temp = str[begin];
                str[begin] = str[Index];
                str[Index] = temp;
                core(str,begin+1);
                temp = str[begin];
                str[begin] = str[Index];
                str[Index] = temp;
            }
        }
    }
    vector<string> Permutation(string str) {
        if(str==""){
            return result;
        }
        core(str,0);
        sort(result.begin(),result.end());
        return result;
    }
};
