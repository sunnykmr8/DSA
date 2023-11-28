class Solution {
private:
ListNode* getMid(ListNode* head){
    ListNode*slow = head;
    ListNode*fast = head->next;
    while(fast && fast->next){
    slow=slow->next;
    fast = fast->next->next;    
    }
    return slow;
}
ListNode* reverse(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
public:
    bool isPalindrome(ListNode* head) {
    if(head == NULL || head->next == NULL) return true;

    //step1: find middle
    ListNode* middle = getMid(head);

    //step2: reverse list after middle
    ListNode*temp = middle->next;
    middle ->next = reverse(temp);

    //step3: compare both halfs
    ListNode*head1 = head;
    ListNode*head2 = middle->next;
    while(head2 != NULL){
        if(head1->val != head2->val) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    //step4: repeat step2 to make head  normal form
    temp = middle->next;
    middle->next = reverse(temp);

    return true;    
    }
};
