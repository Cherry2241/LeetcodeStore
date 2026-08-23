#include <string>
#include<stack>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_232_MyQueue {

    class MyQueue {
    public:
        MyQueue() {
        }

        void push(int x) {
            int num;
            s1.push(x);
        }

        int pop() {
            int num;
            if (s2.empty())
            {
                while (!s1.empty())
                {
                    num = s1.top();
                    s2.push(num);
                    s1.pop();
                }
            }
            num = s2.top();
            s2.pop();
            return num;
        }

        int peek() {
            int num;
            if (s2.empty())
            {
                while (!s1.empty())
                {
                    num = s1.top();
                    s2.push(num);
                    s1.pop();
                }
            }
                return s2.top();
        }

        bool empty() {
            return s1.empty() && s2.empty();
        }
        stack<int> s1, s2;


    };

    bool RunChecks(std::string& message) {
        // 测试1: 基本功能测试
        MyQueue myQueue;  // 不要用new，直接在栈上创建对象
        myQueue.push(1);  // queue is: [1]
        myQueue.push(2);  // queue is: [1, 2] (leftmost is front of the queue)

        if (myQueue.peek() != 1) {
            message = "peek() should return 1";
            return false;
        }

        int popped = myQueue.pop();  // return 1, queue is [2]
        if (popped != 1) {
            message = "pop() should return 1";
            return false;
        }

        if (myQueue.empty()) {
            message = "queue should not be empty";
            return false;
        }

        // 测试2: 更多元素测试
        myQueue.push(3);
        myQueue.push(4);
        if (myQueue.peek() != 2) {
            message = "peek() should return 2";
            return false;
        }

        if (myQueue.pop() != 2) {
            message = "pop() should return 2";
            return false;
        }

        if (myQueue.peek() != 3) {
            message = "peek() should return 3";
            return false;
        }

        myQueue.pop();  // pop 3
        myQueue.pop();  // pop 4

        if (!myQueue.empty()) {
            message = "queue should be empty";
            return false;
        }

        // 测试3: 空队列操作
        MyQueue emptyQueue;
        if (!emptyQueue.empty()) {
            message = "new queue should be empty";
            return false;
        }

        // 所有测试通过
        message = "All tests passed!";
        return true;
    }

    ProblemRegistrar registrar("232.MyQueue", RunChecks);
}
