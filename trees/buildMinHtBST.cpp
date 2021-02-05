/*
 * Build a min height BST, from a sorted array.
 */

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }

  void insert(int value) {
    if (value < this->value) {
      if (left == nullptr) {
        left = new BST(value);
      } else {
        left->insert(value);
      }
    } else {
      if (right == nullptr) {
        right = new BST(value);
      } else {
        right->insert(value);
      }
    }
  }
};

//time O(N) and space O(N)
BST *helper(int l, int r, vector<int> &array){
	if(l>r) return NULL;
	int m=l+(r-l)/2;
	BST *b = new BST(array[m]);
	b->left=helper(l, m-1, array);
	b->right=helper(m+1,r, array);
	return b;
}

BST *minHeightBst(vector<int> array) {
  return helper(0, array.size()-1, array);
}


