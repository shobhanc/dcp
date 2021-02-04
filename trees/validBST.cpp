/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 *
 * Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
 */
class Solution {
public:
    //iterative time O(N) and O(N) space
    bool helper(TreeNode* root, TreeNode* mn, TreeNode *mx){
        if(root==NULL){
            return true;
        }
        if( (mn!=NULL && root->val<=mn->val) ||
            (mx!=NULL && root->val>=mx->val)){
            return false;
        }
        return helper(root->left, mn, root) &&
               helper(root->right, root, mx);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
        //return helper1(root);
    }
    
    //iterative time O(N) and O(N) space
    bool helper1(TreeNode* root){
        queue<TreeNode*> mns,mxs;
        queue<TreeNode*> q;
        if(root==NULL){
            return true;
        }
        q.push(root);
        mxs.push(NULL);
        mns.push(NULL);
        while(!q.empty()){
            TreeNode* n=q.front();
            TreeNode* mn=mns.front();
            TreeNode* mx=mxs.front();
 
            q.pop();
            mns.pop();
            mxs.pop();
            
            if(mx!=NULL && n->val>=mx->val){
               return false;
            }
            if(mn!=NULL && n->val<=mn->val){
               return false;
            }
            if(n->left){
              q.push(n->left);
              mns.push(mn);
              mxs.push(n);
            }
            if(n->right){
              q.push(n->right);
              mns.push(n);
              mxs.push(mx);
            }
            
        }
        return true;
    }
    

};

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

//time O(N) and space O(N)
bool helper(BST* tree, int mn, int mx){
	 if(tree==NULL){
      return true;
	 }
	if(tree->value<mn || tree->value>=mx){
      return false;
	 }
	 return helper(tree->left, mn, tree->value) &&
		      helper(tree->right, tree->value, mx);
}

bool validateBst(BST *tree) {
	return helper(tree, INT_MIN, INT_MAX);
}
