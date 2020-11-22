/*
 * Given an array of integers, find the first missing positive integer in linear time and constant space.
 * In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.
 * For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.
 *
 * Discussion:
 * array of n cells and range of ints [1..n]
 * A) if there are no missing numbers from [1..n] then answer is n+1
 * B) if there is a missing integer X it must be in the range of [1..n]
 *
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

//runtime O(n) and space O(n)
int bruteForce_firstMissingPositiveInt(vector<int> &v){
     unordered_set<int> us;
     for(auto a: v){
        us.insert(a);
     }
     for(int i=1; i<=v.size(); i++){
       if(us.count(i)==0){
         return i;
       } 
     }
     return v.size()+1;
}

//runtime O(n) and space O(1)
int firstMissingPositiveInt(vector<int> &v){
        int n=v.size();
        int idx=0;
        //ignore all numbers <= 0 and > n not in the range of [1..n], replace them with the value n+1
	for(int i=0; i<n; i++){
           if(v[i]<=0 || v[i]>n){
              v[i]=n+1;
           }
	}
	for(int i=0; i<n; i++){
          //could be discovered cell get absolute value
          idx=abs(v[i]);

          //ignore previously ignored cells
          if(idx>n) continue;

          //cell is not discovered, mark it discovered
          if(v[idx-1]>0){
            //mark the cell as discovered
            //for all integers<n+1, mark the bucket to indicate the integers exists
            v[idx-1]=-1*v[idx-1];
          }
        }

        for(int i=0; i<n; i++){
          //first undiscovered cell return idx+1
          //find the first cell not marked, that missing integer. if not unmarked cell then there is no missing int return n+1
          if(v[i]>0){
            return i+1;
          }
        }
        //all [1..n] are present return n+1
	return n+1;
}

int main(int argc, char*argv[]){
	//vector<int> v={3,4,-1,1};
	//vector<int> v={1,2,0};
	vector<int> v={7,8,9,11,12};
	//int missed = bruteForce_firstMissingPositiveInt(v);
	int missed = firstMissingPositiveInt(v);
	cout<<"missed="<<missed<<endl;
	return 0;
}
