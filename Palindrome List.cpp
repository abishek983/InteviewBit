// https://www.interviewbit.com/problems/palindrome-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 void reverse(ListNode** head){
     ListNode* curr = *head;
     ListNode* prev = NULL;
     ListNode* next;
     while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;
     }
     *head = prev;
 }
 
int Solution::lPalin(ListNode* A) {
    ListNode* slow = A;
    ListNode* fast = A;
    ListNode* prev = NULL;
    ListNode* temp = NULL;
    while(fast!=NULL && fast->next!=NULL){
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }
    //check for odd elements
    if(fast){
        slow = slow->next;
    } reverse(&slow);
    while(slow){
        if(slow->val == A->val){
            A = A->next;
            slow = slow->next;
        }
        else
            return 0;
    }
    return 1;
}
