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

#include <cmath>

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        
        ListNode* temp = head;
        int count=0;
        while(temp->next!=NULL){   // O(N)
            count++;
            temp=temp->next;
        }
        temp=head;
        
        int mid = ceil((1+count)/2);  //(1)
            
        for(int i=1;i<=mid;i++){      //O(N/2)
            temp=temp->next;
        }
        
        return temp;
    }
};


// More Optimized

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head; 
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
       
     return slow;
    }
};

// Complexity : O(N/2) , O(1)
