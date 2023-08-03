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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        cnt-=n;
        int cnt2=1;
        temp=head;
        if(cnt==0){
            return head->next;
        }
        while(cnt2!=cnt){
            cnt2++;
            temp=temp->next;
        }
        ListNode *temp2=temp->next;
        temp->next=temp->next->next;
        delete(temp2);
        return head;
    }
};