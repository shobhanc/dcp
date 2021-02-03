/*
 * Given two arrays, find the elements one from each which 
 * gives the minimum absolute difference.
 *
 * one: [-1,5,10,20,28,3]
 * two: [26,134,135,15,17]
 *
 * output:[28,26]
 */

//time O(N^2) and space O(1)
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	int mn=INT_MAX;
	int a=0, b=0;
	for(int i=0; i<arrayOne.size(); i++){
		for(int j=0; j<arrayTwo.size(); j++){
			int mnTemp = abs(arrayOne[i]-arrayTwo[j]);
			if(mn>mnTemp){
				mn=mnTemp;
				a=arrayOne[i];
				b=arrayTwo[j];
			} 
		}
	}
	return {a,b};
}

//time O(nlogn)+mlog(m) and space O(1)
vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
	//sort both arrays
	sort(arrayOne.begin(),arrayOne.end());
	sort(arrayTwo.begin(),arrayTwo.end());
	int idxOne=0;
	int idxTwo=0;
	int a=0, b=0;
	int aRes=0, bRes=0;
	int diff=0, mdiff=INT_MAX;
	while(idxOne<arrayOne.size() &&
				idxTwo<arrayTwo.size()){
		a=arrayOne[idxOne];
		b=arrayTwo[idxTwo];
		//if element in first array is greater than
		//element in second array increment second array index
		//and vise versa
		//capture the difference and keep track of the minimum
		if(a>b){
			idxTwo++;
			diff=abs(a-b);
		}else if(b>a){
			idxOne++;
			diff=abs(a-b);
		}else{
			return {a,b};
		}

		//update min diff and capture possible candidates
		if(mdiff>diff){
			mdiff=diff;
			aRes=a;
			bRes=b;
		}
	}
	return {aRes,bRes};
}
