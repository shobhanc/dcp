/*
 * Given an array find the longest peak.
 * a peak is defined as length of section of array
 * which are strictly increasing and then strictly
 * decreasing. At least 3 integers are required to 
 * form a peak.
 *
 * input:[1,2,3,3,4,0,10,6,5,-1,-3,2,3]
 *
 * forming a peak:
 * [0,10,6,5,-1,-3] whose length is 6
 */

//time O(N) and space O(1)
int longestPeak(vector<int> array) {
	// Write your code here.
	int i=1;
	int mxPeak=0;
	//start from 1 till array.size()-1
	while(i<int(array.size()-1)){
		// in array a,b,c
		// peak is formed if a<b>c
		bool peak=(array[i-1]<array[i] &&
				array[i]>array[i+1]);
		//continue till no peak is found
		if(!peak){
			i++;
			continue;
		}
		//check if its really a peak
		//start checking left side for increasing
		int l=i-2;
		while(l>=0 && array[l]<array[l+1]){
			l--;
		}
		//check if its really a peak
		//start checking right side for decreasing
		int r=i+2;
		while(r<array.size() && array[r-1]>array[r]){
			r++;
		}
		i=r;
		//find length of the peak
		mxPeak=max(mxPeak,r-l-1);
	}
	return mxPeak;
}
