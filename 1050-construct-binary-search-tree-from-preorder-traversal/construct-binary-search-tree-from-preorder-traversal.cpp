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
    TreeNode* solve(vector<int>& preorder,int &idx,int range){
        if(idx==preorder.size() || preorder[idx]>range){
            return NULL;
        }
        TreeNode* node=new TreeNode(preorder[idx]);
        idx++;
        node->left=solve(preorder,idx,node->val);
        node->right=solve(preorder,idx,range);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return solve(preorder,idx,INT_MAX);
    }
};