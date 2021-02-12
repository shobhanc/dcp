/*
 * Given a linked list, remove the kth node from the end.
 */

#include <vector>
using namespace std;

class LinkedList {
	public:
		int value;
		LinkedList *next;

		LinkedList(int value);
		void addMany(vector<int> values);
		vector<int> getNodesInArray();
};

//time O(N) and space O(1)
void removeKthNodeFromEnd(LinkedList *head, int k) {
	int d=1;
	LinkedList* fast = head;
	LinkedList* slow = head;
	LinkedList* prev = NULL;
	while(d<=k && fast){
		d++;
		fast=fast->next;
	}
	//lenght of list is k
	if(fast==NULL){
		head->value=head->next->value;
		head->next = head->next->next;
		return;
	}
	//lenght of list > k
	while(slow && fast){
		prev=slow;
		slow=slow->next;
		fast=fast->next;
	}
	prev->next = slow->next;
}


