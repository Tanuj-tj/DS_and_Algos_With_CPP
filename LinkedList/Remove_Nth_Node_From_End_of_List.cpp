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
        
       // Create a dummy node
       ListNode* dummy = new ListNode();
       dummy->next = head;
        
       // Maintain a fast and slow pointers
       ListNode* slow = dummy;
       ListNode* fast = dummy;
        
       // Move the fast poiner uptill n
       for(int i=1;i<=n;i++)
            fast=fast->next;
        
       // Move both fast and slow pointers untill the fast pointer reaches to null
       while(fast->next!=NULL){
           fast=fast->next;
           slow=slow->next;
       }
       
       // Delete the node 
       slow->next = slow->next->next;
       
       return dummy->next;
        
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)
