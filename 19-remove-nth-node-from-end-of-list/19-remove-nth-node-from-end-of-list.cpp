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
      
    ListNode* dn = new ListNode();
    dn->next = head;
    ListNode* p1;    
    p1 = dn;
    //fast move by n
    while(n--){
        p1 = p1->next;
    }
    
    ListNode* p2 = dn;
    while(p1->next){
        p1 = p1->next;
        p2 = p2->next;
    }
    
    p2->next = p2->next->next;
    return dn->next; 
    }
};