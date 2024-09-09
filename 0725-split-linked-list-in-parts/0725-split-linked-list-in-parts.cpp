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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* iter = head;
        while(head){
            size++;
            head = head->next;
        }
        int remain = size % k;
        size /= k;

        vector<ListNode*> answer = {iter};
        ListNode* end = new ListNode();
        if(!size){
            while(remain){
                k--;
                end = iter;
                iter = iter->next;
                end->next = nullptr;

                answer.push_back(iter);
                remain--;
            }
            while(k){
                answer.push_back(nullptr);
                k--;
            }
            answer.pop_back();
            return answer;
        }
        
        int count = 0;
        while(iter){
            count++;
            if(count == size){
                count = 0;
                if(remain){
                    iter = iter->next;
                    remain--;
                }

                end = iter;
                answer.push_back(iter->next);
            }
            iter = iter->next;
            end->next = nullptr;
        }
        answer.pop_back();
        return answer;
    }
};