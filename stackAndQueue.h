//
// Created by tmy on 19-8-8.
//

#ifndef OFFER_STACKANDQUEUE_H
#define OFFER_STACKANDQUEUE_H
#include <iostream>
#include <stack>
#include <exception>
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