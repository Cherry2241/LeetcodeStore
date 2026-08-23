#include <string>
#include<queue>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_225_MyStack {
    class MyStack {
    public:
        MyStack() {
            size = 0;
            t = 0;
        }
        void push(int x) {
            q.push(x);
            size++;
            t = x;
        }
        int pop() {
            int i, num;
            for (i = 1;i <= size;i++)
            {
                num = q.front();
                q.pop();
                if (i == size - 1) t = num;
                if (i != size) q.push(num);
            }
            size--;
            return num;
        }
        int top() {
            return t;
        }
        bool empty() {
            if (size > 0) return false;
            else return true;
        }
        queue<int> q;
        int size, t;
    };
}