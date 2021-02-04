/*
 * BST insert/delete/remove
 */

class BST {
	public:
		int value;
		BST *left;
		BST *right;

		BST(int val) {
			value = val;
			left = nullptr;
			right = nullptr;
		}

		//average time O(logN) and space O(logN)
		//worst time O(N) and space O(N)
		BST &insert(int val) {
			if(val<value){
				if(left==nullptr){
					left=new BST(val);
				}else{
					left->insert(val);
				}
			}else{
				if(right==nullptr){
					right=new BST(val);
				}else{
					right->insert(val);
				}
			}
			return *this;
		}

		//average time O(logN) and space O(1)
		//worst time O(N) and space O(1)
		BST &insertIter(int val) {
			BST* tree=this;
			while(tree){
				if(val<tree->value){
					if(tree->left==NULL){
						tree->left = new BST(val);
						break;
					}else{
						tree=tree->left;
					}
			  }else{
					if(tree->right==NULL){
						tree->right = new BST(val);
						break;
					}else{
						tree=tree->right;
					}
				}
		  }
			return *this;
		}

		//average time O(logN) and space O(logN)
		//worst time O(N) and space O(N)
		bool contains(int val) {
			if(val<value){
				if(left==nullptr){
					return false;
				}else{
					return left->contains(val);
				}
			}else if(val>value){
				if(right==nullptr){
					return false;
				}else{
					return right->contains(val);
				}
			}else{
				return true;
			}
		}

		//average time O(logN) and space O(1)
		//worst time O(N) and space O(1)
		bool containsIter(int val) {
						BST *tree=this;
						while(tree){
										if(val<tree->value){
														if(tree->left==nullptr){
																		return false;
														}else{
																		tree=tree->left;
														}
										}else if(val>tree->value){
														if(tree->right==nullptr){
																		return false;
														}else{
																		tree=tree->right;
														}
										}else{
														return true;
										}
						}
						return false;
		}

		//average time O(logN) and space O(logN)
		//worst time O(N) and space O(N)
		BST &remove(int val, BST* parent=nullptr) {
			if(val<value){
				if(left){
					left->remove(val, this);
				}
			}else if(val>value){
				if(right){
					right->remove(val, this);
				}
			}else{
				if(left && right){
					value = right->getMinValue();
					right->remove(value,this);
				}else if(parent==nullptr){
					if(left){
						value=left->value;
						right=left->right;
						left=left->left;
					}else if(right){
						value=right->value;
						left=right->left;
						right=right->right;
					}
				}else if(parent->left==this){
					parent->left=left?left:right;
				}else if(parent->right==this){
					parent->right=left?left:right;
				}
			}
			return *this;
		}

		//average time O(logN) and space O(1)
		//worst time O(N) and space O(1)
		BST &removeIter(int val, BST* parent=nullptr) {
						BST* tree=this;
						while(tree){
										if(val<tree->value){
														parent=tree;
														tree=tree->left;
										}else if(val>tree->value){
														parent=tree;
														tree = tree->right;
										}else{
														if(tree->left && tree->right){
																		tree->value = tree->right->getMinValue();
																		tree->right->remove(tree->value,tree);
														}else if(parent==nullptr){
																		if(tree->left){
																						tree->value=tree->left->value;
																						tree->right=tree->left->right;
																						tree->left=tree->left->left;
																		}else if(tree->right){
																						tree->value=tree->right->value;
																						tree->left=tree->right->left;
																						tree->right=tree->right->right;
																		}
														}else if(parent->left==tree){
																		parent->left=tree->left?tree->left:tree->right;
														}else if(parent->right==tree){
																		parent->right=tree->left?tree->left:tree->right;
														}
														break;
										}
						}
						return *this;

		}

		int getMinValue(){
			if(left==nullptr){
				return value;
			}else{
				return left->getMinValue();
			}
		}

		int getMinValueIter(){
						BST *tree = this;;
						while(tree){
						     if(tree->left==NULL)
									  return value;
								 tree=tree->left;
						}
		}

};


