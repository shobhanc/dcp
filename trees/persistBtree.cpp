/*
 * Given the root to a binary tree, implement serialize(root), which serializes the tree into a string,
 * and deserialize(s), which deserializes the string back into the tree.
 */

#include<iostream>
#include "treeNode.h"
#include "treeNodeMgr.h"

int main(int argc, char *argv[]){
	string str("1 2 3 # # 4 5 # # # #");
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
	return 0;
}
