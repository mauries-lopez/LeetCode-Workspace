#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // curNode->next means from the current node, what is its next node?
        while(head != nullptr && head->val == val){
            head = head->next;
        }
        ListNode* curNode = head;
        while(curNode != nullptr && curNode->next != nullptr){
            if ( curNode->next->val == val ){
                curNode->next = curNode->next->next;
            } else {
                curNode = curNode->next;
            }
        }
        return head;
    }
};

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(2);

    Solution solution;
    ListNode* res = solution.removeElements(list1,2);
    while(res != nullptr){
        std::cout << res->val << std::endl;
        res = res->next;
    }
}