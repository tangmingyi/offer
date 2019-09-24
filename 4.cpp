//
// Created by zb198 on 2019/9/24.
//
#include <vector>
using namespace std;
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size();
        int cols = array[0].size();
        for(int col=cols-1;col>=0;col++){
            for(int row=0;row<rows;row++){
                if(array[row][col]>target){
                    break;
                } else{
                    if(array[row][col]==target){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
int main(){
    Solution sol = Solution();
    vector<vector<int> > array({{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}});
    int target = 7;
    bool result = sol.Find(target,array);
    return 0;
}
