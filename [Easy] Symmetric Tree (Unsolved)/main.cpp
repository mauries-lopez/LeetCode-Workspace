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
    bool isSymmetric(TreeNode* root) {
    
        if ( root == nullptr ){
            /*
            std::cout << "---" << std::endl;
            for ( auto x : nodeVector){
                std::cout << "Val: "<< x << std::endl;
            }
            */
            return true;
        }
        isSymmetric(root->left);
        
        std::cout << root->val << std::endl;

        isSymmetric(root->right);
        return true;
    }
};

int main(){

    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left->left = new TreeNode(2);
    tree->left->right = nullptr;
    tree->right = new TreeNode(2);
    tree->right->left = nullptr;
    tree->right->right = new TreeNode(2);

    Solution solution;
    bool res = solution.isSymmetric(tree);
    std::cout << std::boolalpha << res << std::endl;
}