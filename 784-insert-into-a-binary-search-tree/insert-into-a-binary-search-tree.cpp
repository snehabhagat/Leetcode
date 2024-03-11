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
    TreeNode* solve(TreeNode* root,int val){
        if(!root){
            TreeNode* newNode=new TreeNode(val);
            return newNode;
        }
        if(root->val>val){
            root->left=solve(root->left,val);
        }
        else{
            root->right=solve(root->right,val);
        }
        return root;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        solve(root,val);
        if(!root){
            TreeNode* newNode=new TreeNode(val);
            return newNode;
        }
        return root;
    }
};