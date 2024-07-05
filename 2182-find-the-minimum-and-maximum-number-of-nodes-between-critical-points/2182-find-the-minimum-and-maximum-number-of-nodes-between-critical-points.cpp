/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans;
        int count=0;
        vector<int> temp;
        int cn=0;
        ListNode *curr=head,*prev=NULL;
        while(curr && curr->next){
            count++;
            if(prev){
                if(prev->val>curr->val && curr->val<curr->next->val){
                    temp.push_back(count);
                }
                if(prev->val<curr->val && curr->val>curr->next->val){
                    temp.push_back(count);
                }
            }
            prev=curr;
            curr=curr->next;
        }
        if(temp.size()<2){
            return {-1,-1};
        }
        int n=temp.size()-1;
        int x=INT_MAX;
        for(int i=0;i<n;i++){
            x=min(x,temp[i+1]-temp[i]);
        }
        int y=temp[n]-temp[0];
        return {x,y};
    }
};