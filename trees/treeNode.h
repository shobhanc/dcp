/*
 * TreeNode library
 * Left<root and root>=right
 */
#ifndef TREENODE_H
#define TREENODE_H
class TreeNode {
	public:
		TreeNode *left, *right;
		int val;

		TreeNode(){
			val=-1;
			left=nullptr;
			right=nullptr;
		}
		TreeNode(int v){
			val=v;
			left=nullptr;
			right=nullptr;
		}
		void insert(int v){
			if(v<val){
				if(left!=nullptr){
					left->insert(v);
				}else{
					left = new TreeNode(v);
				}
			}else{
				if(right!=nullptr){
					right->insert(v);
				}else{
					right = new TreeNode(v);
				}
			}
		}
};
#endif
