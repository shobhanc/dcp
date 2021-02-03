/*
 * Given an array of integers between 1 and n, inclusive where n is
 * the length of the array. Return the first integer that is a duplicate
 * when going from left to right.
 *
 * input: [2,1,5,2,3,3,4]
 * output: 2
 */

//
//take absolute value of element E in index I
//mark the element in array[E] as -ve
//if the element is already marked then we found out duplicate.
//We are using same array to mark discovered elements with -ve
//marker
//
//other solutions:
//1. loop from 1-n and look for duplicates in the same array
//   time O(N^2) and space O(1)
//
//2. Use a hashtable to keep track of dicovered ellements, with
//  time O(N) and space O(N)



//time O(N) and space O(1)
int firstDuplicateValue(vector<int> array) {
	for(int i=0; i<array.size(); i++){
		int idx = abs(array[i]);
		if(array[idx-1]<0){
			return idx;
		}
		array[idx-1]=-array[idx-1];
	}
	return -1;
}


