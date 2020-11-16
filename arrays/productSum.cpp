/*
 * Given an array of integers, return a new array such that each element at index i of the new array
 * is the product of all the numbers in the original array except the one at i.
 * For example, if our input was [1, 2, 3, 4, 5], the expected output would be
 * [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 */

#include<vector>
#include<iostream>

using namespace std;

//run time O(N) space O(N)
vector<long long int> getProductSum(vector<int> &v){
	vector<long long int> res(v.size(),1);
	int p=1;
	//1, 1, 1*2,1*2*3,1*2*3*4
	for(int i=0; i<v.size(); i++){
		res[i]=p;
		p*=v[i];
	}
	p=1;
	//now start repeating the above in reverse
	for(int i=v.size()-1; i>=0; i--){
		res[i]*=p;
		p*=v[i];
	}
	return res;

}

int main(int argc, char *argv[]){
	vector<int> v={1,2,3,4,5};
	vector<long long int> res = getProductSum(v);
	for(auto a: res){
		cout<<a<<" ";
	}
	cout<<endl;
}
