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
        ListNode *current = NULL, *next;
        while(head){
            next = head->next;
            
            head->next = current;
            current = head;
            head = next;
        }
        return current;
    }
};

// 1->2->null
// null<-1 2->null
// current at 1, head is at 2

// at the second loop:
// null<-1<-2
// current is at 2, head is at null

// exit the loop
