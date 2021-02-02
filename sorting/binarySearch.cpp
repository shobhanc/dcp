/*
 * Given a sorted array, use binary search to see if a element is present in the array.
 */

//time O(log(N) and space O(1))
int binarySearch(vector<int> array, int target) {
	int b=0, e=array.size()-1;
	while(b<=e){
		 int m=b+(e-b)/2;
     if(array[m]>target){
        e--;
		 }else if(array[m]<target){
        b++;
		 }else{
        return m;
		 }
	}
	return -1;
}

//recursion
//time O(log(N)) and space O(log(N))
int helper(vector<int> array, int target, int begin, int end){
				if(begin>end){
								return -1;
				}
				int mid = begin+(end-begin)/2;
				if(array[mid]==target){
								return mid;
				}else if(array[mid]>target){
								return helper(array, target, begin, end-1);
				}else{
								return helper(array, target, begin+1, end);
				}
}

int binarySearch(vector<int> array, int target) {
  // Write your code here.
  return helper(array, target, 0, array.size()-1);
}
