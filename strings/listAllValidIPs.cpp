/*
 * Valid IP Addresses from a given string
 *
 * input:"1921680"
 * output:
 * [
  "1.9.216.80",
  "1.92.16.80",
  "1.92.168.0",
  "19.2.16.80",
  "19.2.168.0",
  "19.21.6.80",
  "19.21.68.0",
  "19.216.8.0",
  "192.1.6.80",
  "192.1.68.0",
  "192.16.8.0"
 *]
 */
bool isValid(string &str){
	if(str.length()==0) return false;
	if(str.length()>1 && str[0]=='0') return false;
	int i=atoi(str.c_str());
	if(i>=0 && i<256)	return true;
	return false;
}

//time O(1) and space  O(1)
vector<string> validIPAddresses(string str) {
	// Write your code here.
	vector<string> v;
	//generate substring from 0 index with lengths of string 1,2,3
	//validate each substring for IP octet
	for(int i=1; i<4 && i<str.length(); i++){
		string one = str.substr(0,i);
		if(!isValid(one)) continue;

	//generate substring from next index with lengths of string 1,2,3
	//validate each substring for IP octet
		for(int j=1; j<4 && (i+j)<str.length(); j++){
			string two=str.substr(i,j);
			if(!isValid(two)) continue;

	//generate substring from next index with lengths of string 1,2,3
	//validate each substring for IP octet
			for(int k=1; k<4 && (i+j+k)<str.length(); k++){
				string three=str.substr(i+j,k);
				if(!isValid(three)) continue;

	//generate substring from next index with lengths of string 1,2,3
	//validate each substring for IP octet
				string four=str.substr(i+j+k);
				if(!isValid(four)) continue;

				string str_out;
				str_out=one+"."+two+"."+three+"."+four;

				v.push_back(str_out);
			}
		}
	}
	return v;
}
