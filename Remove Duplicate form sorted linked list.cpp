// https://www.interviewbit.com/problems/remove-duplicates-from-sorted-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    ListNode* prev = A;
    ListNode* curr = A->next;
    while(curr!=NULL){
        if(prev->val==curr->val){
            ListNode* temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete(temp);
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return A;
}
