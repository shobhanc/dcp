/*
 * Given list of time taken by each task and number of workers. 
 * Each worker has to do two tasks and workers can do their tasks in parallel.
 * Find the minimun time for all workers to complete the tasks. The minimum time will be 
 * max of total time by a worker doing his tasks. Return task indexes for each worker.
 *
 * input time taken by tasks : [1,3,5,3,1,4]
 * no. of workers: 3
 *
 * output:
 * [
 *  [0,2],//tasks[0] is 1+ tasks[2] is 5 = 6
 *  [4,5],//tasks[4] is 1+tasks[5] is 4 = 5
 *  [1,3],//tasks[1] is 3+tasks[3] is 3 = 6
 * ]
 */

bool compPair(vector<int> first, vector<int> second){
   return first[0]<second[0];
}

//time O(NlogN) and space O(N)
//sort tasks in ascending order and pick a
//task from beginning and end for each worker
vector<vector<int>> taskAssignment(int k, vector<int> tasks) {
	// Write your code here.
	vector<vector<int>> v, vout;
	for(int i=0; i<tasks.size(); i++){
		v.push_back({tasks[i],i});
	}
	sort(v.begin(),v.end(),compPair);
	int j=0, b=0, e=v.size()-1;
	while(j<k){
		vout.push_back({v[b][1],v[e][1]});
		b++;
		e--;
		j++;
	}
	return vout;
}
