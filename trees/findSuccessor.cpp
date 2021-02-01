/*
 * Find Successor
 * Given binary tree which has left , right and parent pointers and a node.
 * Find the succesor of the node when the tree is traversed in order.
 */

// This is an input class. Do not edit.
// time O(n) and space O(n)
class BinaryTree {
public:
  int value;
  BinaryTree *left = nullptr;
  BinaryTree *right = nullptr;
  BinaryTree *parent = nullptr;

  BinaryTree(int value) { this->value = value; }
};

void inorder(BinaryTree *tree, vector<BinaryTree*> &v){
    if(tree==NULL){
       return;
		}
	inorder(tree->left, v);
	  v.push_back(tree);
	  inorder(tree->right, v);
}

//do inorder and capture in a vector and secrch for given node and return the next in the list
BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  // Write your code here.
	vector<BinaryTree*> v;
	inorder(tree, v);
	int i=0;
	for(; i<v.size();i++){
     if(v[i]==node){
        break;
		 }
	}
	return ((i+1)<v.size())?v[i+1]:nullptr;
}

//time O(h) and space O(1)
//
//climb up the right nodes till the parent's right node is not the current node
//the return parent of that node
//          A
//         / \
//        B   C
//       /\   /\
//      D  E  F G
//
//     E's parent is B, but go to B's parent till E's parent's right is not same as E
//     So go to A(B's parent) and and A's right C is not B. So return B's parent.
BinaryTree* findRightMostParent(BinaryTree* cur){
	while(cur->parent!= NULL && 
			 cur->parent->right == cur){
       cur = cur->parent;
	}
	return cur->parent;
}

//got right from cur node and go left most to find the succesor from right side
//of the original tree
//          A
//         / \
//        B   C
//       /\   /\
//      D  E  F G
//
//B's successor is the left most, in this case D is the succesor
BinaryTree* findLeftMost(BinaryTree *cur){
	 while(cur->left){
      cur = cur->left;
	 }
	 return cur;
}


BinaryTree *findSuccessor(BinaryTree *tree, BinaryTree *node) {
  // Write your code here.
	//go right and find the left most
	if(node->right){
     return findLeftMost(node->right);
	}
	//find parent of rightmost parent
	return findRightMostParent(node);
}


