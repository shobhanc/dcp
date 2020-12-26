/*
 * input binary tree and return diameter.
 * diameter=length of its longest path even if it does not pass thru root
 * path is collection of connected nodes.
 *           1
 *         1   2
 *       5  2   
 *     8     3
 *   6        4
 * 5           9
 *
 * output: 5,6,8,1,2,3,4,9 ==> 6 length
 */

#include "treeNode.h"

struct TreeCookie{
	int height;
	int diameter;
};

TreeCookie getTreeDetails(TreeNode* root){
	if(root==NULL){
		return TreeCookie{0,0};
	}
	TreeCookie left = getTreeDetails(root->left);
	TreeCookie right = getTreeDetails(root->right);

	//current diameter using sum of current heights
	//diameter = left height + right height
	int pathLen = left.height+right.height;
	//find max diameter so far
	int maxDiameter = max(right.diameter, left.diameter);
	//cur max height + 1 is the root's height
	int maxHeight = 1+max(right.height,left.height);
	//curDiameter is 1+max left path +max right path or the current max diameter
	int curDiameter = max(maxDiameter,pathLen);

	return TreeInfo{maxHeight, curDiameter};
}

int getMaxDiameter(TreeNode* root){
	TreeCookie root = getTreeDetails(root);
	return root.diameter;
}

int getMaxD(TreeNode* root, int &d){
	if(root==NULL){
		return 0;
	}

	int left_h=getMaxD(root->left,d);
	int right_h=getMaxD(root->right,d);
	d=max(d,left_h+right_h);
	return 1+max(left_h,right_h);
}

int getMaxDiameter2(TreeNode* root){
	int d=0;
        getMaxD(root, d);
	return d;
}

