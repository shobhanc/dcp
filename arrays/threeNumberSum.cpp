/*
 * Given an array and a target sum. Return all possible combinations
 * of 3 numbers in the array that make up the sum and return all such
 * combinations.
 *
 * input: [12.3.1.2.-6.5.-8.6]
 * output: [[-8.2.6], [-8, 3, 5], [-6,1,5]]
 */


//time O(N^2) and space O(n)
vector<vector<int>> threeNumberSum(vector<int> array,
		int targetSum) {
	vector<vector<int>> res;
	//first sort array
	sort(array.begin(),array.end());
	for(int i=0; i<array.size(); i++){
		//take an element from array
		//scan left and right of the remaining array
		//to find other two numbers that make up sum.
		int l=i+1, r=array.size()-1;
		while(l<r){
			int sum=array[l]+array[r]+array[i];
			if(sum==targetSum){
				res.push_back({array[i],array[l],array[r]});
				//if one match found search for next
				r--;
				l++;
			}else if(sum>targetSum){
				r--;
			}else{
				l++;
			}
		}
	}
	return res;
}
