/*
 * input: [2, 1, 5, 2, 3, 3, 4]
 * first duplicate result is 2
 *
 * other solutions could be to use a hashtable
 */

int findFirstDuplicate(vector<int> &array){
	for(int i=0; i<array.size()-1; i++){
		for(int j=i+1; j<array.size(); j++){
			if(array[i]==araay[j])
				return array[i];
		}
	}
	return -1;
}

int firstDuplicateValue(vector<int> array) {
	for(int i=0; i<array.size(); i++){
		int v=array[i]<0?-array[i]:array[i];
		if(array[v-1]<0){
			return v;
		}else{
			array[v-1]=-array[v-1];
		}
	}
	return -1;
}


