//
// Created by tmy on 19-8-8.
//

#ifndef OFFER_STACKANDQUEUE_H
#define OFFER_STACKANDQUEUE_H
#include <iostream>
#include <stack>
#include <exception>
#include <vector>
#endif //OFFER_STACKANDQUEUE_H
using namespace std;
namespace offer_9_1{
    template<typename T> class CQueue{
    public:
        CQueue(void);
        ~CQueue(void);

        void appendTail(const T& node);
        T deleteHead();

    private:
        stack<T>stack1; //入对栈
        stack<T>stack2;//出队栈
    };

    template<typename T> void CQueue<T>::appendTail(const T &node) {
        stack1.push(node);
    }
    template<typename S> S CQueue<S>::deleteHead() {
        if (stack1.empty() && stack2.empty()){
            printf("no have data in queue");
            exit(1);
        }
        if (!stack2.empty()){
            S value = stack2.top();
            stack2.pop();
            printf("top %d",value);
            return value;
        } else{
            while (!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
            S value = stack2.top();
            stack2.pop();
            printf("top %d",value);
            return value;
        }
    }

    template <typename W> CQueue<W>::CQueue(void) {}
    template <typename T> CQueue<T>::~CQueue(void) {}
}

namespace offer_30_1{
    class Solution {
    public:
        std::stack<int> m_data;
        std::stack<int> m_min;
        void push(int value) {
            m_data.push(value);
            if(m_min.size()==0 || m_min.top() >= value){
                m_min.push(value);
            }else if(m_min.top() < value) {
                m_min.push(m_min.top());
            }
        }
        void pop() {
            m_data.pop();
            m_min.pop();
        }
        int top() {
            return m_data.top();
        }
        int min() {
            return m_min.top();
        }
    };
}

namespace offer_31_1{
    class Solution {
    public:
        bool IsPopOrder(vector<int> pushV,vector<int> popV) {
            if(pushV.size()!=popV.size()){
                return false;
            }
            if(popV.empty()){
                return true;
            }
            std::stack<int> temp;
            auto popIter = popV.begin();
            for (auto pushIter=pushV.begin();pushIter!=pushV.end();pushIter++){
                temp.push(*pushIter);
                while ((!temp.empty())&&temp.top()==*popIter){  //这里调用栈时要检查是否为空
                    temp.pop();
                    popIter++;
                }
            }
            return temp.empty();
        }
    };
    void test(){
        std::vector<int> push({1,2,3,4,5});
        std::vector<int> pop({4,3,5,2,1});
        Solution a;
        bool flag = a.IsPopOrder(push,pop);
        if(flag){
            printf("right");
        } else{
            printf("false");
        }
    }
}