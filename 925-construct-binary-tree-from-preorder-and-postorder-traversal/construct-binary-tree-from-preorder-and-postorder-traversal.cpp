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
    unordered_map<int,int> mp;
    int i=0;
    TreeNode *solve(vector<int> &preorder,vector<int> &postorder,int start,int end){
        if(start>end || i>=preorder.size()){
            return NULL;
        }
        int x=preorder[i];
        i++;
        TreeNode *root=new TreeNode(x);
        if(start==end || i>=preorder.size()){
            return root;
        }
        int j=mp[preorder[i]];
        root->left=solve(preorder,postorder,start,j);
        root->right=solve(preorder,postorder,j+1,end-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0;i<postorder.size();i++){
            mp[postorder[i]]=i;
        }
        return solve(preorder,postorder,0,preorder.size()-1);
    }
};