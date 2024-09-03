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
    //wanted to practice quick sort
    //take 1: put all ListNode inside a list and quickSort: TLE
    //take 2 learn from solution: pointer approach
    //      but both head and tail as pivot result in TLE
    //take 3: mergeSort, AC but still slow
    //todo: take 4
    ListNode* mergeSort(ListNode* head){
        if(!head->next) return head; //size = 1

        ListNode* walker = head;
        ListNode* lhs_tail = nullptr;
        ListNode* runner = head;
        while(runner && runner->next){ //execute at least once
            lhs_tail = walker;
            walker = walker->next; //walker forward 1 step
            runner = runner->next->next; //runner forward 2 steps
        }//when break, walker at list[(n + 1)/2]

        lhs_tail->next = NULL; //seperate two list
        ListNode* lhs = mergeSort(head);
        ListNode* rhs = mergeSort(walker);
        
        return merge(lhs, rhs);
    }

    ListNode* merge(ListNode* list1, ListNode* list2){
        ListNode* iter = new ListNode();
        ListNode* head = iter;
        while(list1 && list2){
            if(list1->val < list2->val){
                iter->next = list1;
                list1 = list1->next;
            }else{
                iter->next = list2;
                list2 = list2->next;
            }
            iter = iter->next;
        }

        if(!list1) iter->next = list2;
        else iter->next = list1;
        return head->next;

        //garbage collection, but slow the code down
        // iter = head->next;
        // delete head;
        // return iter;
    }

    ListNode* sortList(ListNode* head) {
        if(!head) return head;
        else return mergeSort(head);
    }
};