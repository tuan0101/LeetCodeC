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
        ListNode* dummyHead = new ListNode(); //ListNode(-1) where -1 is any value
        ListNode* tail = dummyHead;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                tail->next = list1;
                list1 = list1->next;
            }else{
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        
        if(list1) tail->next = list1;
        else if(list2) tail->next = list2;
        return dummyHead->next;
        
        // recursive
        // Time: O(m+n) Space:O(m+n) because of the call stack
        // if(list1==NULL) return list2;
        // if(list2==NULL) return list1;
        // if(list1->val < list2->val){
        //     list1->next = mergeTwoLists(list1->next, list2);
        //     return list1;
        // }
        // else{
        //     list2->next = mergeTwoLists(list2->next, list1);
        //     return list2;
        // }
    }
};

// recursive call stack: (from bottom to top)
// list1->next 
// list1->next =mergeTwoLists(l1,l2)
// list2->next = mergeTwoLists(l1,l2)