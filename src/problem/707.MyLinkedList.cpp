#include <string>
#include "helper/VerifyHelper.h"
#include "ProblemRegistry.h"
using namespace std;
namespace problem_707_MyLinkedList {
    class MyLinkedList {
    public:
        struct MyList {
            int val;
            MyList* next;
            MyList(int _val) : val(_val), next(nullptr) {}
        };
        int len;
        MyList* head;
        MyLinkedList() {
            len = 0;
            head = new MyList(0);
        }
        int get(int index) {
            if (index<0 || index>len - 1) return -1;
            MyList* pos = head->next;
            for (int i = 0;i < index;i++) pos = pos->next;
            return pos->val;
        }

        void addAtHead(int val) {
            addAtIndex(0, val);
        }

        void addAtTail(int val) {
            addAtIndex(len, val);
        }

        void addAtIndex(int index, int val) {
            MyList* addNew = new MyList(val);
            MyList* pos = head;
            if (index > len) return;
            len++;
            for (int i = 0;i < index;i++) pos = pos->next;
            addNew->next = pos->next;
            pos->next = addNew;
        }

        void deleteAtIndex(int index) {
            if (index < 0 || index >= len) return;
            MyList* pos = head;
            for (int i = 0;i < index;i++) pos = pos->next;
            MyList* tmp = pos->next;
            pos->next = pos->next->next;
            delete tmp;
            len--;
        }
    };
}