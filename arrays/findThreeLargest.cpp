/*
 * Given an unsorted array, return the largest k elements
 * without sorting the array.
 *
 * input [10,5,9.10.12]
 * largest 3 elements
 * output [10,10,12]
 */

//time O(N) and space O(k)
void leftShift(vector<int> &largest, int from){
	int prev=INT_MIN, temp=0;
	for(int i=from; i>=0; i--){
		temp=largest[i];
		largest[i]=prev;
		prev=temp;
	}
}

//time O(Nk) and space O(k)
vector<int> findThreeLargestNumbers(vector<int> array, int k) {
	// Write your code here.
	vector<int> largest(k,INT_MIN);
	for(int i=0; i<array.size(); i++){
		//ignore if the current element is less
		//than the smallest of the largest
		if(array[i]<largest[0]){
			continue;
		}
		int j=k-1;
		//start checking from the largest,
		// if the element is larger than one of the 
		// largest element, left shift the largest
		// array and create space for new largest
		// element and replace
		while(j>=0){
			if(array[i]>=largest[j]){
				leftShift(largest,j);
				largest[j]=array[i];
				break;
			}
			j--;
		}
	}
	return largest;
}
