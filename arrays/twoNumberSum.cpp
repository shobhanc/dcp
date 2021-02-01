/*
 * Given an unsorted array and a target sum return elements that make up the target sum from the array.
 */

//time O(nlogn) and space O(1)
//sort array and check of begin element and end element sum match target
//if less move towards end else move end towards begin.
vector<int> twoNumberSum(vector<int> array, int targetSum) {
	// Write your code here.
	sort(array.begin(),array.end());
	int b=0, e=array.size()-1;
	while(b<=e){
		int sum=array[b]+array[e];
		if(sum==targetSum){
			return {array[b],array[e]};
		}else if(sum>targetSum){
			e--;
		}else{
			b++;
		}
	}
	return {};
}

//time O(n) and space O(n)
//use a hashtable to lookup for the other number
vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	unordered_set<int> us;
	for(auto a:array){
		int diff = targetSum - a;
    if(us.find(diff)!=us.end()){
       return {a,diff};
		}
		us.insert(a);
	}
	return {};
}

//time O(N^2) and space O(1)
vector<int> twoNumberSum(vector<int> array, int targetSum) {
	for(int i=0; i<array.size(); i++){
	   for(int j=0; j<array.size(); j++){
			 if(i==j) continue;
			 if(array[i]+array[j]==targetSum){
          return {array[i],array[j]};
			 }
		 }
	}
	return {};
}

