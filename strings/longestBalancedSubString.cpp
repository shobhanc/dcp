/*
 * Longest Balanced Substring
 *
 * input:()()(()))
 * output:8
 *
 * input:)(()))
 * output:4
 *
 * input:()()))
 * output:4
 */
#include<stack>
using namespace std;

bool isBalanced(string &str){
	stack<int> st;
	for(int i=0; i<str.length(); i++){
		if(str[i]=='('){
			st.push(i);
		}else if(!st.empty()){
			st.pop();
		}else{
			return false;
		}
	}
	return st.empty();
}

//O(N^3) time and O(1) space O(n)
//Check if each substring is balanced and capture max length
int longestBalancedSubstring(string str) {
	int max_len=0;
	for(int i=0; i<str.length(); i++){
		for(int j=i+2; j<str.length()+1; j++){
			string sstr = str.substr(i,j-i);
			if(isBalanced(sstr) && max_len<sstr.length()){
				max_len=sstr.length(); 
			}
		}
	}
	return max_len;
}

//time O(N) and space O(N)
// keep track of begining index, with init set to -1
// keep track of max balanced length and
// replace beginning index as needed
int longestBalancedSubstring(string str) {
	vector<int> v;
	v.push_back(-1);
	int max_len=0;
	for(int i=0; i<str.length(); i++){
		if(str[i]=='('){
			v.push_back(i);
		}else{
			v.pop_back();
			if(v.empty()){
				//mark new begining
				v.push_back(i);
			}else{
				int lastBalanced = v[v.size()-1];
				int len = i-lastBalanced;
				max_len=max(len,max_len);
			}
		}
	}
	// Write your code here.
	return max_len;
}

//time O(N) and space O(1)
//scan left to right till more closes than opens and record max len
//scan right to left till more opens than closes and record max len
int longestBalancedSubstring(string str) {
	int op=0, cls=0, max_len=0;
	for(auto a:str){
      if(a=='('){
         op++;
			}else{
         cls++;
			}
		  if(op==cls){
        max_len=max(max_len,2*cls);
			}else if(cls>op){
         op=0;
				 cls=0;
			}
	}
	op=0;
	cls=0;
	for(int i=str.length()-1; i>=0; i--){
      if(str[i]=='('){
         op++;
			}else{
         cls++;
			}
		  if(op==cls){
        max_len=max(max_len,2*cls);
			}else if(op>cls){
         op=0;
				 cls=0;
			}
	}
	// Write your code here.
  return max_len;
}

