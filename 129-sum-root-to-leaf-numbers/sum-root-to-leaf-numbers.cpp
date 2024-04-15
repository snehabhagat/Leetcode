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
    int ans;
    void solve(TreeNode* root,int temp){
        if(!root){
            return;
        }
        temp=temp*10+root->val;
        if(!root->left && !root->right){
            ans+=temp;
            return;
        }
        solve(root->left,temp);
        solve(root->right,temp);
    }
    int sumNumbers(TreeNode* root) {
        ans=0;
        solve(root,0);
        return ans;
    }
};