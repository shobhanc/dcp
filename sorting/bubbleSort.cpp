/*
 * Sort an array using bubble sort.
 *
 * Keep swapping neighbors from 0 to end of the array till
 * there is no need to swap to make lower index smaller than
 * the larget neighbor
 */

//averga and worst time O(N^2) and space O(1)
//best time O(N) and space O(1)
vector<int> bubbleSort(vector<int> array) {
	// Write your code here.
	int isSorted=0;
	while(!isSorted){
		isSorted=1;
		for(int j=0; j<array.size()-1; j++){
			if(array[j]>array[j+1]){
				swap(array[j],array[j+1]);
				isSorted=0;
			}
		}
	}
	return array;
}
