/*
 * Given an array, check if its acending or descending only
 * input: [1,2,3,4,5] or [4,3,2,1] output: true
 *        [1,3,5,0,9] output: false
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
