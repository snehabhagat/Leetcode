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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* curr=head;
        while(curr && curr->next){
            ListNode* next=curr->next;
            int x=curr->val;
            int y=curr->next->val;
            int z=__gcd(x,y);
            ListNode* newNode=new ListNode(z);
            curr->next=newNode;
            newNode->next=next;
            curr=next;
        }
        return head;
    }
};