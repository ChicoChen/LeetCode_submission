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
    //pratice for insertion sort
    ListNode* insertionSortList(ListNode* head) {
        ListNode *returnHead = head;
        while(head->next){
            ListNode *temp = head->next;
            if(temp->val < returnHead->val){
                head->next = temp->next;
                temp->next = returnHead;
                returnHead = temp; 
            }
            else if(temp->val < head->val){
                head->next = temp->next;
                ListNode* parent = returnHead;
                while(parent->next->val < temp->val){
                    parent = parent->next;
                }
                temp->next = parent->next;
                parent->next = temp;
            }
            else{ head = head->next; }
        }
        return returnHead;
    }
};