/*
 * Given an array, find the maximum sum of adjacent sub array
 *
 * input [3,5,-9,1,3,-2,3,4,7,2,-9,6,3,1,-5,4]
 * output : 19 //[1,3,-2,3,4,7,2,-9,6,3,1]
 */

//time O(N) and space O(1)
int kadanesAlgorithm(vector<int> array) {
	//sum init 0
	int maxEndingHere=0;
	int maxSoFar=INT_MIN;
	for(auto a:array){
		//is cur element higher or the sum so far
		maxEndingHere=max(a,maxEndingHere+a);
		//capture max sum so far
		maxSoFar=max(maxSoFar,maxEndingHere);
	}
	return maxSoFar;
}
