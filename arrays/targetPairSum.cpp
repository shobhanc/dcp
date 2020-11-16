/*
 * Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
 * For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 * Bonus: Can you do this in one pass?
 *
 * Variants:
 * Extra space
 * Change original array
 * Duplicates in original array.
 *
 * corner cases
 * number of elements less than 2
 */
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<iostream>

using namespace std;

//1,2,3,4,5  target=6
//run time O(N^2) space O(1)
vector< vector<int> > bt_getTargetSumPair(vector<int> &vec, int target){
    if(vec.size()<2) { return {}; }
    vector< vector<int> > res;
    for(int i=0; i<vec.size()-1; i++){
	    for(int j=i+1; j<vec.size(); j++){
		    if(target == (vec[i]+vec[j])){
			    res.push_back({vec[i],vec[j]});
		    }
	    }
    }
    return res;
}

//run time O(N + N Log(N))=O(N Log N) space O(1)
//can change original array
vector< vector<int> > opt1_getTargetSumPair(vector<int> &vec, int target){
	if(vec.size()<2) { return {}; }
	vector< vector<int> > res;
	sort(vec.begin(), vec.end());
	int l=0;
	int r=vec.size()-1;
	while(l<r){
		int sum=vec[l]+vec[r];
		if(sum==target){
			res.push_back({vec[l],vec[r]});	    
			l++;
			r--;
		}else if(sum>target){
			r--;
		}else{
			l++;
		}
	}
	return res;
}

//run time O(N) space O(N)
//additional space ok
vector< vector<int> > opt2_getTargetSumPair(vector<int> &vec, int target){
	if(vec.size()<2) { return {}; }
        vector< vector<int> > res;
	unordered_set<int> vals;
	for(auto a: vec){
		int diff=target-a;
		if(vals.count(diff)){
			res.push_back({a,diff});
		}else{
		   vals.insert(a);
		}
	}
	return res;

}

//run time O(N) space O(N)
//possible duplicates
//additional space ok
//remove duplicated
vector< vector<int> > opt3_getTargetSumPair(vector<int> &vec, int target){
	if(vec.size()<2) { return {}; }
        vector< vector<int> > res;
	vector<int> filtered;
	unordered_set<int> mp;//val, bitmap
	for(int i=0; i<vec.size(); i++){
		if(mp.count(vec[i])==0){
		   mp.insert(vec[i]);
		   filtered.push_back(vec[i]);
		}
	}
	return opt2_getTargetSumPair(filtered,target);
}

int main(int argc, char *argv[]){
	vector<int> v = {1,2,3,4,5,5};
	int target=6;
	vector< vector<int> > res;
        res = opt1_getTargetSumPair(v, target);
        //res = opt2_getTargetSumPair(v, target);
        //res = opt3_getTargetSumPair(v, target);
        //res = bt_getTargetSumPair(v, target);
	for(auto a: res){
		cout<<a[0]<<","<<a[1]<<endl;
	}
	return 0;
}
