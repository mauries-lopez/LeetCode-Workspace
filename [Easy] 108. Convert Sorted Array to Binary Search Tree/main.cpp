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
        int mid = std::floor(nums.size()/2);
        TreeNode* root = new TreeNode(nums.at(mid));
        leftBranch(root, nums, 0, mid-1);
        rightBranch(root, nums, mid+1, nums.size()-1);
        return root;
    }

    void leftBranch(TreeNode* root, std::vector<int>& nums, int low, int high){
        if ( low > high ) return;
        
        int mid = std::floor(low + (high-low)/2);
        TreeNode* node = new TreeNode(nums[mid]);

        if (nums[mid] < root->val){
            std::cout << "Left Node" << std::endl;
            std::cout << "nums[mid]: " << nums[mid] << " | root->val: " << root->val << std::endl;
            root->left = node;
        } else {
            std::cout << "Right Node" << std::endl;
            std::cout << "nums[mid]: " << nums[mid] << " | root->val: " << root->val << std::endl;
            root->right = node;
        }

        leftBranch(node, nums, low, mid - 1);
        leftBranch(node, nums, mid + 1, high);
    }

    void rightBranch(TreeNode* root, std::vector<int>& nums, int low, int high){
        if ( low > high ) return;
        
        int mid = std::floor(low + (high-low)/2);
        TreeNode* node = new TreeNode(nums[mid]);

        if (nums[mid] < root->val){
            std::cout << "Left Node" << std::endl;
            std::cout << "nums[mid]: " << nums[mid] << " | root->val: " << root->val << std::endl;
            root->left = node;
        } else {
            std::cout << "Right Node" << std::endl;
            std::cout << "nums[mid]: " << nums[mid] << " | root->val: " << root->val << std::endl;
            root->right = node;
        }

        rightBranch(node, nums, low, mid - 1);
        rightBranch(node, nums, mid + 1, high);
    }
};

int main(){

    std::vector<int> input = {1,3};
    Solution solution;
    TreeNode* res = solution.sortedArrayToBST(input);
    std::cout << res->val << std::endl;
    std::cout << res->left->val << std::endl;
    // std::cout << res->left->left->val << std::endl;
    // std::cout << res->left->right->val << std::endl;
    // std::cout << res->right->val << std::endl;
    // std::cout << res->right->left->val << std::endl;
}