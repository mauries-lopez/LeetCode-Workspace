#include <iostream>
#include <vector>
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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if ( nums.size() > 1 ){
            int midIndex = std::floor(nums.size() / 2);
            TreeNode* root = new TreeNode(nums.at(midIndex));
            TreeNode* rootMaster = root;
            int leftStartIdx = 0, leftEndIdx = midIndex - 1;
            int rightStartIdx = midIndex + 1, rightEndIdx = nums.size()-1;
            leftBranch(root, rootMaster, nums, leftStartIdx, leftEndIdx);
            //std::cout << root->val << std::endl;
            //std::cout << root->left->val << std::endl;
            //std::cout << root->left->left->val << std::endl;
            rightBranch(root, rootMaster, nums, rightStartIdx, rightEndIdx);
            //std::cout << root->val << std::endl;
            //std::cout << root->right->val << std::endl;
            //std::cout << root->right->left->val << std::endl;
            //std::cout << root->right->left->left->val << std::endl;
            return root;
        } else if ( nums.size() == 1 ){
            TreeNode* root = new TreeNode(nums.at(0));
            return root;
        }
        return nullptr;
    }

    void leftBranch(TreeNode* root, TreeNode* rootMaster, std::vector<int>& nums, int leftStartIdx, int leftEndIdx){
        
    }

    void rightBranch(TreeNode* root, TreeNode* rootMaster, std::vector<int>& nums, int rightStartIdx, int rightEndIdx){
        
    }
};

int main(){

    std::vector<int> input = {0,1,2,3,4,5};
    Solution solution;
    TreeNode* res = solution.sortedArrayToBST(input);
    // std::cout << res->val << std::endl;
    // std::cout << res->left->val << std::endl;
    // std::cout << res->left->left->val << std::endl;
    // std::cout << res->left->right->val << std::endl;
    // std::cout << res->right->val << std::endl;
    // std::cout << res->right->left->val << std::endl;
}