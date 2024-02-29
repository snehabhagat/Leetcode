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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        int prev=INT_MIN;
        while(!q.empty()){
            int n=q.size();
            int prev=q.front()->val;
            if(level%2==0 && prev%2!=1){
                return false;
            }
            if(level%2==1 && prev%2!=0){
                return false;
            }
            if(level%2==0){
                prev=INT_MIN;
            }
            else{
                prev=INT_MAX;
            }
            while(n--){
                auto p=q.front();
                if(level%2==0 && p->val>prev && p->val%2==1){
                    prev=p->val;
                }
                else if(level%2==1 && p->val<prev && p->val%2==0){
                    prev=p->val;
                }
                else{
                    return false;
                }
                q.pop();
                if(p->left){
                    q.push(p->left);
                }
                if(p->right){
                    q.push(p->right);
                }
            }
            level++;
        }
        return true;
    }
};