/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1=0,l2=0;
        ListNode* head=headA;
        ListNode* head2=headB;
        while(headA!=NULL or headB!=NULL){
            if(headA!=NULL){
                l1++;
                headA=headA->next;
            }
            if(headB!=NULL){
                l2++;
                headB=headB->next;
            }
        }
        int diff=abs(l2-l1);
        // making head bigger 
        if(l1<l2){
            swap(head,head2);
        }
        while(diff!=0 ){
            head=head->next;
            diff--;
        }
        while(head!=NULL and head2!=NULL){
            if(head==head2){
                return head;
            }
            head=head->next;
            head2=head2->next;
        }
        return NULL;
    }
};