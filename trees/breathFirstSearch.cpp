/*
 * Given a tree with multiple children at each node.
 * Navigate the tree in breadth first search appraoch
 * and capture all values of the nodes in a vector and 
 * return.
 *
 * input:
 *          A
 *         / \
 *        B   C
 *      / | \  \
 *     D  E  F  G
 *
 * output: [A,B,C,D,E,F,G]
 */
class Node {
	public:
		string name;
		vector<Node *> children;

		Node(string str) { name = str; }

		//time O(v+e) and space O(v)
		vector<string> breadthFirstSearch(vector<string> *array) {
			// Write your code here.
			deque<Node*> q;
			q.push_back(this);
			while(!q.empty()){
				Node* n=q.front();
				q.pop_front();
				(*array).push_back(n->name);
				for(auto a: n->children){
					q.push_back(a);
				}
			}
			return *array;
		}

		Node *addChild(string name) {
			Node *child = new Node(name);
			children.push_back(child);
			return this;
		}
};
