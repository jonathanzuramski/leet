#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printLst(ListNode *lst) {
    while (lst->next) {
        cout << lst->val << ", ";
        lst = lst->next;
    }
    cout << lst->val << endl;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int x = 0;
    int y = 0;
    
    ListNode *head = new ListNode(l1->val + l2->val);
    ListNode *currNode = head; 
    l1 = l1->next;
    l2 = l2->next;

    while (l1 != nullptr || l2 != nullptr) {
        if (l1 == nullptr) {
            x = 0;
        } else {
            x = l1->val;
        }
        if (l2 == nullptr) {
            y = 0;
        } else {
            y = l2->val;
        }

        int val = x + y; 

        if(val >= 10) {
            currNode->val = currNode->val + 1; 
            val = val % 10; 
        }
        currNode->next = new ListNode(val);
        currNode = currNode->next;
        l2 = l2->next;
        l1 = l1->next;
    }
    return head;
}

int main() {

    ListNode l1(2, new ListNode(4, new ListNode(3)));
    ListNode l2(5, new ListNode(6, new ListNode(4)));

    ListNode *results = addTwoNumbers(&l1, &l2);

    printLst(results);
}