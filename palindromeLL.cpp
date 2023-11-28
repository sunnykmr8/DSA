class Solution {
public:
    ListNode* getmid(ListNode *head){
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode *getreverse(ListNode* head){
        ListNode *prev=NULL;
        ListNode * next=NULL;
        while(head!=NULL){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next==NULL){
           return true;
        }
        ListNode *middle=getmid(head);
        ListNode *temp =middle->next;
        middle->next= getreverse(temp); 

        ListNode *head1=head;
        ListNode *head2=middle->next;

        while(head2!=NULL){
            if(head1->val!=head2->val){
                return false;
            }
                head1=head1->next;
                head2=head2->next;
        }
        temp=middle->next;
        middle->next=getreverse(temp);
        return true;
    }
};
