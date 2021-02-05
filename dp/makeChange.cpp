/*
 * Given a set of denominations [1,2,5] and an amount.
 * Find all possible ways to change using the denominations.
 *
 */

//time O(2^(A+D)) and space O(A+D) - A amount D no. of denominations
int helper(int amount, vector<int>& denoms, int idx){
	if(idx==denoms.size()){
		return 0;
	}
	if(amount==0){
		return 1;
	}
	//ignore the current denomination completely
	int exclude=helper(amount, denoms, idx+1);
	int include=0;
	if(amount>=denoms[idx]){
		//substract and try to reduce again with same denomination
		include=helper(amount-denoms[idx], denoms, idx);
	}
	return exclude+include;
}

int numberOfWaysToMakeChangeRec(int n, vector<int> denoms) {
	return helper(n, denoms, 0);
}

//time O(N) and space O(N)
int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> ways(n+1,0);
	ways[0]=1;
	for(auto d: denoms){
		for(int amount=1; amount<=n; amount++ ){
			if(d<=amount){
				ways[amount]+=ways[amount-d];
			}
		}
	}
	return ways[n];
}
