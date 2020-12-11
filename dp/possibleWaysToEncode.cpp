/*
 * Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
 * For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
 * You can assume that the messages are decodable. For example, '001' is not allowed.
 *
 * Need to consider that a single digit can map to a char and/or a double digit can map to the char.
 * There is only few ways to include the last digit with correct mappings. e.g: 229 can map the last mapping
 * only 9. So need to find all the mapping that allow that so 2,2,9 and 22,9
 */
#include<iostream>
#include<string>
#include<vector>

using namespace std;

//recursion
//O(2^N) time and O(N) space
int recEncodeMessage(string str, int i=0){
    if(str.length()==0)
      return 0;
    if(str[i]=='0')
     return 0;
    if(i==str.length()){
      return 1;
    }
    int ret=recEncodeMessage(str, i+1);
    if(i<str.length()-1 &&
      ((str[i]=='1' && str[i+1]>='0' && str[i+1]<='9') ||
      (str[i]=='2' && str[i+1]>='0' && str[i+1]<='2')))
      ret+=recEncodeMessage(str,i+2); 
    return ret;
}

//DP solution
//O(N) space and O(N) time
int encodeMessage(string &str){
	int len=str.length();
	if(len==0 || (len>=1 && str[0]=='0')){
		return 0;
	}
	vector<int> dp(len, 0);
	dp[0]=1;//assume there is atleast one mapping
	for(int i=1; i<=len;i++){
		if(str[i]>='1' && str[i]<='9'){//valid single digit
			dp[i]+=dp[i-1];//add all valid possibilities till now
		}
		if(i<len &&
		((str[i-1]=='1' && str[i]>='0' && str[i]<='9') ||
		 (str[i-1]=='2' && str[i]>='0' && str[i]<='6')))//valid double digit
		{
			if(i>2){
				dp[i]+=dp[i-2];//add all valid possibilities till now
			}else{
				dp[i]+=1;//first double digit
			}
		}
	}
	return dp[len-1];
}

int main(int argc, char *argv[]){
	if(argc!=2){
		return 1;
	}
	string message(argv[1]);
	cout<<"possible ways to encode="<<encodeMessage(message)<<endl;
	return 0;
}
