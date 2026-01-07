/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long totalSum(TreeNode* root){
        if(root==nullptr)return 0;
        return root->val + totalSum(root->right)+totalSum(root->left);
    }

    long long max = 0;
    long long total = 0;
    int mp(TreeNode* root){
        if(root==nullptr)return 0;
        int right = mp(root->right);
        int left = mp(root->left);
        if (((total-right )* right)>max)max = (total-right )* right;
        if (((total-left )* left)>max)max = (total-left )* left;
        return root->val + right+left;
    }
    

    long long maxProduct(TreeNode* root) {
        max = 0;
        total = totalSum(root);
        mp(root);
        return max % 1000000007;
    }
};