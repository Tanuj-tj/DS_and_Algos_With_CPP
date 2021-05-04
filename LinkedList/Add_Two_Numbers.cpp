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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {   // 2 , 5 , 4, 6 , 3,4
       
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        
        int carry = 0;   // 0 , 1 , 0
        
        while(l1!=NULL || l2!=NULL || carry){    // carry != 0
            int sum = 0;         // 0 , 7 , 0 , 10 , 0
            if(l1!=NULL){        
                sum+=l1->val;     // 4 , 3
                l1=l1->next;      // 3 , NULL
            }
            if(l2!=NULL){
                sum+=l2->val;     // 10  , 7
                l2=l2->next;      // 4 , NULL
            }
             
            sum+=carry;            // 10 , 8
            carry = sum / 10;   // 0 ,  1 , 0
            ListNode* node = new ListNode(sum%10);   // 7 , 0 , 8
            temp-> next = node;
            temp = temp->next;
            
        }
        return dummy->next;
    }
    
};
