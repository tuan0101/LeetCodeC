/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *bike = head;
        ListNode *motoBike = head;
        
        while(motoBike && motoBike->next){
            bike = bike->next;
            motoBike = motoBike->next->next;

            // At the point if fast and slow are at same address
            if(bike == motoBike) return true;
        }
        
        return false;
    }
};