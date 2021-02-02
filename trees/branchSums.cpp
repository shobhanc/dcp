/*
 * Gather branch sums of the tree and return.
 *
 * branch sum is sum of values from root to leaf in each path.
 */
// This is the class of the input root. Do not edit it.
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

//time O(N) and space O(N)
void helper(BinaryTree* root, vector<int> &v, int sum){
	if(root==NULL){
		return;
	}
	sum+=root->value;
	if(root->left==NULL && root->right==NULL){
		v.push_back(sum);
		return;
	}
	helper(root->left, v, sum);
	helper(root->right, v, sum);
}

vector<int> branchSums(BinaryTree *root) {
	vector<int> res;
	helper(root, res, 0);
	return res;
}
