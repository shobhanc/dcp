/*
 * Sort an array using selection sort
 *
 * find smallest of 0 to n and swap with index 0
 * find smallest of 1 to n and swap with index 1
 * and so on
 */

//best, average and worst time O(N^2) and space O(1)
vector<int> selectionSort(vector<int> array) {
	// Write your code here.
	for(int i=0; i<array.size()-1; i++){
		int mnIndex=i;
		for(int k=i+1; k<array.size(); k++){
			if(array[mnIndex]>array[k]){
				mnIndex=k; 
			}
		}
		swap(array[i],array[mnIndex]);
	}
	return array;
}


