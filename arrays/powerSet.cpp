/*
 * Given an array 1,2,3
 * return the power set
 * {},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}
 */

#include <vector>
using namespace std;

//time O(N*2^N) and space O(N*2^N)
vector<vector<int>> powersetIter(vector<int> array) {
	vector<vector<int>> res;
	//add empty list
	res.push_back({});
	for(int i=0; i<array.size(); i++){
		int sz=res.size();
		//pick the current combinations and add
		//new elements and add that to current set
		//and repeat
		for(int j=0; j<sz; j++){
			vector<int> v = res[j];
			v.push_back(array[i]);
			res.push_back(v);
		}
	}
	return res;
}

//time O(N*2^N) and space O(N*2^N)
vector<vector<int>> helper(int i, vector<int> &array){
	if(i<0){
		return {{}};
	}
	vector<vector<int>> res = helper(i-1, array);
	int sz=res.size();
	for(int j=0; j<sz; j++){
		vector<int> v = res[j];
		v.push_back(array[i]);
		res.push_back(v);
	}
	return res;
}

vector<vector<int>> powersetRec(vector<int> array) {
	return helper(array.size()-1,array);
}
