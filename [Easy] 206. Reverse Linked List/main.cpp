#include <stack>
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
    ListNode* reverseList(ListNode* head) {

        if ( head != nullptr ){
            std::stack<ListNode*> stackList;
            while(head != nullptr){
                stackList.push(head);
                head = head->next;
            }
    
            ListNode* resList = stackList.top();
            stackList.pop();
            ListNode* curNode = resList;
            while(!stackList.empty()){
                curNode->next = stackList.top();
                stackList.pop();
                curNode = curNode->next;
            }
            
            curNode->next = nullptr;
            return resList;
        }
        return head;
    }
};

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* res = solution.reverseList(new ListNode());
    while(res != nullptr){
        std::cout << res->val << std::endl;
        res = res->next;
    }
}