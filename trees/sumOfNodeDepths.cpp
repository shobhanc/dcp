/*
 * Get sum of node depths.
 *      A-0 (node -level)
 *      /  \
 *    B-1   C-1
 *   /  \   /  \
 * D-2 E-2 F-2 G-2
 *
 * sum of levels 0 + (1+1)+(2+2+2+2) = 10
 */

class BinaryTree {
	public:
		int value;
		BinaryTree *left;
		BinaryTree *right;

		BinaryTree(int value) {
			this->value = value;
			left = nullptr;
			right = nullptr;
		}
};

struct nodeDepth{
	BinaryTree* root;
	int depth;
};

int nodeDepths(BinaryTree *root) {
	stack<struct nodeDepth> stNode;
	stNode.push({root, 0});
	int sum=0;
	while(!stNode.empty()){
		struct nodeDepth nd = stNode.top();
		stNode.pop();
		sum+=nd.depth;
		if(nd.root->left){
			stNode.push({nd.root->left, nd.depth+1});
		}
		if(nd.root->right){
			stNode.push({nd.root->right, nd.depth+1});
		}
	}
	return sum;
}


