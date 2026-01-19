#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

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
    std::vector<int> nodeVector;
    bool res = true;

    bool isSymmetric(TreeNode* rootA) {
        TreeNode* rootB = rootA;
        validateSymmetric(rootA, rootB);
        return res;
    }

    void validateSymmetric(TreeNode* rootA, TreeNode* rootB){
        if ( rootA == nullptr && rootB == nullptr){
            /*
            std::cout << "---" << std::endl;
            for ( auto x : nodeVector){
                std::cout << "Val: "<< x << std::endl;
            }
            */
            return;
        }
        
        if ( rootA != nullptr && rootB != nullptr ){
            validateSymmetric(rootA->left, rootB->right);
            //std::cout << "---" << std::endl;
            //std::cout << "A Val: "<< rootA->val << std::endl;
            //std::cout << "B Val: "<< rootB->val << std::endl;
            if ( rootA->val != rootB->val ){
                res = false;
                return;
            }
            validateSymmetric(rootA->right, rootB->left);
        } else {
            res = false;
            return;
        }
    }
};

int main(){

    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left->left = new TreeNode(3);
    tree->left->right = new TreeNode(4);
    tree->right = new TreeNode(2);
    tree->right->left = new TreeNode(4);
    tree->right->right = new TreeNode(3);

    Solution solution;
    bool res = solution.isSymmetric(tree);
    std::cout << std::boolalpha << res << std::endl;
}