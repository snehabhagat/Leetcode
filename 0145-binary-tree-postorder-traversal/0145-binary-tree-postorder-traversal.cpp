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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> ans;
        while(st.size() || root){
            if(root){
                st.push(root);
                root=root->left;
            }
            else{
                auto it=st.top();
                if(it->right==NULL){
                    ans.push_back(it->val);
                    st.pop();
                    while(st.size()>0 && st.top()->right==it){
                        ans.push_back(st.top()->val);
                        it=st.top();
                        st.pop();
                    }
                }
                else{
                    root=it->right;
                }
            }
        }
        return ans;
    }
};