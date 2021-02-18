/*
 * Construct a Suffix Trie from a given string
 *
 * input: "babc"
 * output structure
 * {
 * 'c':{'*':true}
 * 'b':{
 *   'c':{'*':true}
 *   'a':{'b':{'c':{'*':true}}}
 * }
 * 'c':{'b':{'c':{'*':true}}}
 */


#include <unordered_map>
using namespace std;

class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;

  SuffixTrie(string str) {
    this->root = new TrieNode();
		//'*' indicates that it reached end of the substring
    this->endSymbol = '*';
    this->populateSuffixTrieFrom(str);
  }

	//time O(N^2) and space O(N^2)
  void populateSuffixTrieFrom(string str) {
    for(int i=0; i<str.length(); i++){
			TrieNode* cur=this->root;
			//keep taking substring starting from index 0,1 and so on
			//and keep inserting starting from root for each substring
			for(int j=i; j<str.length(); j++){
				char c=str[j];
				//if current char not found create a new node and insert
    		if(cur->children.find(c)==cur->children.end()){
		     	 cur->children.insert({c,new TrieNode()});
			  }
				//go to the next node and check for next char
				cur=cur->children[c];
		  }
			//insert '*' at the end of substring
			cur->children.insert({this->endSymbol,NULL});
		}
  }

	//time O(N) and space O(1)
  bool contains(string str) {
		TrieNode* cur=this->root;
    for(auto c: str){
			//if you can't find the next char return false
    	if(cur->children.find(c)==cur->children.end()){
		   	return false;
		  }
			//go to next node and check for next char
			cur=cur->children[c];
		}
		//make sure the end of the substring is reached for a perfect match
    return cur->children.find(this->endSymbol)!=cur->children.end();
  }
};


