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
    vector<TreeNode*> nums;
    void Inorder(TreeNode* root){
        if(root->left){
            Inorder(root->left);
        }
        nums.push_back(root);
        if(root->right){
            Inorder(root->right);
        }
        return;
    }
    TreeNode* createTree(vector<TreeNode*>&nums,int start,int end){
        if(start>end){
            return NULL;
        }
        int mid=start+(end-start)/2;
        TreeNode* node=new TreeNode(nums[mid]->val);
        node->left=createTree(nums,start,mid-1);
        node->right=createTree(nums,mid+1,end);
        return node;
    }
    TreeNode* balanceBST(TreeNode* root) {
        Inorder(root);
        int start=0,end=nums.size()-1;
        TreeNode* node=createTree(nums,start,end);
        return node;
    }

};