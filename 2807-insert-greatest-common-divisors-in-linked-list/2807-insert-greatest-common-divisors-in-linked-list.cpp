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
    int computeGCD(int a, int b){
        while(b){
            int temp = b;
            b = a % b;
            a = temp; 
        }
        return a;
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* anchor = head;
        ListNode* next = head->next;
        while(next){
            int gcd = computeGCD(head->val, next->val);
            ListNode* gcdNode = new ListNode(gcd, next);
            head->next = gcdNode;
            head = next;
            next = head->next;
        }
        
        return anchor;
    }
};