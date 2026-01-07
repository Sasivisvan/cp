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
int helper(TreeNode* root, int lvl){
    if(root==nullptr)return lvl;
    return max(helper(root->left,lvl+1),helper(root->right,lvl+1));
}
    int maxDepth(TreeNode* root) {
        return helper(root,0);
    }
};