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
    int depthf(TreeNode* root){
        if (root==nullptr)return 0;
        return 1+max((depthf(root->right)),(depthf(root->left)));
    }
    TreeNode* ans =nullptr;
    void d(TreeNode* root, int depth, int currdepth){
        if(root==nullptr)return ;
        
        int l =depthf(root->left);
        int r =depthf(root->right);

        if(l==depth-currdepth && r == depth-currdepth){ans = root;return;}
        if(l>r) d(root->left,depth,currdepth+1);
        else d(root->right,depth,currdepth+1);
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int depth = depthf(root);
        if(root==nullptr)return nullptr;
        ans = nullptr;
        d(root,depth,1);
        
        return ans;
    }
};