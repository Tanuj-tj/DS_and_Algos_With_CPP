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
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
        
//         ListNode* next;      // next = head->next;
//         ListNode* prev = NULL;
//         ListNode* curr = head;
        
//         int count = 0;
      
//         // Reverse first k nodes
//         while(curr!=NULL && count<k){
//             next = curr->next;
//             curr->next = prev;
            
//             prev = curr;
//             curr = next;
        
//             count++;
//         }
        
//         // Recursive Call
//         if(next!=NULL){
//             head->next = reverseKGroup(next,k);
//         }
        
//         return prev;    
//     }
    
// };


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == NULL || k==1) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* nextptr = dummy;      
        ListNode* prev = dummy;
        ListNode* curr = dummy;
        
        int count = 0;
        while(curr->next!=NULL){
            curr=curr->next;
            count++;  
        }
        
        curr = head;
        
        
         while(count>=k){
             curr = prev->next;
             nextptr = curr->next;
             for(int i=1;i<k;i++){
                 curr->next = nextptr->next;
                 nextptr->next = prev->next;
                 prev->next = nextptr;
                 nextptr = curr->next;
             }
             prev = curr;
             count-=k;
         } 
        
        return dummy->next;
    }
    
};
