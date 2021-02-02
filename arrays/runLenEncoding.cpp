/*
 * Run Length Encoding
 *
 * input: AAAAAAAAAABBBC
 * output: 9A1A3B1C
 */

//time O(N) and space(N)
string runLengthEncoding(string str) {
	if(str.length()==0){
		return "";
	}
	char prev=str[0];
	string strout;
	int cnt=1;
	for(int i=1; i<str.length(); i++){
		if(str[i]!=prev || cnt==9){
			strout+=to_string(cnt)+prev;
			cnt=1;
			prev=str[i];
		}else{
			cnt++;
		}
	}
	strout+=to_string(cnt)+prev;
	return strout;
}


