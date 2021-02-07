/*
 * Given a tree where the nodes are connected to their ancestors.
 * Given the root which does not have any ancestors and any two descendants 
 * find the lowest common ancestor of the descendants.
 *
 *          A
 *         / \
 *        B  C
 *       / \ / 
 *      D  E F
 *
 *   A: the root with no ancestor
 *   Given nodes D and C, the lowest common ancestor is A.
 */

class AncestralTree {
public:
  char name;
  AncestralTree *ancestor;

  AncestralTree(char name) {
    this->name = name;
    this->ancestor = nullptr;
  }

  void addAsAncestor(vector<AncestralTree *> descendants);
};

int getDepth(AncestralTree *topAncestor,
		AncestralTree *descendantOne){
	int depth=0;
	while(descendantOne!=topAncestor){
		depth++;
		descendantOne=descendantOne->ancestor;
	}
	return depth;
}

AncestralTree *moveUpByN(AncestralTree *descendantOne, int N){
	while(N){
		N--;
		descendantOne = descendantOne->ancestor;
	}
	return descendantOne;
}

//time O(h) and space O(1) - h height of the tree
AncestralTree *getYoungestCommonAncestor(AncestralTree *topAncestor,
                                         AncestralTree *descendantOne,
					 AncestralTree *descendantTwo) {
	//find height of one and two
	int one = getDepth(topAncestor, descendantOne);
	int two = getDepth(topAncestor, descendantTwo);
	//move up the longest depth
	if(one>two){
		descendantOne = moveUpByN(descendantOne, one-two);
	}else if(one<two){
		descendantTwo = moveUpByN(descendantTwo, two-one);
	}
	//move both up till they meet
	while(descendantOne != descendantTwo){
		descendantOne = descendantOne->ancestor;
		descendantTwo = descendantTwo->ancestor;
	}
	return descendantOne;
}
