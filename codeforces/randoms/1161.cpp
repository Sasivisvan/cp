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
    int maxLevelSum(TreeNode* root) {
        int max = root->val;
        int ans=1;
        int lvl = 1;
        int sum = 0;
        queue<pair<int,TreeNode*>>q;
        q.push({1,root});
        pair<int,TreeNode*>node;
        while(!q.empty()){
            node = q.front();q.pop();
            if(lvl<node.first){
                if(sum>max){
                    ans = lvl;
                    max = sum;
                }
                sum=0;
                lvl++;
            }
            sum+=node.second->val;
            if(node.second->left!=nullptr){
                q.push({lvl+1,node.second->left});
                // cout<<lvl+1<<"  l:"<<node.second->left->val<<endl;
            }

            if(node.second->right!=nullptr){
                q.push({lvl+1,node.second->right});
                // cout<<lvl+1<<"  r:"<<node.second->right->val<<endl;
            }

            // cout<<lvl<<" "<<node.second->val<<" "<<sum<<endl;
            

        }
        if(sum>max){
                    ans = lvl;
                    max = sum;
                }
        return ans;
    }
};