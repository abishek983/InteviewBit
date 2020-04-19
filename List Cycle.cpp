// https://www.interviewbit.com/problems/list-cycle/
// Time complexity O(n) and space complexity is constant O(1)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* head = A;
    ListNode* fast = A;
    ListNode* newNode = new ListNode(INT_MAX) ;
    while(head!=NULL){
            //cout << head->val << endl;
        if(head->next==NULL){
            return NULL;
        }
        if(head->next == newNode)
            return head;
        ListNode* temp = head->next;
        head->next = newNode;
        head = temp;
    }
    
    
}
