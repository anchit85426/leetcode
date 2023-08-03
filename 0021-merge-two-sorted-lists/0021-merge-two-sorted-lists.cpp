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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=NULL;
        ListNode* head2=NULL;
        if(list1==NULL){
            return list2;
        }
        else if(list2==NULL){
            return list1;
        }
        if(list1->val<list2->val){
            ListNode* node=new ListNode();
            head=node;
            head2=node;
            node->val=list1->val;
            list1=list1->next;
        }
        else{
            ListNode* node=new ListNode();
            head=node;
            head2=node;
            node->val=list2->val;
            list2=list2->next;
        }
        while(list1!=NULL and list2!=NULL){
              if(list1->val<list2->val){
                  
              ListNode* node=new ListNode();
              head->next=node;
              node->val=list1->val;
              list1=list1->next;
              head=node;
        }
        else{
            ListNode* node=new ListNode();
            head->next=node;
            node->val=list2->val;
            list2=list2->next;
            head=node;
        }
    }
   while(list1!=NULL){
       ListNode* node=new ListNode();
       head->next=node;
       node->val=list1->val;
       list1=list1->next;
       head=node;
   }
        while(list2!=NULL){
        ListNode* node=new ListNode();
        head->next=node;
        // cout<<list2->val<<endl;
        node->val=list2->val;
        list2=list2->next;
            head=node;
   }
    return head2;
    }
};