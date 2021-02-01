/*
 * Given a BST and a value. Find the closest value in the tree to the given value.
 *
 */

//recursive
class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

//time O(N) and worst space O(N)
//average time O(log(N)) and space O(log(N)) depth of the tree
int helper(BST *tree, int target, int closest){
	if(tree==NULL){
     return closest;
	}
	if(abs(target-closest)>abs(target-tree->value)){
     closest = tree->value;
	}
	if(target<tree->value){
     return helper(tree->left, target, closest);
	}else if(target>tree->value){
     return helper(tree->right, target, closest);
	}else{
     return closest;
	}
}
int findClosestValueInBst(BST *tree, int target) {
  return helper(tree, target, tree->value);
}

//time O(N) and space O(1)
int findClosestValueInBst(BST *tree, int target) {
  // Write your code here.
	int closest=tree->value;
	while(tree){
		if(abs(target-closest)>abs(target-tree->value)){
       closest=tree->value;
		}
		if(target>tree->value){
       tree=tree->right;
		}else if(target<tree->value){
       tree=tree->left;
		}else{
			return tree->value;
		}
	}
	return closest;
}
