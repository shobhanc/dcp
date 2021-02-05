/*
 * Given an array return the max non adjacent sum.
 * input: [75,105,120,75,90,135]
 * output: 330 = 75+120+135
 */

//time O(N) and space O(N)
int maxSubsetSumNoAdjacent(vector<int> array) {
	if(array.size()==0) return -1;
	if(array.size()==1) return array[0];
	array[1]=max(array[0],array[1]);
	for(int i=2; i<array.size(); i++){
		array[i]=max(array[i-1],array[i]+array[i-2]);
	}
	return array[array.size()-1];
}

//time O(N) and space O(1)
int maxSubsetSumNoAdjacent(vector<int> array) {
	if(array.size()==0) return 0;
	if(array.size()==1) return array[0];
	int second=array[0];
	int first=max(array[0],array[1]);
	for(int i=2; i<array.size(); i++){
     int temp=max(first,array[i]+second);
		 second=first;
		 first=temp;
	}
	return first;
}
