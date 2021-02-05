/*
 * Given a binary tree, return the max diameter
 * where diameter is defined as the longest path from
 * one leaf to the other thru a common node.
 *        A
 *       / \
 *      B   C
 *     / \ / \
 *    D  E F  G
 *   /         \
 *  I           J 
 *
 *    the longest diameter is 6
 *    I-D-B-A-C-G-J
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

struct TreeInfo{
	int diameter;
	int height;
};

//time O(N) and space O(h) - h height of the binary tree
struct TreeInfo getMaxHtAndDiameter(BinaryTree *tree){
	if(tree==NULL){
		return {0,0};
	}
	struct TreeInfo left = getMaxHtAndDiameter(tree->left);
	struct TreeInfo right = getMaxHtAndDiameter(tree->right);

	int curDiameter = left.height+right.height;
	int maxDiameterSoFar = max(right.diameter,left.diameter);
	int curMaxDiameter = max(curDiameter,maxDiameterSoFar);
	int maxHeight = 1+max(left.height,right.height);

	return {curMaxDiameter, maxHeight};

}


int binaryTreeDiameter(BinaryTree *tree) {
	struct TreeInfo info = getMaxHtAndDiameter(tree);
	return info.diameter;
}


