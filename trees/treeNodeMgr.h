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
				while(root){
					st.push(root);
					root=root->left;
				}
				root=st.top();
				st.pop();
				res.push_back(root->val);
				root=root->right;
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
			st.push(root);
			while(!st.empty())
			{
				root=st.top();
				st.pop();
				res.push_back(root->val);
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
					array.push_back(root->val);
					if(root->right)
						st.push(root->right);
					root=root->left;
				}
				if(!st.empty()){
					root=st.top();
					st.pop();
				}
			}
		}

		void postOrderRec( TreeNode *root, vector<int> &res){
			if(root==nullptr){
				return;
			}
			postOrderRec(root->left, res);
			postOrderRec(root->right, res);
			res.push_back(root->val);
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
