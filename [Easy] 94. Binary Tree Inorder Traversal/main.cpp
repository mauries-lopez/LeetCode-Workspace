#include <iostream>
#include <vector>

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
    std::vector<int> res;
    std::vector<int> inorderTraversal(TreeNode* root) {
        nodeTraversal(root);
        return res;
    }

    void nodeTraversal(TreeNode* root){
        if ( root == nullptr ){
            return;
        }
        nodeTraversal(root->left);
        res.push_back(root->val);
        nodeTraversal(root->right);
    }
};


int main(){

    TreeNode* tree = new TreeNode(1);
    //tree->left = new TreeNode(2);
    //tree->left->left = new TreeNode(1);
    //tree->left->right = new TreeNode(3);
    //tree->right = new TreeNode(7);
    //tree->right->left = new TreeNode(6);
    //tree->right->right = new TreeNode(9);
    tree->right = new TreeNode(2);
    tree->right->left = new TreeNode(3);
    //tree->right->right = new TreeNode(9);

    Solution solution;
    std::vector<int> res = solution.inorderTraversal(tree);
    std::cout << res.at(0) << std::endl;
}