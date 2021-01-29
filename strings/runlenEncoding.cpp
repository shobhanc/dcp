/*
 * Run length encoding
 * len+char len for repetition count
 * len <=9 and len >=1
 *
 * input: "AAAAABCBB"
 * output: "5A1B1C2B"
 *
 * input: "AAAAAAAAAAABCBB"
 * output: "9A2A1B1C2B"
 */

//O(n) time and O(n) space
string runLengthEncoding(string str) {
	// Write your code here.
	string str_out;
	char prev, ch;
	int count=0, first=0;
	vector<int> vc;
	for(auto a:str){
		if(first==0){
			count=1;
			first=1;
			ch=a;
		}else if(prev!=a || count==9){
			vc.push_back(to_string(count)[0]);
			vc.push_back(ch);
			count=1;
			ch=a;
		}else{
			count++;
		}
		prev=ch;
	}

	vc.push_back(to_string(count)[0]);
	vc.push_back(ch);
	return string(vc.begin(),vc.end());
}
