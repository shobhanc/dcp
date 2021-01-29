/*
 * jobs and time to complete [5, 1, 4]
 * Total wait time 0+5+(5+1)=11
 * sort the jobs lowest first [1,5,4]
 * Total wait time 0+1+(5+1)=7
 */

//O(nlog(n) time and O(1) space
int minimumWaitingTime(vector<int> queries) {
	// Write your code here.
	sort(queries.begin(),queries.end());
	int accu=0, total=0;
	for(auto a: queries){
		total+=accu;
		accu+=a;
	}
	return total;
}

//O(nlog(n) time and O(1) space
int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
	sort(queries.begin(), queries.end());
	int total=0;
	for(int i=0; i<queries.size(); i++){
		//add as many times as the jobs waiting in queue
    total+=queries[i]*(queries.size()-1-i);
	}
	return total;
}
