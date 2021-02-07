/*
 * Given an array, the value of each element is the jump factor. If element value is 2 in index i, from i you cna jump to i+2. Starting from index 0 if you keep jumping based on the element value does it form a cycle. which mean after visiting all N nodes the N+1th node should be index 0.
 *
 * input: [2,3,1,-4,-1,2]
 * output:true
 */

int getNextId(vector<int> &array, int curIdx){
	int nextIdx=(curIdx+array[curIdx])%(int)array.size();
	return nextIdx>=0?nextIdx:nextIdx+(int)array.size();
}

//time O(N) and space O(1)
bool hasSingleCycle(vector<int> array) {
	int visited=0;
	int curIdx=0;
	while(visited<array.size()){
		//0 is visited again before
		//visiting all other elements
		//local loop detected exit
		//e.g: [0,1,1,1,1], [1,-1,-1,1]
		if(visited>0 && curIdx==0){
			return false;
		}
		//find next index after jump based
		//on current element value
		curIdx=getNextId(array,curIdx);
		visited++;
	}
	return curIdx==0;
}
