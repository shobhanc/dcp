/*
 * Given phone number mapping to characters as on phone
 * 2-abc
 * 3-def
 * 4-ghi
 * 5-jkf
 * 6-mno
 * 7-pqrs
 * 8-tuv
 * 9-wxyz
 * 0-
 * 1-
 *
 * input: i"1905"
 * output:
 [
  "1w0j",
  "1w0k",
  "1w0l",
  "1x0j",
  "1x0k",
  "1x0l",
  "1y0j",
  "1y0k",
  "1y0l",
  "1z0j",
  "1z0k",
  "1z0l"
]
*/

//Brute force time exponential and space exponential
vector<string> phoneNumberMnemonics(string phoneNumber) {
	// Write your code here.
	map<char,string> mp;
	mp.insert({'2',"abc"});
	mp.insert({'3',"def"});
	mp.insert({'4',"ghi"});
	mp.insert({'5',"jkl"});
	mp.insert({'6',"mno"});
	mp.insert({'7',"pqrs"});
	mp.insert({'8',"tuv"});
	mp.insert({'9',"wxyz"});
	vector<string> v;
	v.push_back(phoneNumber);	
	for(int i=0; i<phoneNumber.length(); i++){
		char c=phoneNumber[i]; 
		if(c=='0' || c=='1') continue;

		string alpha = mp[c];
		int sz=v.size();
		for(int j=0; j<sz; j++){
			string str=v[j];
			for(auto a: alpha){
				str[i]=a;
				v.push_back(str);
			}
		}
		for(int k=0; k<sz; k++){
			v.erase(v.begin());
		}
	}
	return v;
}

//time O(4^n*n) and space O(4^n*n)
void memnonicHelper(map<char,string> &mp, vector<string>& vout,
										int idx, string phoneNumber){
   if(idx==phoneNumber.length()){
      vout.push_back(phoneNumber);
		  return;
   }
	string alpha=mp[phoneNumber[idx]];
	for(auto a: alpha){
		  phoneNumber[idx]=a;
	    memnonicHelper(mp, vout, idx+1, phoneNumber);
	}
}

vector<string> phoneNumberMnemonics(string phoneNumber) {
  // Write your code here.
	map<char,string> mp;
	mp.insert({'2',"abc"});
	mp.insert({'3',"def"});
	mp.insert({'4',"ghi"});
	mp.insert({'5',"jkl"});
	mp.insert({'6',"mno"});
	mp.insert({'7',"pqrs"});
	mp.insert({'8',"tuv"});
	mp.insert({'9',"wxyz"});
	mp.insert({'1',"1"});
	mp.insert({'0',"0"});
  
	vector<string> vout;
	
	memnonicHelper(mp,vout,0,phoneNumber);
	
	return vout;
}


