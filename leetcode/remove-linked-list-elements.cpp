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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* ans = new ListNode();
        ans->next = head;

        ListNode* curr = ans;

        while(curr->next)
        {
            if(curr->next->val == val){
                curr->next = curr->next->next;
                continue;
            }
            
            curr = curr->next;
        }

        return ans->next;
    }
};