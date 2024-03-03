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
    int length(ListNode* curr){
        int count=0;
        while(curr){
            curr=curr->next;
            count++;
        }
        return count;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=length(head);
        int skip=len-n;
        if(skip==0){
            ListNode* newhead=head->next;
            delete head;
            return newhead;
        }
        else{
            int count=1;
            ListNode* curr=head;
            while(count!=skip){
                count++;
                curr=curr->next;
            }
            ListNode* del=curr->next;
            curr->next=del->next;
            delete del;
        }
        return head;
    }
};