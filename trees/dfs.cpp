/*
 * Given a tree with n children per node, capture the dfs traversal in an array.
 */
class Node {
	public:
		string name;
		vector<Node *> children;

		Node(string str) { name = str; }

		//time O(v+e) and space O(v)
		vector<string> depthFirstSearch(vector<string> *array) {
			array->push_back(name);
			for(auto a: children){
				a->depthFirstSearch(array);
			}
			return *array;
		}

		Node *addChild(string name) {
			Node *child = new Node(name);
			children.push_back(child);
			return this;
		}
};
