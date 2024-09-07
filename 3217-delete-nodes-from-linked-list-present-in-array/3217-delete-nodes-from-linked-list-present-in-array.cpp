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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        std::unordered_set<int> nums_set(nums.begin(), nums.end());
        while(nums_set.find(head->val) != nums_set.end()) head = head->next; //relocate head;
        
        ListNode* parent = head;
        ListNode* iter = head->next;

        while(iter){
            if(nums_set.find(iter->val) != nums_set.end()){
                parent->next = iter->next; //skip elements in nums
            }else{
                parent = parent->next;
            }
            iter = iter->next;
        }
        return head;
    }
};