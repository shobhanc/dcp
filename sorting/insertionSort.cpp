/*
 * Insertion sort of an array.
 *
 * first sort 0,1
 * next  sort 0,1,2
 * next  sort 0,1,2,3
 */

//worst & average time O(N^2) and space O(1)
//best time O(N) and space O(1)
vector<int> insertionSort(vector<int> array) {
	for(int i=1; i<array.size(); i++){
		int j=i;
		while(j>0 && array[j]<array[j-1]){
			swap(array[j],array[j-1]);
			j--;
		}
	}
	return array;
}
