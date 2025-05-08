#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool res = true;
    bool isSameTree(TreeNode* p, TreeNode* q) {
        traverseTree(p, q);
        return res;
    }

    void traverseTree(TreeNode* p, TreeNode* q){
        if ( p == nullptr && q == nullptr ){
            return;
            //std::cout << "p->val: " << p->val << "- q->val: " << q->val << std::endl;
            
        }

        if ( p != nullptr && q != nullptr ){
            if ( p->val != q->val ){
                res = false;
                return;
            }
        } else {
            res = false;
            return;
        }

        //std::cout << "if p->val: " << p->val << "- q->val: " << q->val << std::endl;
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);
    }
};

int main(){

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    //tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    //tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(2);

    Solution solution;
    bool res = solution.isSameTree(tree1, tree2);
    std::cout << std::boolalpha << res << std::endl;
}