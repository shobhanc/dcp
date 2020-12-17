/**
 *Given a non-negative integer represented as a linked list of digits, plus one to the integer.
 *The digits are stored such that the most significant digit is at the head of the list.
 *Example 1:
 *
 *Input: head = [1,2,3]
 *Output: [1,2,4]
 *Example 2:
 *
 *Input: head = [0]
 *Output: [1]
 *
 *
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
    ListNode* reverse(ListNode* head){
        ListNode *cur=NULL;
        ListNode *prev = NULL;
        while(head){
            cur=head;
            head=head->next;
            cur->next = prev;
            prev=cur;
        }
        return prev;
    }
    
    ListNode* plusOneUsingReverseList(ListNode* node) {
        if(node==NULL){
            node = new ListNode(1);
            return node;
        }
        ListNode *root = reverse(node);
        ListNode* head = root;
        ListNode* prev=NULL;
        int add_one=1;        
        while(head){
            if(add_one){
                head->val+=add_one;
                if(head->val/10!=0){
                    head->val%=10;
                }else{
                    break;                   
                }
            }
            prev=head;
            head=head->next;
        }
        if(add_one){
            prev->next = new ListNode(1);
        }
        return reverse(root);
    }
    
    /*find right most not 9 and increment it and 
     *if none found create a new head with value 1 make it new root
     *set the 9's following it to 0
     *Time O(n) and space O(1)
     */
    ListNode* plusOneFindRightMostNotNine(ListNode* node) {
        ListNode* lastNot9 = NULL;
        ListNode* notNine=NULL;
        ListNode* prev=NULL;
        ListNode* cur = node;
        while(cur){
            if(cur->val!=9){
               notNine=cur;
            }
            cur=cur->next;
        }
        //set all nines after not nine to 0
        if(notNine==NULL){
            notNine=new ListNode(0, node);
            node=notNine;
        }
        cur = notNine->next;    
        while(cur){
             cur->val=0;
             cur=cur->next;
        }
        notNine->val++;
        return node;
        
    }
};
