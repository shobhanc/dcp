/*
 * Given an array 1,2,3 print all the permutations
 * 123,132,231,213,321,312
 */
#include <vector>
using namespace std;

//time O(N*N!) and space O(N*N!)
/*
 * Recursion Stack
 * i=0, j=0, array=1 2 3
 *    i=1, j=1, array=1 2 3
 *       2 ADD 1 2 3
 *    i=1, j=2, array=1 3 2
 *       2 ADD 1 3 2
 * i=0, j=1, array=2 1 3
 *    i=1, j=1, array=2 1 3
 *       2 ADD 2 1 3
 *    i=1, j=2, array=2 3 1
 *       2 ADD 2 3 1
 * i=0, j=2, array=3 2 1
 *    i=1, j=1, array=3 2 1
 *       2 ADD 3 2 1
 *    i=1, j=2, array=3 1 2
 *       2 ADD 3 1 2
 */
void helper(int i, vector<int> &array, vector<vector<int>> & ret){
	if(i==array.size()-1){
		ret.push_back(array);
	}else{
		for(int j=i; j<array.size(); j++){
			swap(array[i],array[j]);
			helper(i+1, array, ret);
			swap(array[i],array[j]);
		}
	}
}

vector<vector<int>> getPermutations(vector<int> array) {
	vector<vector<int>> ret;
	helper( 0, array, ret);
	return ret;
}
