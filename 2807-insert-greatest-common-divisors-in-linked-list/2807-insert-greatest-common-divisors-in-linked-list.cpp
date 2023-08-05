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
        ListNode* temp=head;
        while(temp->next!=NULL){
            ListNode* curr=temp->next;
            ListNode* node=new ListNode(__gcd(temp->val,curr->val));
            temp->next=node;
            node->next=curr;
            temp=temp->next;
            temp=temp->next;
        }
        return head;
    }
};