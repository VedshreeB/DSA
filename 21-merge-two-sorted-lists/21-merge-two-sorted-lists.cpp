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
        //edge case
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;
        
        //decide the head of the resulting ll
        ListNode* res , *temp;
        if(list1->val <= list2->val){
            res = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            res = temp = list2;
            list2 = list2->next;
        }
        
        while(list1 && list2){
            if(list1->val <= list2->val){
                temp->next = list1;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
    
        return res;
    }
};