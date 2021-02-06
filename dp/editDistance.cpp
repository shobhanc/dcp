/* Given two strings "abc" and "yabd"
 * Find the minimum number of operations to change from first to second string * using operations like replace/delete/insert
 */

//time O(NM) and space(NM)
int levenshteinDistance(string str1, string str2) {
	vector<vector<int>> dp(str2.length()+1,
			vector<int>(str1.length()+1,0));
	for(int i=0; i<str2.length()+1; i++){
		dp[i][0]=i;//str2 length>0 and str1 length=0
	}
	for(int j=0; j<str1.length()+1; j++){
		dp[0][j]=j;//str1 length>0 and str2 length==0
	}

	for(int i=1; i<str2.length()+1; i++){
		for(int j=1; j<str1.length()+1; j++){
			//when chars match
			if(str2[i-1]==str1[j-1]){
				dp[i][j]=dp[i-1][j-1];
			}else{//get min+1 of case where
				//char operation insert/delete/substitue
				//can be used to transform
				dp[i][j]=1+min(dp[i-1][j-1],
						min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}
	return dp[str2.length()][str1.length()];
}

//time O(NM) and space O(min(N,M))
int levenshteinDistance(string str1, string str2) {
	//pick the small and the big string based on lengths
	string small=str1.length()<str2.length()?str1:str2;
	string big=str1.length()>=str2.length()?str1:str2;
	vector<int> even(small.length()+1,0);
	vector<int> odd(small.length()+1,0);
	for(int i=0; i<small.length()+1; i++){
		even[i]=i;
	}
	//init cur and prev for both strings of length==0
	//always examine row index 1 first as row index 0 is
	//pre-initialised as above
	vector<int> *cur = &even;
	vector<int> *prev = &odd;
	for(int i=1; i<big.length()+1; i++){
		if(i%2==1){
			//examining the odd index, cur row is odd and prev row is even
			//start examining by row index 1
			prev = &even;
			cur = &odd;
		}else{
			//examining the even index, prev row is odd and cur row is even
			prev = &odd;
			cur = &even;
		}
		(*cur)[0]=i;
		for(int j=1; j<small.length()+1; j++){
			if(small[j-1]==big[i-1]){
				(*cur)[j]=(*prev)[j-1];
			}else{
				(*cur)[j]=1+min((*prev)[j-1], min((*prev)[j],(*cur)[j-1]));
			}
		}
	}
	//return the cur rows lasts element
	return (*cur)[small.length()];
}


