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
    string ans;
    void solve(TreeNode* root,string temp){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            temp+=('a'+root->val);
            reverse(temp.begin(),temp.end());
            if(ans.size()==0){
                ans=temp;
            }
            else{
                if(ans>temp){
                    ans=temp;
                }
            }
            return;
        }
        temp+=('a'+root->val);
        solve(root->left,temp);
        solve(root->right,temp);
    }
    string smallestFromLeaf(TreeNode* root) {
        ans="";
        solve(root,"");
        return ans;
    }
};