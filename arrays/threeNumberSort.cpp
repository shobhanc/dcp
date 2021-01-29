/*
 * Three Number Sort
 * Given an array [1,0,0,-1,-1,0,1,1]
 * order of three distinct integers [0,1,-1]
 *
 * output in the same order as the order array:[0,0,0,1,1,1,-1,-1]
 *
 * Do in place sort without using auxillary data structure.
 */

//Bruteforce with  auxillary array.
//O(k) space and O(Nk) time
vector<int> threeNumberSort(vector<int> array, vector<int> order) {
	// Write your code here.
	map<int,int> mp;
	for(int v:order){
		mp.insert({v,0});
	}
	for(int v:array){
		mp[v]+=1;
	}
	int idx=0;
	for(int v:order){
		int t=mp[v];
		for(int i=0; i<t; i++){
			array[idx]=v;
			idx++;
		}
	}
	return array;
}

//O(1) space and O(NK) time
int vsort(vector<int>& array, int i, int val){
	int j=i;
	for(; i<array.size(); i++){
     if(val==array[i]){
       swap(array[j],array[i]);
			 j++;
		 }
	}
	return j;
}

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  // Write your code here.
	int start=0;
	for(int i=0; i<order.size()-1 && start<array.size(); i++){
	   start= vsort(array, start, order[i]);
	}
	return array;
}

//time O(N) space O(1)
vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  // Write your code here.
	int b=0, e=array.size()-1;
	for(int i=0; i<array.size(); i++){
    if(array[i]==order[0]){
       swap(array[i],array[b]);
			 b++;
		} 
	}
	for(int i=array.size()-1; i>=0; i--){
    if(array[i]==order[2]){
       swap(array[i],array[e]);
			 e--;
		} 
	}
	return array;
}

//time O(N) and space(1)
vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  // Write your code here.
	int start=0, end=array.size()-1;
	int i=0;
	while(i<=end){
     if(array[i]==order[2]){
        swap(array[i],array[end]);
			  end--;
		 }else if(array[i]==order[0]){
        swap(array[i],array[start]);
			  start++;
			  i++;
		 }else{
		   i++;
		 }
	}
	return array;
}

