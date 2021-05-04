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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* next;      // next = head->next;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        int count = 0;
      
        // Reverse first k nodes
        while(curr!=NULL && count<k){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
        
            count++;
        }
        
        // Recursive Call
        if(next!=NULL){
            head->next = reverseKGroup(next,k);
        }
        
        return prev;    
    }
    
};