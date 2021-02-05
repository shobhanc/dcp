/*
 * Given a binary tree swap all left and right nodes
 */

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

//time O(N) and space O(N)
void invertBinaryTree(BinaryTree *tree) {
	if(tree==NULL) return;
	BinaryTree *temp = tree->right;
	tree->right = tree->left;
	tree->left = temp;
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
}

//time O(N) and space O(N)
void invertBinaryTree(BinaryTree *tree) {
	while(tree){
        }
	if(tree==NULL) return;
	BinaryTree *temp = tree->right;
	tree->right = tree->left;
	tree->left = temp;
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
}

void invertBinaryTree2(BinaryTree *tree) {
	queue<BinaryTree *> q;
	q.push(tree);
	while(!q.empty()){
		BinaryTree* b = q.front();
		q.pop();
		BinaryTree *temp = b->left;
		b->left = b->right;
		b->right = temp;
		if(b->left)
			q.push(b->left);
		if(b->right)
			q.push(b->right);
	}
}
