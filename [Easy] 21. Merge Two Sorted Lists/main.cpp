#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* resList = new ListNode(0);
        ListNode* tempList = resList; //This is needed so that we wont lose the "head" of resList
        std::vector<int> values;

        while(list1 != nullptr){
            values.push_back(list1->val);
            list1 = list1->next;
        }

        while(list2 != nullptr){
            values.push_back(list2->val);
            list2 = list2->next;
        }

        std::sort(values.begin(), values.end());
        for (auto x : values ){
            tempList->next = new ListNode(x);
            tempList = tempList->next;
            //std::cout << tempList->val << std::endl;
        }

        return resList->next;
    };
};

int main(){
    ListNode* list1ThirdNode = new ListNode(4, nullptr);
    ListNode* list1SecondNode = new ListNode(2, list1ThirdNode);
    ListNode* list1 = new ListNode(1, list1SecondNode);

    ListNode* list2ThirdNode = new ListNode(4, nullptr);
    ListNode* list2SecondNode = new ListNode(3, list2ThirdNode);
    ListNode* list2 = new ListNode(1, list2SecondNode);

    Solution solution;
    ListNode* res = solution.mergeTwoLists(list1, list2);
    while(res != nullptr){
        std::cout << res->val << std::endl;
        res = res->next;
    }
}