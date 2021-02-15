/*
 * Given two linked lists, sum the linked lists and return the list.
 * 2->4->7->1
 * 9->4->5
 *
 * result:
 * 1->9->2->2
 */

using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

//time O(max(M,N)) and space O(max(N,M))
LinkedList *sumOfLinkedLists(LinkedList *llOne,
		LinkedList *llTwo) {
	int prev=0, one=0, two=0, sum=0;
	auto root= new LinkedList(0);
	auto ret=root;
	//iterate over both linked list till either
	//of them are numm or prev is zero
	while(llOne!=NULL || llTwo!=NULL || prev!=0){
		one=0;
		two=0;
		if(llOne){
			one=llOne->value;
		}
		if(llTwo){
			two=llTwo->value;
		}
		sum = one+two+prev;
		//keep adding to new list
		root->next = new LinkedList(sum%10);
		prev = sum/10;
		if(llOne){
			llOne = llOne->next;
		}
		if(llTwo){
			llTwo = llTwo->next;
		}
		root=root->next;
	}
	return ret->next;
}
