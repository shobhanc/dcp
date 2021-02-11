/*
 * Construct a doubly linked list
 */

using namespace std;

class Node {
	public:
		int value;
		Node *prev;
		Node *next;

		Node(int value);
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
	public:
		Node *head;
		Node *tail;

		DoublyLinkedList() {
			head = nullptr;
			tail = nullptr;
		}

		//time O(1) and space O(1)
		void setHead(Node *node) {
			if(head==NULL){
				head=node;
				tail=node;
			}else{
				insertBefore(head,node);
			}
		}

		//time O(1) and space O(1)
		void setTail(Node *node) {
			if(tail==NULL){
				setHead(node);
			}else{
				insertAfter(tail,node);
			}
		}

		//time O(N) and space O(1)
		void insertBefore(Node *node, Node *nodeToInsert) {
			if(nodeToInsert==head && nodeToInsert==tail){
				return;
			}
			remove(nodeToInsert);
			nodeToInsert->next = node;
			nodeToInsert->prev = node->prev;
			if(node->prev){
				node->prev->next=nodeToInsert;
			}else{
				head=nodeToInsert;
			}
			node->prev = nodeToInsert;
		}

		//time O(N) and space O(1)
		void insertAfter(Node *node, Node *nodeToInsert) {
			if(nodeToInsert==head && nodeToInsert==tail){
				return;
			}
			remove(nodeToInsert);
			nodeToInsert->prev = node;
			nodeToInsert->next = node->next;
			if(node->next){
				node->next->prev = nodeToInsert;
			}else{
				tail=nodeToInsert;
			}
			node->next=nodeToInsert;
		}

		//time O(N) and space O(1)
		void insertAtPosition(int position, Node *nodeToInsert) {
			if(position==1){
				setHead(nodeToInsert);
				return;
			}
			Node* root=head;
			while(position!=1 && root){
				position--;
				root=root->next;
			}
			if(root){
				insertBefore(root, nodeToInsert);
			}else{
				setTail(nodeToInsert);
			}
		}

		//time O(N) and space O(1)
		void removeNodesWithValue(int value) {
			Node* root=head;
			while(root){
				Node* toRemove=root;
				root=root->next;
				if(toRemove->value==value){
					remove(toRemove);
				}
			}
		}

		//time O(1) and space O(1)
		void remove(Node *node) {
			if(node==head){
				head=head->next;
			}
			if(node==tail){
				tail = tail->prev;
			}
			removeBindings(node);
		}

		//time O(1) and space O(1)
		void removeBindings(Node* node){
			if(node->prev){
				node->prev->next = node->next;
			}
			if(node->next){
				node->next->prev = node->prev;
			}
			node->next=NULL;
			node->prev=NULL;
		}

		//time O(N) and space O(1)
		bool containsNodeWithValue(int value) {
			Node* root=head;
			while(root){
				if(root->value==value){
					return true;
				}
				root=root->next;
			}
			return false;
		}
};


