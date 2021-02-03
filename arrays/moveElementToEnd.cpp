/*
 * Move element to end
 * Given an array 
 * [2,1,2,2,2,3,4,2]
 * move all 2's to the end
 * output: [1,3,4,2,2,2,2,2]
 */

//time O(N) and space O(1)
vector<int> moveElementToEnd(vector<int> array, int toMove) {
	int l=0, r=array.size()-1;
	//skip already moved elements
	while(r>=l && array[r]==toMove){
		r--;
	}
	while(l<r){
		if(array[l]==toMove){
			swap(array[l],array[r]);
			r--;
		}else{
			l++;
		}
	}
	return array;
}
