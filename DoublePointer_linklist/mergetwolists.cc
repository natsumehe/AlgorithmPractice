#include <iostream>
#include "../util/list_node.hpp"

using namespace std;


class Solution {
public:
    SingleListNode<int>::ListNode* mergeTwoLists(SingleListNode<int>::ListNode* l1, SingleListNode<int>::ListNode* l2){
        if (l1 == nullptr) {
            return l2;
        }
        else if (l2 == nullptr) {
            return l1;
        }
        else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

int main() {
    Solution sol;
    vector<int> vec1 = {1,2,3};
    vector<int> vec2 = {1,3,4};
    SingleListNode<int>::ListNode* l1 = SingleListNode<int>::vectorToListNode(vec1);
    SingleListNode<int>::ListNode* l2 = SingleListNode<int>::vectorToListNode(vec2);
    SingleListNode<int>::ListNode* merged = sol.mergeTwoLists(l1, l2=nullptr);
    
    cout << "合并后的链表: ";
    for (SingleListNode<int>::ListNode* p = merged; p; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    
    SingleListNode<int>::freeMemoryLinkedList(merged);
    return 0;
}
    