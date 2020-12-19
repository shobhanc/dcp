/*
 *
 * Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 *
 */

//Add first half arrays to hashtable in a nested fashion O(N^k/2) time and O(N^k/2) space
void addToHash(vector<vector<int>> &arrays, unordered_map<int,int> &mp, int s, int e, int sum)
{
	if(s==e){
		mp[sum]++;
	}else{
		for(auto a:arrays[s]){
			addToHash(arrays, mp, s+1,e, sum+a);
		}
	}
}

//lookup the remaining half in the previous hashtable in a nested fashion O(N^(k+1)/2) time and O(N^k/2) space
int lookupAndCount(vector<vector<int>> &arrays, unordered_map<int,int> &mp, int s, int complement)
{
	if(s==arrays.size()){
		if(mp.find(complement)!=mp.end()){
			return mp[complement];
		}
		return 0;
	}
	int cnt=0;
	for(auto a: arrays[s]){
		cnt+=lookupAndCount(arrays, mp, s+1, complement-a);
	}
	return cnt;
}


// O(N^(k+1)/2) time and O(N^k/2) space
//basic idea put a+b in hashtable m[a+b]=1
//lookup -a-b in hash table by -(-a)-(-b) in m
int kSumCount(vector<vector<int>> &arrays, int k)
{
	unordered_map<int,int> mp;
	addToHash(arrays, mp, 0, arrays.size()/2, 0);
	return lookupAndCount(arrays, mp, arrays.size()/2, k);
}


