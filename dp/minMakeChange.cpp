/* Given a set of denominations and an amount
 * get the min coins required to make change.
 *
 */

//time O(A*N) and space O(A) - A -amount and N - number of coins
int minNumberOfCoinsForChange(int n, vector<int> denoms) {
	//init dp array with n+1
	//as number of coins required can't be more than amount
	vector<int> ways(n+1, n+1);
	ways[0]=0;
	for(int amount=1; amount<=n; amount++)
	{
		for(auto d: denoms)
		{
			if(amount>=d){
				ways[amount]=min(ways[amount], ways[amount-d]+1);
			}
		}
	}
	return ways[n]>n? -1: ways[n];
}


//time O(A^N) and space O(A+N) - A -amount and N - number of coins
int minNumberOfCoinsForChangeRec(int n, vector<int> denoms) {
	if(n<=0){
		return 0;
	}
	int best=n+1;
	for(auto d:denoms){
		if(n>=d){
			int res = minNumberOfCoinsForChangeRec(n-d,denoms);
			best=min(best,res+1);
		}
	}
	return best>n?0:best;
}


