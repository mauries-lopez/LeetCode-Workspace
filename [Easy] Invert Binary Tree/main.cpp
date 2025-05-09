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
    
    int temp;

    TreeNode* invertTree(TreeNode* root) {
        traverseTree(root);
        return root;
    }

    TreeNode* traverseTree(TreeNode*& root){
        if ( root == nullptr ){
            return nullptr;
        }

        TreeNode* nodeLeft = traverseTree(root->left);
        TreeNode* nodeRight = traverseTree(root->right);

        root->left = nodeRight;
        root->right = nodeLeft;

        return root;
    }
};

int main(){

    TreeNode* tree = new TreeNode(2);
    //tree->left = new TreeNode(2);
    //tree->left->left = new TreeNode(1);
    //tree->left->right = new TreeNode(3);
    //tree->right = new TreeNode(7);
    //tree->right->left = new TreeNode(6);
    //tree->right->right = new TreeNode(9);
    tree->right = new TreeNode(3);
    tree->right->right = new TreeNode(1);
    //tree->right->right = new TreeNode(9);

    Solution solution;
    TreeNode* res = solution.invertTree(tree);
    std::cout << res->left->left->val << std::endl;
}