#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        string listOne;
        string listTwo;
        string stringRes;
        ListNode* dummy = new ListNode(0);
        ListNode* res = dummy;

        while(l1 != nullptr){
            listOne += to_string(l1->val);
            l1 = l1->next;
        }

        while(l2 != nullptr){
            listTwo += to_string(l2->val);
            l2 = l2->next;
        }

        listOne = string(listOne.rbegin(), listOne.rend());
        listTwo = string(listTwo.rbegin(), listTwo.rend());

        int carry = 0;
        int x = listOne.size() - 1, y = listTwo.size() - 1;

        while ( x >= 0 || y >= 0 || carry != 0){
            int numA = 0, numB = 0;
            
            try{
                numA = listOne.at(x) - '0';
            } catch (...) {}

            try{
                numB = listTwo.at(y) - '0';
            } catch (...) {}

            //cout << numA << " " << numB << endl;

            int res = numA + numB;
            if ( carry == 1 ){
                res++;
                carry = 0;
            }

            if ( res >= 10 ){
                stringRes += to_string(res).at(1);
                //cout << to_string(res).at(1) << endl;                
                carry = 1;
            } else {
                stringRes += to_string(res).at(0);
            }
            
            x--;
            y--;
            //cout << stringRes << endl;
            //cout << carry << endl;
        }
 
        stringRes = string(stringRes.begin(), stringRes.end());

        for ( char i : stringRes ){
            res->next = new ListNode(i - '0');
            res = res->next;
        }

        return dummy->next;
    }
};

int main(){
    Solution solution;
    ListNode* list1NodeThree = new ListNode(3, nullptr);
    ListNode* list1NodeTwo = new ListNode(4, list1NodeThree);
    ListNode* list1 = new ListNode(2, list1NodeTwo);

    //ListNode* list2NodeFour = new ListNode(9, nullptr);
    ListNode* list2NodeThree = new ListNode(4, nullptr);
    ListNode* list2NodeTwo = new ListNode(6, list2NodeThree);
    ListNode* list2 = new ListNode(5, list2NodeTwo);

    ListNode* res = solution.addTwoNumbers(list1, list2);

    while(res != nullptr){
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}