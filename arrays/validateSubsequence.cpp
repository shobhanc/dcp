/*
 * Given a sequence A and sub sequence B. verify that the 
 * sub sequence is part of A in same order and does not
 * have to be adjacent to each other
 *
 * array [ 1,2,3,4]
 * sequence [1,3,4]
 * result is true
 */

//time O(N) and space O(1)
bool isValidSubsequence(vector<int> array, vector<int> sequence) {
	int j=0;
	for(int i=0; i<array.size(); i++){
		if(array[i]==sequence[j]){
			j++;
		}
		if(j==sequence.size()){
			break;
		}
	}
	return (j==sequence.size());
}
