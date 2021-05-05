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
    ListNode* rotateRight(ListNode* head, int k) {
        
        // If LL is empty || LL having one element || zero rotations
        if(head==NULL || head->next==NULL || k==0) return head;
        
        // Point a temporary pointer to head
        ListNode* curr = head;
        
        // Count the no. of element in a LL
        int count = 1;
        
        while(curr->next && ++count)
            curr=curr->next;
        
        // Make the Normal LL as circular LL
        curr->next = head;
        
        // Will reduce the no. of rotations if the value of K is greater then or equal to LL 
        k = k % count;
        k = count - k;
        
        while(k--) curr=curr->next;
        
        head = curr->next;
        curr->next=NULL;
        
        return head;
        
    }
};
