/*
 * A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.
 * Given the root to a binary tree, count the number of unival subtrees.
 * For example, the following tree has 5 unival subtrees:
 *
 *     0
 *    / \
 *   1   0
 *      / \
 *     1   0
 *    / \
 *   1   1
 */
#include<iostream>
#include<queue>
#include "treeNode.h"
#include "treeNodeMgr.h"

//Recursion
//O(N) time as we express all nodes
//O(h) space as we traverse the depth of the tree
bool isUnivalTree(TreeNode *root){
	if(root==NULL){
		return true;
	}
	int v = root->val;
	if((root->right && v!=root->right->val) || //if right and root are not equal
			(root->left && v!=root->left->val)){//if left and root are not equal
		return false;
	}
	return isUnivalTree(root->right) && isUnivalTree(root->left); //keep checking 
}

//Iterative
//O(N) time as we express all nodes
//O(1) space as we traverse the depth of the tree
bool iterIsUnivalTree(TreeNode *root){
	if(root==NULL){
		return true;
	}
	queue<TreeNode*> dq;
	dq.push(root);
	while(dq.size()){
		root = dq.front();
		dq.pop(); 
		int v = root->val;
		if((root->right && v!=root->right->val) ||
				(root->left && v!=root->left->val)){
			return false;
		}
		if(root->right) dq.push(root->right);
		if(root->left) dq.push(root->left);
	}
	return true;
}

//Time O(n)
//Space depth of tree O(h)
bool univalHelper(TreeNode* root, int val, int *count){
	if(!root){//on reaching end
		return true;
	}

        //take root value and check if the current left or right subtree is unival
	bool left=univalHelper(root->left, root->val, count);
	bool right=univalHelper(root->right, root->val, count);
	if(!left || !right){
                //if either side is not unival then this subtree is not unival
		return false;
	}
        //found a unival subtree
        (*count)++;
        //tell the caller root if it can consider this path for unival
	return root->val==val;
}

int countUnivalTree(TreeNode *root){
    int count=0;
    univalHelper(root, 0, &count);
    return count;
}
 

int main(int argc, char *argv[]){
        string str("5 5 5 5 5 # 5 # # # # # # # #");
        TreeNodeMgr mgr;
        cout<<"Recursive Serial/DeSerial"<<endl;
        istringstream istr(str);
        ostringstream ostr;
        TreeNode* root = mgr.deSerializeRecur(istr);
        mgr.serializeRecur(root, ostr);
        string tempStr = ostr.str();
        cout<<"str ="<<str<<endl;
        cout<<"tempStr ="<<tempStr<<endl;

        cout<<"Iterative Serial/DeSerial"<<endl;
        root = mgr.deSerializeIter(str);
        tempStr = mgr.serializeIter(root);
        cout<<"str ="<<str<<endl;
        cout<<"tempStr ="<<tempStr<<endl;

        cout<<"count unival="<<countUnivalTree(root)<<endl;
        return 0;
}                       
