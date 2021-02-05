/*
 * TreeNodeMgr library
 * Left<root and root>=right
 */
#ifndef TREENODEMGR_H
#define TREENODEMGR_H
#include<vector>
#include<sstream>
#include<stack>
#include<queue>
#include "treeNode.h"

using namespace std;

class TreeNodeMgr{
	public:
		//time O(N) space O(N)
		void inOrderRec( TreeNode *root, vector<int> &res){
			if(root==nullptr){
				return;
			}
			inOrderRec(root->left, res);
			res.push_back(root->val);
			inOrderRec(root->right, res);
		}

		//time O(N) space O(N)
		void inOrderIter( TreeNode *root, vector<int> &res){
			stack<TreeNode*> st;
			while(root || !st.empty())
			{
				//stack up the left most nodes
				//got to left most leaf
				if(root){
					st.push(root);
					root=root->left;
				}else{
					//pop and capture current node
					root=st.top();
					st.pop();
					res.push_back(root->val);
					//now stack up the right node's leftmost path
					root=root->right;
				}
			}
		}

		//time O(N) space O(N)
		void preOrderRec( TreeNode *root, vector<int> &res){
			if(root==nullptr){
				return;
			}
			res.push_back(root->val);
			preOrderRec(root->left, res);
			preOrderRec(root->right, res);
		}

		//time O(N) space O(N)
		void preOrderIter( TreeNode *root, vector<int> &res){
			stack<TreeNode*> st;
			//init stack with root
			st.push(root);
			while(!st.empty())
			{
				//pop and capture current node
				root=st.top();
				st.pop();
				res.push_back(root->val);
				//push right and then left to stack
				if(root->right)st.push(root->right);
				if(root->left)st.push(root->left);
			}
		}

		//time O(h) space O(N) 
		void preOrderIter2( TreeNode *root, vector<int> &array){
			stack<TreeNode*> st;
			while(root || !st.empty())
			{
				while(root){
					//gather current node
					array.push_back(root->val);
					//capture right node first
					//and left next to keep left on top
					if(root->right)
						st.push(root->right);
					//go to left node
					root=root->left;
				}
				//node stacked just before root became null
				//is not captured, to get from stack
				//and set to root to capture
				//and stack its right and left leafs
				if(!st.empty()){
					root=st.top();
					st.pop();
				}
			}
		}

		//time O(N) space O(N)
		void postOrderRec( TreeNode *root, vector<int> &res){
			if(root==nullptr){
				return;
			}
			postOrderRec(root->left, res);
			postOrderRec(root->right, res);
			res.push_back(root->val);
		}

		//time O(N) and space O(N) with one stack
		void postOrderTraverseIter(TreeNode *tree, vector<int> &array) {
						stack<TreeNode*> st;
						TreeNode* pre=NULL;
						while(tree || !st.empty()){
										//stack up all left leafs like inorder
										if(tree){
														st.push(tree);
														tree=tree->left;
										}else{
														tree=st.top();
														//check if leftmost's right is empty or
														//already processed, if yes capture the node
														//and set it to already processed
														//else go capture the right leaf's left
														//leafs
														if(tree->right==NULL || tree->right==pre){
																		st.pop();
																		array.push_back(tree->val);
																		pre=tree;
																		tree=NULL;
														}else{
																		tree=tree->right;
														}
										}
						}
		}

		//time O(N) and space O(N) with two stack
		void postOrderTraverseIter(TreeNode *tree, vector<int> &array) {
						stack<TreeNode*> s1,s2;
						//init s1 with root
						s1.push(tree);
						// push each node from s1 to s2 and
						// push its left and right to s1
						// and repeat.
						while(!s1.empty()){
										tree=s1.top();
										s2.push(tree);
										s1.pop();
										if(tree->left)s1.push(tree->left);
										if(tree->right)s1.push(tree->right);
						}
						//capture all nodes in s2
						while(!s2.empty()){
										tree=s2.top();
										array.push_back(tree->val);
										s2.pop();
						}
		}

		//run time O(N) space O(D) for recursion stack, depth of the tree
		void serializeRecur( TreeNode *root, ostringstream &ostr){
			if(root==nullptr){
				ostr<<"# ";
				return;
			}
			ostr<<root->val<<" ";
			serializeRecur(root->left, ostr);
			serializeRecur(root->right, ostr);
		}

		//run time O(N) space O(D) for recursion stack, depth of the tree
		TreeNode* deSerializeRecur(istringstream &istr){
			string str;
			istr>>str;
			if(str=="#"){
				return nullptr;
			}
			TreeNode *root = new TreeNode(stoi(str));
			root->left = deSerializeRecur(istr);
			root->right = deSerializeRecur(istr);
			return root;
		}

		//run time O(N) space O(1)
		string serializeIter(TreeNode *root){
			queue<TreeNode*> q;
			ostringstream ostr;
			if(root==nullptr){
				return "# ";
			}
			q.push(root);

			while(!q.empty()){
				TreeNode* temp = q.front();
				q.pop();
				if(temp == nullptr){
					ostr<<"# ";
				}else{
					ostr<<temp->val<<" ";
					q.push(temp->left);
					q.push(temp->right);
				}
			}
			return ostr.str();
		}

		//run time O(N) space O(1)
		TreeNode* deSerializeIter(string str){
			if(str == "# "){
				return nullptr;
			}
			istringstream istr(str);
			string v;
			istr>>v;
			TreeNode* root = new TreeNode(stol(v));
			queue<TreeNode*> q;
			q.push(root);
			while(!q.empty()){
				TreeNode *temp = q.front();
				q.pop();
				if(istr){
					istr>>v;
					if(v!="#"){
						temp->left=new TreeNode(stol(v));
						q.push(temp->left);
					}
				}
				if(istr){
					istr>>v;
					if(v!="#"){
						temp->right=new TreeNode(stol(v));
						q.push(temp->right);
					}
				}
			}
			return root;
		}
};
#endif
