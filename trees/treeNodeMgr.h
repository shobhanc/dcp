/*
 * TreeNodeMgr library
 * Left<root and root>=right
 */
#ifndef TREENODEMGR_H
#define TREENODEMGR_H
#include<vector>
#include<sstream>
#include<queue>
#include "treeNode.h"

using namespace std;

class TreeNodeMgr{
	public:

		void inorderRec( TreeNode *root, vector<int> &res){
			if(root==nullptr){
				return;
			}
			inorderRec(root->left, res);
			res.push_back(root->val);
			inorderRec(root->right, res);
		}

		void preorderRec( TreeNode *root, vector<int> &res){
			if(root==nullptr){
				return;
			}
			res.push_back(root->val);
			inorderRec(root->left, res);
			inorderRec(root->right, res);
		}

		void postorderRec( TreeNode *root, vector<int> &res){
			if(root==nullptr){
				return;
			}
			inorderRec(root->left, res);
			inorderRec(root->right, res);
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
