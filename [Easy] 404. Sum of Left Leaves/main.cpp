#include <iostream>

using namespace std;

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

    bool flag = true; // true = left, false = right;
    int sum = 0;

    int traverseTree(TreeNode* root, bool isLeft){
        if ( root == nullptr ){
            return 0;
        }

        if ( root->left == nullptr && root->right == nullptr && isLeft ){
            cout << root->val << endl;
            sum += root->val;
        }

        traverseTree(root->left, true);
        traverseTree(root->right, false);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if ( root->left == nullptr && root->right == nullptr ){
            return 0;
        }
        bool isLeft = true;
        return traverseTree(root, isLeft);;
    }
};

int main(){
    Solution solution;
    
    TreeNode* tree = new TreeNode(3);
    tree->left = new TreeNode(9);
    tree->right = new TreeNode(20);
    tree->right->left = new TreeNode(15);
    tree->right->right = new TreeNode(7);

    int res = solution.sumOfLeftLeaves(tree);
    cout << res << endl;
    return 0;
}