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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curNode = head;
        while(curNode != nullptr && curNode->next != nullptr){
            //std::cout << "curNode: " << curNode->val << std::endl;
            //std::cout << "head: " << head->val << std::endl;
            if ( curNode->val == curNode->next->val ){
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
    list1->next->next->next->next = new ListNode(3);

    Solution solution;
    ListNode* res = solution.deleteDuplicates(list1);
    while(res != nullptr){
        std::cout << res->val << std::endl;
        res = res->next;
    }
}