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
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next;
        
        while(current!=NULL){
            next=current->next;
            current->next= prev;
            prev = current;
            current=next;
        }
        return prev;
            
    }
    bool isPalindrome(ListNode* head) {
        
        
        // Find the middle element
        
        ListNode* slow = head;
        ListNode* fast = head;
                      
                // Last Node             Second Last Node
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        // After while loop terminates slow will point to mid element
        
        // Revese the other half of the linked list  || mid->
        slow->next = reverse(slow->next);
        slow=slow->next;
        
        while(slow!=NULL){
            if(head->val!=slow->val){
                return false;
            }
            head=head->next;
            slow=slow->next;
        }
        return true;
       
        
        
    }
};
