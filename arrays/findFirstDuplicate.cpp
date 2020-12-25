/*
 * input: [2, 1, 5, 2, 3, 3, 4]
 * first duplicate result is 2
 * find whose first duplicate value has the the minimum index
 *
 * other solutions could be to use a hashtable
 */

//[9, 13, 6, 2, 3, 5, 5, 5, 3, 2, 2, 2, 2, 4, 3]
//result should be 5 not 2
int findFirstDuplicate(vector<int> &array){
  int minIdx=INT_MAX;
	for(int i=0; i<array.size(); i++){
		for(int j=i+1; j<array.size(); j++){
			if(array[i]==araay[j]){
         minIdx=min(minIdx,j);
      }
		}
	}
	return minIdx==INT_MAX?-1:array[minIdx];;
}

int firstDuplicateValue(vector<int> array) {
	for(int i=0; i<array.size(); i++){
		int v=abs(array[i]);
		if(array[v-1]<0){
			return v;
		}else{
			array[v-1]*=-1;
		}
	}
	return -1;
}


