/*
 * Given a singlely linked list, remove duplicates
 *
 * input: 1->2->3->3->4->4->5->6->7->7->NULL
 * output:1->2->3->4->5->6->7->NULL
 */

class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

//time O(N) and space O(1)
LinkedList *removeDuplicatesFromLinkedList(LinkedList *root) {
	if(root==NULL || root->next==NULL){
		return root;
	}
	LinkedList* cur = root;
	LinkedList* nextNode = NULL;
	while(cur){
		nextNode = cur->next;
		while(nextNode && cur->value==nextNode->value){
			nextNode=nextNode->next;
		}
		cur->next = nextNode;
		cur=nextNode;
	}
	return root;
}


