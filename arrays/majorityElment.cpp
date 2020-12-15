/*
 * If a number repeats more than n/2 times its a majority element.
 * Other ways to solve the problem
 * Brute force search each element in the array with O(n^2) time and O(1) space
 * keep track in a hashtable with extra space  O(n) and time O(n)
 * sort the array and then count with O(nlogn) time and O(1) or O(n) space
 * randomly pick an element and check if its the majority element O(Infinity) time and O(1) space
 */
#include<iostream>
#include<vector>

using namespace std;

//O(n) time and O(1) space
int findMajority(vector<int> &v){
	int major=0;
	int count=0;
	for(auto a:v){
		if(count==0){
			major=a;
			count++;
		}else{
			if(major==a)
				count++;
			else
				count--;
		}
	}
	return count>0?major:-1;
}

int main(int argc, char*argv[]){
	vector<int> v={1,2,3,4,5,5,5,5,5};
        cout<<"Majority Element "<<findMajority(v)<<endl;
	return 0;
}
