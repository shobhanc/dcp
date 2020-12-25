/*
 * Check if the linked list is a palindrome.
 */

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = NULL;
  }
};

//time O(N) and space O(1)
LinkedList* reverse(LinkedList *head){
	LinkedList* cur=NULL, *prev=NULL;
	while(head){
		cur=head;
		head=head->next;
		cur->next = prev;
		prev=cur;
	}
	return prev;
}

//time O(N) and space O(1)
int linkedListLen(LinkedList *head){
	int l=0;
	LinkedList *cur= head;
	while(cur){
		cur=cur->next;
		l++;
	}
	return l;
}

//time O(N) and space O(1)
LinkedList* split(LinkedList* head, int totalLen){
	LinkedList* cur=head, *prev=NULL;
	int len=totalLen/2;
	while(cur && len){
		prev=cur;
		cur=cur->next;
		len--;
	}
	if(totalLen%2){
		prev=cur;
		cur = cur->next;
	}
	prev->next=NULL;
  return cur;
}

//time O(N) and space O(1)
bool compare(LinkedList* first, LinkedList* second){
	while(first && second){
		if(first->value!=second->value)
			return false;
		first=first->next;
		second=second->next;
	}
	return true;
}

//time O(N) and space O(1)
bool linkedListPalindrome(LinkedList *head) {
  // Write your code here.
	int len = linkedListLen(head);
	LinkedList *second=split(head, len);
	second = reverse(second);
	return compare(head, second);
}

LinkedList* findMiddle(LinkedList* head){
	LinkedList* slow=head, *fast=head;
	while(fast && fast->next){
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

//time O(N) and space O(1)
bool linkedListPalindrome2(LinkedList *head) {
	if(head == NULL || head->next==NULL)
		return true;

	// Write your code here.
	LinkedList *second=findMiddle(head);
	second = reverse(second);
	return compare(head, second);
}




