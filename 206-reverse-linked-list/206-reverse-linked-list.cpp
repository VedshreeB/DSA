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
    ListNode* reverseList(ListNode* head) {
        //edge case
        if(head == NULL || head->next==NULL) return head;
        
        ListNode *prev, *nex, *cur;
        prev = NULL;
        cur = head;
        
        while(cur){
            nex = cur->next;
            cur->next = prev;
            //move the pointers
            prev = cur;
            cur= nex;
        }
        
        return prev;
    }
};