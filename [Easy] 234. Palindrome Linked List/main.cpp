#include <vector>
#include <iostream>
#include <algorithm>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::vector<int> temp;
        ListNode* curNode = head;

        while ( curNode != nullptr ){
            temp.push_back(curNode->val);
            curNode = curNode->next;
        }
        
        std::reverse(temp.begin(), temp.end());
        int i = 0;
        curNode = head;
        while(curNode != nullptr){
            if ( curNode->val != temp.at(i) ){
                return false;
            }
            i++;
            curNode = curNode->next;
        }
        return true;
    }
};

int main(){
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(2);
    list1->next->next->next->next = new ListNode(3);

    Solution solution;
    bool res = solution.isPalindrome(list1);
    std::cout << std::boolalpha << res << std::endl;
}