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

ListNode* nextNode(ListNode *node) {
    if(node == nullptr) { 
        return nullptr;
    } else {
        return node->next;
    }
}
 
int nodeVal(ListNode *node) { 
    if(node == nullptr) { 
        return 0;
    } else { 
        return node->val;
    }
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
 
        ListNode *head = new ListNode;   
        ListNode *curr = head; 
        int value = 0;

        while(l1 != nullptr || l2 != nullptr || value/10 != 0) { 

            value = value/10 + nodeVal(l1) + nodeVal(l2); 
            l1 = nextNode(l1); 
            l2 = nextNode(l2);
            curr->next = new ListNode(value % 10);
            curr = curr->next;
        }
        return head->next; 
}

int main() {

    //ListNode l1(5);
    //ListNode l2(5);
    //ListNode l1(6, new ListNode(4, new ListNode(3)));
    //ListNode l2(6, new ListNode(6, new ListNode(4)));
    ListNode l1(6);
    ListNode l2(6, new ListNode(6, new ListNode(4)));

    ListNode *results = addTwoNumbers(&l1, &l2);

    printLst(results);
}