#include <iostream>
#include <string>

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
    int traverseTree(TreeNode* root, string binaryString) {
        if (root == NULL) {
            return 0;
        }
        binaryString += to_string(root->val);
        cout << binaryString << endl;

        if (root->left == NULL && root->right == NULL) {
            return stoi(binaryString, nullptr, 2);
        }

        return traverseTree(root->left, binaryString) + traverseTree(root->right, binaryString);
    }

    int sumRootToLeaf(TreeNode* root) {
        return traverseTree(root, "");
    }
};

int main(){
    Solution solution;
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(0);
    tree->right = new TreeNode(1);
    tree->left->left = new TreeNode(0);
    tree->left->right = new TreeNode(1);
    tree->right->left = new TreeNode(0);
    tree->right->right = new TreeNode(1);

    int res = solution.sumRootToLeaf(tree);
    cout << res << endl;
    return 0;
}